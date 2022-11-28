#include "database.h"
#include "login.h"
#include "initialpage.h"
#include "register.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Database db;

    InitialPage initPage; // 初始页
    Register reg; // 注册页
    reg.setDbconn(&db.dbconn);

    Login login;// 登录页
    login.setDbconn(&db.dbconn);

    // UI 控制流程
    if(initPage.exec() == QDialog::Accepted) {
        if(initPage.btnType == "userLogin")// 初始页 -> 登录页
        {
            login.show();
        }
        else if(initPage.btnType == "userRegister") // 初始页 -> 注册页
        {
            reg.show();
            // 注册页 -> 登录页
            if(reg.exec() == QDialog::Accepted && reg.btnType == "registerBtn") {
                login.show();
            }
            else
                return 0;
        }
    }
    return a.exec();
}
