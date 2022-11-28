#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QButtonGroup>
#include <QSqlDatabase>

namespace Ui {
class Register;
}

enum Sex {
    male,
    female,
};

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    void setDbconn(QSqlDatabase *dbconn); // 设置数据库连接

    QString btnType;
    QString username;
    QString password;
    QString mail;
    Sex sex;

    // 单选框
    QButtonGroup *buttonGroup;


public slots:
    void registerSignal();

private:
    Ui::Register *ui;
    QSqlDatabase *dbconn; // 数据库连接
    bool inputCheck(); // 输入数据检测
};

#endif // REGISTER_H
