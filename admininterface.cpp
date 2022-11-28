#include "admininterface.h"
#include "ui_admininterface.h"

AdminInterface::AdminInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminInterface)
{
    ui->setupUi(this);
}

AdminInterface::~AdminInterface()
{
    delete ui;
}

void AdminInterface::setDbconn(QSqlDatabase *dbconn)
{
    this->dbconn = dbconn;
}
