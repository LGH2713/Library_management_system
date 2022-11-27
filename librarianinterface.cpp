#include "librarianinterface.h"
#include "ui_librarianinterface.h"

LibrarianInterface::LibrarianInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibrarianInterface)
{
    ui->setupUi(this);
//    QStringList *itemInfo = new QStringList();
//    itemInfo->append("b1145145656\t\t百年孤独\t\t马尔克斯");
//    itemInfo->append("b1145145656\t\t三体\t\t刘慈欣");
//    ui->bookInfoList->addItems(*itemInfo);

}

LibrarianInterface::~LibrarianInterface()
{
    delete ui;
}


