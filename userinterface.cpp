#include "userinterface.h"
#include "ui_userinterface.h"

UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    dataList = new QStringList;
    model = new QSqlQueryModel;

    // 设置列表不可编辑,只能选择一行
    ui->bookList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->bookList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->bookList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QHeaderView *headerView = ui->bookList->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);
}

UserInterface::~UserInterface()
{
    delete ui;
    delete[] dataList;
}

void UserInterface::pullBookInfoList()
{
    QString sqlStr = QString("select %1, %2, %3, %4, %5 from book").arg("isbn", "b_name", "author", "category", "press");
    model->setQuery(sqlStr);
    QModelIndex item_index = model->index(0, 0);
    qDebug() << model->data(item_index).toString();

    // 填充数据
    for(int i = 0; i < model->rowCount(); i++) {
        ui->bookList->insertRow(ui->bookList->rowCount());
        for(int j = 0; j < model->columnCount(); j++) {
            QModelIndex item_index = model->index(i, j);
            ui->bookList->setItem(i, j, new QTableWidgetItem(model->data(item_index).toString()));
            ui->bookList->item(i, j)->setTextAlignment(Qt::AlignCenter); // 设置文字居中
        }
    }

}

void UserInterface::on_pullAll_clicked()
{
    pullBookInfoList();
}

