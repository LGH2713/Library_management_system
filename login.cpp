#include "login.h"
#include "ui_login.h"
#include "Common.h"

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

    // 连接登录信号和槽
    connect(ui->loginBtn, SIGNAL(clicked(bool)), this, SLOT(loginSignal()));



}

Login::~Login()
{
    delete ui;
}

void Login::loginSignal()
{
    username = ui->usename->text();
    password = ui->password->text();

    Common::LoginType = ui->userRadio->isChecked() ? Type::User : Type::Librarian;
    if(username == "root")
        Common::LoginType = Type::Admin;

    btnType = qobject_cast<QPushButton *>(this->sender())->objectName();

    // ==================== test ==========================
    QString type = ui->userRadio->isChecked() ? "User" : "Admin";
    qDebug() << "username = " << username << "\n" <<
                "passworrd = " << password << "\n" <<
                "LoginType = " << type;
}

bool Login::check()
{
    return false;
}
