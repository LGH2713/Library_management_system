#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace Ui {
class UserInterface;
}

class UserInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = nullptr);
    ~UserInterface();
    void pullBookInfoList(); // 拉取数据库所有书本信息


private slots:
    void on_pullAll_clicked();

private:
    Ui::UserInterface *ui;
    QSqlDatabase *dbconn; // 数据库连接
    QSqlQueryModel *model; // 数据库模型
    QStringList *dataList;

};

#endif // USERINTERFACE_H
