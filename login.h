#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QButtonGroup>
#include <QSqlDatabase>
#include "userinterface.h"
#include "librarianinterface.h"
#include "admininterface.h"


namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool check();

    QString btnType; // 按钮类型
    QString username; // 用户名
    QString password; // 密码
    QButtonGroup *groupRadio; // 角色单选框


public slots:
    // 登录按钮槽函数
    void loginSignal();

private:
    Ui::Login *ui;
    QSqlDatabase *dbconn;// 数据库连接
    UserInterface *userInterface;
    LibrarianInterface *librarianInterface;
    AdminInterface *adminInterface;
};

#endif // LOGIN_H
