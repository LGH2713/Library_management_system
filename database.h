#ifndef DATABASE_H
#define DATABASE_H
#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

class Database
{
public:
    Database();
    ~Database();

    QSqlDatabase dbconn;

private:
    QString hostName;
    QString dbName;
    QString userName;
    QString password;
    int port;
};

#endif // DATABASE_H
