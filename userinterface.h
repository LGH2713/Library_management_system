#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "bookmanagement.h"
#include "bookdetail.h"
#include "announcementdetail.h"

namespace Ui {
class UserInterface;
}

class UserInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = nullptr);
    ~UserInterface();
    void setUserID(QString userID); // 设置用户ID

private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_infoEditBtn_clicked();

    void on_bookSearchBtn_clicked();

    void on_orderSearchBtn_clicked();

    void on_bookList_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_announcementList_clicked(const QModelIndex &index);

private:
    Ui::UserInterface *ui;
    QSqlQueryModel *model; // 数据库模型
    QString userID; // 用户ID
    BookManagement *bookManagement;
    BookDetail *bookDetail;
    AnnouncementDetail *ad; // 公告详情界面

    void pullBookInfoList();                                            // 拉取数据库所有书本信息
    bool checkInput();                                                  // 审查输入的个人信息
    void modifyUserInfo();                                              // 修改个人信息
    void getUserInfo();                                                 // 获取个人信息
    void searchAndShow(QWidget *inputUI, QWidget *showUI, SearchWay way);  // 查询数据并显示到UI上
    void getAnnouncementList();                                         // 获取公告列表
    void showDetails(QString isbn);                                     // 展示书本详情
    void borrowBook(QString isbn);                                      // 借阅图书
};

#endif // USERINTERFACE_H
