#include "librarianinterface.h"
#include "ui_librarianinterface.h"

LibrarianInterface::LibrarianInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibrarianInterface)
{
    ui->setupUi(this);
    QListWidgetItem *listItem = new QListWidgetItem("hello");
    ui->bookInfoList->addItem(listItem);
}

LibrarianInterface::~LibrarianInterface()
{
    delete ui;
}

void LibrarianInterface::createItem()
{

}
