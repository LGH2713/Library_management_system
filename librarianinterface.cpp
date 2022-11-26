#include "librarianinterface.h"
#include "ui_librarianinterface.h"

LibrarianInterface::LibrarianInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibrarianInterface)
{
    ui->setupUi(this);
    // 设置标题不可编辑
    ui->librarianTitle->setEnabled(false);
}

LibrarianInterface::~LibrarianInterface()
{
    delete ui;
}
