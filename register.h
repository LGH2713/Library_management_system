#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QButtonGroup>
#include <QSqlQueryModel>

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

private slots:
    void on_userRadio_clicked();

    void on_librarianRadio_clicked();

private:
    Ui::Register *ui;
    QSqlQueryModel *model; // 数据库连接
    bool inputCheck(); // 输入数据检测
};

#endif // REGISTER_H
