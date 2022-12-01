#include "bookdetail.h"
#include "ui_bookdetail.h"
#include <QMessageBox>

BookDetail::BookDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookDetail)
{
    ui->setupUi(this);
    ui->editBookInfoBtn->setVisible(false); // 隐藏 编辑 按钮
    ui->intoEditMode->setVisible(false); // 隐藏 进入编辑模式 按钮
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

void BookDetail::getDetail(bool isEdit)
{
    QString sqlStr = QString("select * from book where isbn = '%1'").arg(isbn);
    model->setQuery(sqlStr);
    ui->id->setEnabled(false);

    // 设置信息是否可编辑
        setEditable(isEdit);


    QModelIndex index = model->index(0, 0);
    ui->id->setText(model->data(index).toString());


    index = model->index(0, 1);
    ui->isbn->setText(model->data(index).toString());


    index = model->index(0, 2);
    ui->inventory->setText(model->data(index).toString());


    index = model->index(0, 3);
    ui->name->setText(model->data(index).toString());


    index = model->index(0, 4);
    ui->author->setText(model->data(index).toString());


    index = model->index(0, 5);
    ui->shelfLife->setText(model->data(index).toString());


    index = model->index(0, 6);
    ui->price->setText(model->data(index).toString());


    index = model->index(0, 7);
    ui->category->setText(model->data(index).toString());


    index = model->index(0, 8);
    ui->press->setText(model->data(index).toString());


    index = model->index(0, 9);
    ui->leanStatus->setText(model->data(index).toString());

}

void BookDetail::showEditMode()
{
    ui->editBookInfoBtn->setVisible(true);
    ui->intoEditMode->setVisible(true);
}

void BookDetail::setEditable(bool isEdit)
{
    ui->isbn->setEnabled(isEdit);
    ui->inventory->setEnabled(isEdit);
    ui->name->setEnabled(isEdit);
    ui->author->setEnabled(isEdit);
    ui->shelfLife->setEnabled(isEdit);
    ui->price->setEnabled(isEdit);
    ui->category->setEnabled(isEdit);
    ui->press->setEnabled(isEdit);
    ui->leanStatus->setEnabled(isEdit);
}

void BookDetail::on_intoEditMode_clicked()
{
    setEditable(true);
}


void BookDetail::on_editBookInfoBtn_clicked()
{
    QString isbn = ui->isbn->text();
    QString inventory = ui->inventory->text();
    QString name = ui->name->text();
    QString author = ui->author->text();
    QString shelf_life  = ui->shelfLife->text();
    QString price =  ui->price->text();
    QString loanStatus = ui->leanStatus->text();
    QString category = ui->category->text();

    QString sqlStr = QString("update book set isbn = '%1', inventory = %2, "
                             "b_name = '%3', author = '%4', "
                             "shelf_life = '%5', price = %6, "
                             "category = '%6', press = '%7',  loan_status = '%8'  where isbn = '%9'")
            .arg(isbn, inventory, name, author, shelf_life, price,  category, loanStatus, this->isbn);

    model->setQuery(sqlStr);
    QMessageBox::information(this, "Message", "修改成功");
    getDetail(false);
}

