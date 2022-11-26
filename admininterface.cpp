#include "admininterface.h"
#include "ui_admininterface.h"

AdminInterface::AdminInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminInterface)
{
    ui->setupUi(this);
    // 设置标题不可编辑
    ui->adminTitle->setEnabled(false);
}

AdminInterface::~AdminInterface()
{
    delete ui;
}
