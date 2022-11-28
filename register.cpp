#include "register.h"
#include "ui_register.h"
#include <QSqlQueryModel>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->registerTitle->setEnabled(false);

    buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->maleRadio);
    buttonGroup->addButton(ui->femaleRadio);
    ui->maleRadio->setChecked(true);

    connect(ui->registerBtn, SIGNAL(clicked(bool)), this, SLOT(registerSignal()));
}

Register::~Register()
{
    delete ui;
}

void Register::setDbconn(QSqlDatabase *dbconn)
{
    this->dbconn = dbconn;
}

void Register::registerSignal()
{
    username = ui->username->text();
    password = ui->password->text();
    mail = ui->mail->text();
    sex = ui->maleRadio->isChecked() ? Sex::male : Sex::female;
    btnType = qobject_cast<QPushButton *>(this->sender())->objectName();

//    QSqlQueryModel *model = new QSqlQueryModel;
//    QString sqlStr;
//    IF()
//    model->setQuery();
}
