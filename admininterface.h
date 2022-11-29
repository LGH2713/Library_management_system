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

private:
    Ui::AdminInterface *ui;
    QSqlDatabase *dbconn; // 数据库连接
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
};

#endif // ADMININTERFACE_H
