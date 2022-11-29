#include "userinterface.h"
#include "ui_userinterface.h"

UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;

    // 设置列表不可编辑,只能选择一行,表头自适应
    ui->bookList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->bookList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->bookList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView *bookInfoHeaderView = ui->bookList->horizontalHeader();
    bookInfoHeaderView->setSectionResizeMode(QHeaderView::Stretch);

    // 用户ID不可编辑
    ui->userId->setEnabled(false);

    pullBookInfoList();
}

UserInterface::~UserInterface()
{
    delete ui;
}

void UserInterface::setUserID(QString userID)
{
    this->userID = userID;
}

void UserInterface::pullBookInfoList()
{
    QString sqlStr = QString("select %1, %2, %3, %4, %5 from book").arg("isbn", "b_name", "author", "category", "press");
    model->setQuery(sqlStr);

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

bool UserInterface::checkInput()
{
    return false;
}

void UserInterface::modifyUserInfo()
{

}

void UserInterface::getUserInfo()
{
    QString sqlStr = QString("select u_id, u_name, u_password, u_mail, u_sex from user where u_id = '%1'").arg(userID);
    model->setQuery(sqlStr);

    QModelIndex index = model->index(0, 0);
    ui->userId->setText(model->data(index).toString());

    index = model->index(0, 1);
    ui->userName->setText(model->data(index).toString());

    index = model->index(0, 2);
    ui->userPassword->setText(model->data(index).toString());

    index = model->index(0, 3);
    ui->userMail->setText(model->data(index).toString());

    index = model->index(0, 4);
    QString sex = model->data(index).toString();
    ui->maleRadio->setCheckable(sex == "male");
}

void UserInterface::on_tabWidget_tabBarClicked(int index)
{
    getUserInfo();
}

