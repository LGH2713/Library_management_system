#include "userinterface.h"
#include "ui_userinterface.h"
#include <QMessageBox>
#include "utils.h"

UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;

    ui->maleRadio->setChecked(true);
    ui->bookNameRadio->setChecked(true);

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
    delete model;
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
    return true;
}

void UserInterface::modifyUserInfo()
{
    QString name = ui->userName->text();
    QString passwd = ui->userPassword->text();
    QString mail = ui->userMail->text();
    QString sex = ui->maleRadio->isChecked() ? "mele" : "female";

    if(checkInput()) {
        QString sqlStr = QString("update user set u_name = '%1', u_password = '%2', u_mail = '%3', u_sex = '%4' where u_id = '%5'")
                .arg(name, passwd, mail, sex, userID);
        model->setQuery(sqlStr);
        getUserInfo();
        QMessageBox::information(this, "修改信息", "修改成功", QMessageBox::Ok);
    }
}

void UserInterface::getUserInfo()
{
    QString sqlStr = QString("select u_id, u_name, u_password, u_mail, u_sex from user where u_id = '%1'").arg(userID);
    model->setQuery(sqlStr);

    // 从数据库获取个人信息并显示到UI上
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
    ui->maleRadio->setChecked(sex == "male");
}

void UserInterface::searchAndShow()
{
    bookManagement = new BookManagement;

    // 清空列表
    while(ui->bookList->rowCount() > 0)
        ui->bookList->removeRow(0);

    qDebug() << ui->bookSearchInput->text();

        if(ui->bookSearchInput->text() != nullptr) {
            if(ui->bookNameRadio->isChecked())
                bookManagement->searchBook(ui->bookSearchInput->text(), SearchWay::ByName);
            else if(ui->authorRadio->isChecked())
                bookManagement->searchBook(ui->bookSearchInput->text(), SearchWay::ByAuthor);
            else if(ui->isbnRadio->isChecked())
                bookManagement->searchBook(ui->bookSearchInput->text(), SearchWay::ByBookISBN);


            // 显示搜索出来的信息
            for(int i = 0; i < bookManagement->bookList.length(); i++) {
                qDebug() << "bookManagement->bookList.at(i)->category = " << bookManagement->bookList.at(i)->category;
                ui->bookList->insertRow(ui->bookList->rowCount());
                ui->bookList->setItem(i, 0, new QTableWidgetItem(bookManagement->bookList.at(i)->ISBN));
                ui->bookList->setItem(i, 1, new QTableWidgetItem(bookManagement->bookList.at(i)->bookName));
                ui->bookList->setItem(i, 2, new QTableWidgetItem(bookManagement->bookList.at(i)->author));
                ui->bookList->setItem(i, 3, new QTableWidgetItem(switchCategoryEnumToQString(bookManagement->bookList.at(i)->category)));
                ui->bookList->setItem(i, 4, new QTableWidgetItem(bookManagement->bookList.at(i)->press));
            }

        }
}

void UserInterface::on_tabWidget_tabBarClicked(int index)
{
    getUserInfo();
}


void UserInterface::on_infoEditBtn_clicked()
{
    modifyUserInfo();
}


void UserInterface::on_bookSearchBtn_clicked()
{
    searchAndShow();
}

