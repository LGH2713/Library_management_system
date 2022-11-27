#include "librarianinterface.h"
#include "ui_librarianinterface.h"

LibrarianInterface::LibrarianInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibrarianInterface)
{
    ui->setupUi(this);
}

LibrarianInterface::~LibrarianInterface()
{
    delete ui;
}

void LibrarianInterface::createItem()
{
    QListWidgetItem *listItem = new QListWidgetItem("hello");
    listItem->
}
