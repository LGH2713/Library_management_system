#include "mainwindow.h"
#include "logindlg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("图书管理系统");

    LoginDlg dlg;

    if(dlg.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else
        return 0;
    // w.show();
    // return a.exec();
}
