#include "mainwindow.h"
#include "login.h"
#include "initialpage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("图书管理系统");

    Login login;
    InitialPage initPage;


    // 初始页 -> 登录页
    if(initPage.exec() == QDialog::Accepted) {
        login.show();
    }
    else
        return 0;


    // 登录页 -> 主页
    if(login.exec() == QDialog::Accepted) {
        w.show();
        return a.exec();
    }
    else
        return 0;
    // w.show();
    // return a.exec();
}
