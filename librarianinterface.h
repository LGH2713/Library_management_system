#ifndef LIBRARIANINTERFACE_H
#define LIBRARIANINTERFACE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "Common.h"
#include "bookmanagement.h"

namespace Ui {
class LibrarianInterface;
}

class LibrarianInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit LibrarianInterface(QWidget *parent = nullptr);
    ~LibrarianInterface();
    void setUserID(QString userID); // 设置用户ID

private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_editInfoBtn_clicked();

    void on_publishBtn_clicked();

    void on_bookSearchBtn_clicked();

    void on_addBookBtn_clicked();

    void on_bookInfoClear_clicked();

    void on_deleteSearchBtn_clicked();

    void on_deleteBookBtn_clicked();

private:
    Ui::LibrarianInterface *ui;
    QString stringItemList;
    QSqlDatabase *dbconn; // 数据库连接
    QSqlQueryModel *model;
    QString userID; // 用户ID
    BookManagement *bookManagement;

    void pullBookInfoList(); // 拉取数据库所有书本信息
    bool checkInput(); // 审查输入的个人信息
    void modifyUserInfo(); // 修改个人信息
    void getUserInfo(); // 获取个人信息
    void searchAndShow(QWidget *inputUI, QWidget *showUI, SearchWay way); // 查询数据并显示到UI上
    QString getPublisherName(); // 获取发布公告的图书管理员的姓名
    void publishAnnouncement(); // 发布公告
    void addNewBook(); // 添加书籍
    void clearAddInfo(); // 清除填写的添加信息
};

#endif // LIBRARIANINTERFACE_H
