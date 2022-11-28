#include "userinterface.h"
#include "ui_userinterface.h"

UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    dataList = new QStringList;
    model = new QSqlQueryModel;
}

UserInterface::~UserInterface()
{
    delete ui;
    delete[] dataList;
}

void UserInterface::pullBookInfoList()
{
    qDebug() << "start";
    qDebug() << "end";
    model->setQuery(QString("select * from book"));
    QModelIndex item_index = model->index(0, 0);
    qDebug() << model->data(item_index).toString();

    for(int i = 0; i < model->rowCount(); i++) {
        QString item = "";
        for(int j = 0; j < model->columnCount(); j++) {
            QModelIndex item_index = model->index(i, j);
            item += model->data(item_index).toString() + "\t\t";
        }
        qDebug() << item;
        dataList->append(item);
    }



     ui->bookList->addItems(*dataList);
}

void UserInterface::on_pullAll_clicked()
{
    pullBookInfoList();
}

