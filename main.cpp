#include "mainwindow.h"
#include "login.h"
#include "initialpage.h"
#include "register.h"
#include "userinterface.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.setWindowTitle("图书管理系统");

    Login login;
    InitialPage initPage;
    Register reg;
    UserInterface userInterface;

    userInterface.setWindowTitle("图书管理系统");

    // UI 控制流程
    if(initPage.exec() == QDialog::Accepted) {
        if(initPage.btnType == "userLogin")// 初始页 -> 登录页
        {
            login.show();
            // 登录页 -> 主页
            if(login.exec() == QDialog::Accepted && login.btnType == "loginBtn") {
                userInterface.show();
                return a.exec();
            }
        }
        else if(initPage.btnType == "userRegister") // 初始页 -> 注册页
        {
            reg.show();
            // 注册页 -> 登录页
            if(reg.exec() == QDialog::Accepted && reg.btnType == "registerBtn") {
                login.show();
                // 登录页 -> 主页
                if(login.exec() == QDialog::Accepted && login.btnType == "loginBtn") {
                    userInterface.show();
                    return a.exec();
                }
            }
            else
                return 0;
        }
    }
}
