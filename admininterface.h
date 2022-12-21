#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace Ui {
class AdminInterface;
}

class AdminInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminInterface(QWidget *parent = nullptr);
    ~AdminInterface();

private slots:
    void on_confirm_clicked();

    void on_cancelUserBtn_clicked();

    void on_cancelLibrarianBtn_clicked();

private:
    Ui::AdminInterface *ui;
    QSqlQueryModel *model; // 数据库模型
    // 获取超级级管理员界面所需信息
    void getInfo();
    // 获取所有普通用户
    void getAllUser();
    // 获取所有图书管理员
    void getAllLibrarian();
    // 获取旧密码
    void getOldPasswd();
    // 修改超级管理员密码
    void modifyAdminPasswd();
    // 注销普通用户
    void cancelUser(QString userID);
    // 注销图书管理员
    void cancelLibrarian(QString librarianID);
};

#endif // ADMININTERFACE_H
