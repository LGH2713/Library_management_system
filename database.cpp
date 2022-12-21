#include "database.h"
#include <QFile>
#include <QDir>

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

    qDebug() << "链接库：";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver,drivers)
        qDebug() << driver;
}

Database::~Database()
{
    dbconn.close();
}

int Database::init()
{
    int iRet = 0;
    QFile sqlFile(QString(QDir::currentPath() + "/sql/librarian_system.sql"));
    qDebug() << "QDir::currentPath() = " <<  QDir::currentPath() ;
    if(!sqlFile.exists()) {
        qDebug() << "文件不存在 ";
        return -1;
    }
    if(!sqlFile.open(QIODevice::ReadOnly  | QIODevice::Text)) {
        return -1;
    }

    QTextStream in(&sqlFile);
    QString sql_str_file_data = in.readAll();
    QSqlQuery qsql("LibraryManagementSystem");
    QStringList qstr_list_sql = sql_str_file_data.split(";");
    for(int i = 0; i < qstr_list_sql.size() - 1; i++) {
        QString sql_str_part = qstr_list_sql.at(i).toUtf8();
        qDebug() << "sql = " << sql_str_part;
        bool sql_result = qsql.exec(sql_str_part);
        if(!sql_result) {
            QSqlError sql_error = qsql.lastError();
            iRet = -1;
            break;
        }
    }

    return iRet;
}
