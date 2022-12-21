#ifndef LIBRARIANINTERFACE_H
#define LIBRARIANINTERFACE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "Common.h"
#include "bookmanagement.h"
#include "bookdetail.h"

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

    void on_bookList_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_returnUserIDSearchBtn_clicked();

    void on_returnBookBtn_clicked();

private:
    Ui::LibrarianInterface *ui;
    QString stringItemList;
    QSqlQueryModel *model;
    QString userID; // 用户ID
    BookManagement *bookManagement;
    BookDetail *bookDetail;
    int requestRowIndex; // 请求列表当前选中行

    void pullBookInfoList();                                                // 拉取数据库所有书本信息
    bool checkInput();                                                      // 审查输入的个人信息
    void modifyUserInfo();                                                  // 修改个人信息
    void getUserInfo();                                                     // 获取个人信息
    void searchAndShow(QWidget *inputUI, QWidget *showUI, SearchWay way);   // 查询数据并显示到UI上
    QString getPublisherName();                                             // 获取发布公告的图书管理员的姓名
    void publishAnnouncement();                                             // 发布公告
    void addNewBook();                                                      // 添加书籍
    void clearAddInfo();                                                    // 清除填写的添加信息
    void showDetails(QString isbn);                                         // 展示书本详情
    void getRequestList();                                                  // 获取借书请求列表
    void confirmRequest(QString isbn);                                      // 通过请求
    void getReturnBookList();                                               // 获取还书列表
    void returnBook(QString isbn);                                          // 还书
};

#endif // LIBRARIANINTERFACE_H
