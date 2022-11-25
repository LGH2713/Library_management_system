#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->loginTitle->setEnabled(false); // 设置标题文本框不可编辑
}

Login::~Login()
{
    delete ui;
}
