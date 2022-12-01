#include "register.h"
#include "ui_register.h"
#include "Common.h"
#include <QSqlQueryModel>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->registerTitle->setEnabled(false);
    model = new QSqlQueryModel;

    buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->maleRadio);
    buttonGroup->addButton(ui->femaleRadio);
    ui->maleRadio->setChecked(true);
    ui->userRadio->setChecked(true);

    connect(ui->registerBtn, SIGNAL(clicked(bool)), this, SLOT(registerSignal()));
}

Register::~Register()
{
    delete ui;
}

void Register::registerSignal()
{
    // 获取输入信息
    username = ui->username->text();
    password = ui->password->text();
    mail = ui->mail->text();
    sex = ui->maleRadio->isChecked() ? Sex::male : Sex::female;
    QString sexType = sex == Sex::male ? "male" : "female";
    btnType = qobject_cast<QPushButton *>(this->sender())->objectName();
    Common::RegisterType = ui->userRadio->isChecked() ? Type::User : Type::Librarian;

    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlStr;
    // 根据不同的注册类型创建sql语句
    if(Common::RegisterType == Type::User && inputCheck())
        sqlStr = QString("insert into user (u_name, u_sex, u_password, u_mail) values "
                         "('%1', '%2', '%3', '%4')").arg(username, sexType, password, mail);
    else if(Common::RegisterType == Type::Librarian && inputCheck())
        sqlStr = QString("insert into librarian (l_name, l_password, l_mail) values "
                         "('%1', '%2', '%3')").arg(username, password, mail);

    qDebug() << sqlStr;

    // 执行sql
    model->setQuery(sqlStr);
}

// 检查输入信息
bool Register::inputCheck()
{
    if(username == nullptr || password == nullptr || mail == nullptr)
        return false;
    return true;

}

// 显示性别单选框
void Register::on_userRadio_clicked()
{
    for(int i = 0; i < ui->sexBox->count(); ++i) {
        QWidget *w = ui->sexBox->itemAt(i)->widget();
        if(w != nullptr)
            w->setVisible(true);
    }
}

// 隐藏性别单选框
void Register::on_librarianRadio_clicked()
{
    for(int i = 0; i < ui->sexBox->count(); ++i) {
        QWidget *w = ui->sexBox->itemAt(i)->widget();
        if(w != nullptr)
            w->setVisible(false);
    }
}

