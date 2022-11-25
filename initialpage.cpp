#include "initialpage.h"
#include "ui_initialpage.h"

InitialPage::InitialPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InitialPage)
{
    ui->setupUi(this);
    connect(ui->userLogin, SIGNAL(clicked(bool)), this, SLOT(featureSignal()));
    connect(ui->userRegister, SIGNAL(clicked(bool)), this, SLOT(featureSignal()));
}

InitialPage::~InitialPage()
{
    delete ui;
}

void InitialPage::featureSignal()
{
    featureName = qobject_cast<QPushButton *>(this->sender())->text();
    qDebug() << "button name = " << featureName;
}
