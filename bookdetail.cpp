#include "bookdetail.h"
#include "ui_bookdetail.h"

BookDetail::BookDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookDetail)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;
}

BookDetail::~BookDetail()
{
    delete ui;
    delete model;
}

void BookDetail::setIsbn(QString isbn)
{
    this->isbn = isbn;
}

void BookDetail::getDetail()
{
    QString sqlStr = QString("select * from book where isbn = '%1'").arg(isbn);
    model->setQuery(sqlStr);

    QModelIndex index = model->index(0, 0);
    ui->id->setText(model->data(index).toString());
    ui->id->setEnabled(false);

    index = model->index(0, 1);
    ui->isbn->setText(model->data(index).toString());
    ui->isbn->setEnabled(false);

    index = model->index(0, 2);
    ui->inventory->setText(model->data(index).toString());
    ui->inventory->setEnabled(false);

    index = model->index(0, 3);
    ui->name->setText(model->data(index).toString());
    ui->name->setEnabled(false);

    index = model->index(0, 4);
    ui->author->setText(model->data(index).toString());
    ui->author->setEnabled(false);

    index = model->index(0, 5);
    ui->shelfLife->setText(model->data(index).toString());
    ui->shelfLife->setEnabled(false);

    index = model->index(0, 6);
    ui->price->setText(model->data(index).toString());
    ui->price->setEnabled(false);

    index = model->index(0, 7);
    ui->category->setText(model->data(index).toString());
    ui->category->setEnabled(false);

    index = model->index(0, 8);
    ui->press->setText(model->data(index).toString());
    ui->press->setEnabled(false);

    index = model->index(0, 9);
    ui->leanStatus->setText(model->data(index).toString());
    ui->leanStatus->setEnabled(false);
}
