#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class UserInterface;
}

class UserInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = nullptr);
    ~UserInterface();
    void setDbconn(QSqlDatabase *dbconn); // 设置数据库连接

private:
    Ui::UserInterface *ui;
    QSqlDatabase *dbconn; // 数据库连接
};

#endif // USERINTERFACE_H
