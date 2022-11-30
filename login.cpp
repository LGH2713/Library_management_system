#include "login.h"
#include "ui_login.h"
#include "Common.h"
#include <QSqlQueryModel>
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    // 设置标题文本框不可编辑
    ui->loginTitle->setEnabled(false);

    // 设置单选框
    groupRadio = new QButtonGroup(this);
    groupRadio->addButton(ui->userRadio);
    groupRadio->addButton(ui->adminRadio);
    ui->userRadio->setChecked(true);

    userInterface = new UserInterface;
    userInterface->setWindowTitle("用户界面");

    librarianInterface = new LibrarianInterface;
    librarianInterface->setWindowTitle("图书管理员界面");

    adminInterface = new AdminInterface;
    adminInterface->setWindowTitle("超级用户界面");

    // 连接登录信号和槽
    connect(ui->loginBtn, SIGNAL(clicked(bool)), this, SLOT(loginSignal()));
}

Login::~Login()
{
    delete ui;
    delete userInterface;
    delete librarianInterface;
    delete adminInterface;
}

bool Login::check()
{
    ui->loginBtn->blockSignals(true);
    username = ui->usename->text();
    password = ui->password->text();


    Common::LoginType = ui->userRadio->isChecked() ? Type::User : Type::Librarian;
    if(username == "root") {
        Common::LoginType = Type::Admin;
        QSqlQueryModel *model_name = new QSqlQueryModel;
        model_name->setQuery(QString("select a_password from admin"));
        QModelIndex index_passwd = model_name->index(0, 0);
        if(password == model_name->data(index_passwd).toString()) {
            return true;
        }
    }

    return false;
}

void Login::loginSignal()
{
    ui->loginBtn->blockSignals(true);
    username = ui->usename->text();
    password = ui->password->text();

    QSqlQueryModel *model = new QSqlQueryModel;
    Common::LoginType = ui->userRadio->isChecked() ? Type::User : Type::Librarian;

    // 超级管理员登陆
    if(username == "root") {
        Common::LoginType = Type::Admin;
        model->setQuery(QString("select a_password from admin"));
        QModelIndex index_passwd = model->index(0, 0);
        if(password == model->data(index_passwd).toString()) {
            adminInterface->show();
        } else {
            QMessageBox::critical(this, tr("登录失败"), tr("密码输入错误！"), QMessageBox::Cancel);
        }
    } else {
        // 普通用户登录
        if(Common::LoginType == Type::User) {
            model->setQuery(QString("select u_password, u_id from user where u_name = '%1'").arg(username));
            QModelIndex index_passwd = model->index(0, 0);
            QString resultPasswd = model->data(index_passwd).toString();
            qDebug() << "password = " << password << " " << "resultPasswd = " << resultPasswd;
            if(password == resultPasswd && resultPasswd != nullptr) {
                userInterface->show();
                QModelIndex index_id = model->index(0, 1);
                userInterface->setUserID(model->data(index_id).toString());
            } else {
                QMessageBox::critical(this, tr("登录失败"), tr("用户名或密码输入错误！"), QMessageBox::Cancel);
            }
        }
        // 图书管理员登录
        else {
            model->setQuery(QString("select l_password, l_id from librarian where l_name = '%1'").arg(username));
            QModelIndex index_passwd = model->index(0, 0);
            QString resultPasswd = model->data(index_passwd).toString();
            if(password == resultPasswd && resultPasswd != nullptr) {
                librarianInterface->show();
                QModelIndex index_id = model->index(0, 1);
                librarianInterface->setUserID(model->data(index_id).toString());
            }else {
                QMessageBox::critical(this, tr("登录失败"), tr("用户名或密码输入错误！"), QMessageBox::Cancel);
            }
        }
    }
}





