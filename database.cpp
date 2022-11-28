#include "database.h"

Database::Database()
{
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
    dbconn.close();

    qDebug() << "链接库：";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver,drivers)
        qDebug() << driver;
}
