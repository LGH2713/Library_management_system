#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class AdminInterface;
}

class AdminInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminInterface(QWidget *parent = nullptr);
    ~AdminInterface();

private:
    Ui::AdminInterface *ui;

    // 数据库连接
    QSqlDatabase *dbconn;
};

#endif // ADMININTERFACE_H
