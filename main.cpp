#include "mainwindow.h"
#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("图书管理系统");

    Login login;


    if(login.exec() == QDialog::Accepted) {
        w.show();
        return a.exec();
    }
    else
        return 0;
    // w.show();
    // return a.exec();
}
