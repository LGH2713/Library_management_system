#include "logindlg.h"
#include "ui_logindlg.h"

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    connect(ui->userLogin, SIGNAL(clicked(bool)), this, SLOT(buttonSignal()));
    connect(ui->adminLogin, SIGNAL(clicked(bool)), this, SLOT(buttonSignal()));
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::buttonSignal()
{
    buttonName = qobject_cast<QPushButton *>(this->sender())->text();
}




