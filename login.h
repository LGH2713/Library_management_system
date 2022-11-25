#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QButtonGroup>


namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    // 单选框
    QButtonGroup *groupRadio;


public slots:
    // 登录按钮槽函数
    void loginSignal();

private:
    Ui::Login *ui;

    // 检验登录信息
    bool check();
};

#endif // LOGIN_H
