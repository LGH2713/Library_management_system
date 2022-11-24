#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hostName = "localhost";                     // 主机名
    dbName = "LibraryManagementSystem";         // 数据库名称
    userName = "root";                          // 用户名
    password = "admin";                         // 密码
    port = 3306;                                // 端口号

    dbconn = QSqlDatabase::addDatabase("QMYSQL");
    dbconn.setHostName(hostName);
    dbconn.setDatabaseName(dbName);
    dbconn.setUserName(userName);
    dbconn.setPassword(password);
    dbconn.setPort(port);

    qDebug("database open status: %d\n", dbconn.open());

    QSqlError error = dbconn.lastError();
    qDebug() << error.text();

    dbconn.close();

    qDebug() << "链接库：";

    QStringList drivers = QSqlDatabase::drivers();

    foreach(QString driver,drivers)

        qDebug() << driver;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

