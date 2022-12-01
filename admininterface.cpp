#include "admininterface.h"
#include "ui_admininterface.h"
#include <QMessageBox>

AdminInterface::AdminInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminInterface)
{
    ui->setupUi(this);

    model = new QSqlQueryModel;

    // 设置用户列表自适应表头
    ui->userList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->userList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->userList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView *userHeaderView = ui->userList->horizontalHeader();
    userHeaderView->setSectionResizeMode(QHeaderView::Stretch);

    // 设置图书管理员列表自适应表头
    ui->librarianList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->librarianList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->librarianList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView *librarianHeaderView = ui->librarianList->horizontalHeader();
    librarianHeaderView->setSectionResizeMode(QHeaderView::Stretch);

    // 设置旧密码框不可输入
    ui->oldPasswd->setEnabled(false);

    getInfo();
}

AdminInterface::~AdminInterface()
{
    delete ui;
    delete model;
}

void AdminInterface::getInfo()
{
    getAllUser();
    getAllLibrarian();
    getOldPasswd();
}

void AdminInterface::getAllUser()
{
    while(ui->userList->rowCount() > 0)
        ui->userList->removeRow(0);
    QString sqlStr = QString("select u_id, u_name, u_sex, u_password, u_mail from user");

    qDebug() << "user start";
    model->setQuery(sqlStr);
    qDebug() << "user end";

    // 填充数据
    for(int i = 0; i < model->rowCount(); i++) {
        ui->userList->insertRow(ui->userList->rowCount());
        for(int j = 0; j < model->columnCount(); j++) {
            QModelIndex item_index = model->index(i, j);
            ui->userList->setItem(i, j, new QTableWidgetItem(model->data(item_index).toString()));
            ui->userList->item(i, j)->setTextAlignment(Qt::AlignCenter); // 设置文字居中
        }
    }
}

void AdminInterface::getAllLibrarian()
{
    while(ui->librarianList->rowCount() > 0)
        ui->librarianList->removeRow(0);

    QString sqlStr = QString("select l_id, l_name, l_mail, l_password from librarian");
    model->setQuery(sqlStr);

    // 填充数据
    for(int i = 0; i < model->rowCount(); i++) {
        ui->librarianList->insertRow(ui->librarianList->rowCount());
        for(int j = 0; j < model->columnCount(); j++) {
            QModelIndex item_index = model->index(i, j);
            ui->librarianList->setItem(i, j, new QTableWidgetItem(model->data(item_index).toString()));
            ui->librarianList->item(i, j)->setTextAlignment(Qt::AlignCenter); // 设置文字距中
        }
    }
}

void AdminInterface::getOldPasswd()
{
    QString sqlStr = QString("select a_password from admin where a_name = 'root'");
    model->setQuery(sqlStr);
    QModelIndex item_index = model->index(0, 0);

    ui->oldPasswd->setText(model->data(item_index).toString()); // 设置旧密码
}

// 修改密码
void AdminInterface::modifyAdminPasswd()
{
    qDebug() << ui->newPasswd->text();
    QString sqlStr = QString("update admin set a_password = '%1' where a_name = '%2'").arg(ui->newPasswd->text(), "root");
    model->setQuery(sqlStr);
    getOldPasswd();
}

void AdminInterface::cancelUser(QString userID)
{
    QString sqlStr = QString("delete from user where u_id = '1'").arg(userID);
    model->setQuery(sqlStr);
    getAllUser();
    QMessageBox::information(this, "Message", "注销成功");
}

void AdminInterface::cancelLibrarian(QString librarianID)
{
    QString sqlStr = QString("delete from librarian where l_id = '1'").arg(librarianID);
    model->setQuery(sqlStr);
    getAllLibrarian();
    QMessageBox::information(this, "Message", "注销成功");
}

void AdminInterface::on_confirm_clicked()
{
    modifyAdminPasswd();
    QMessageBox::information(this, "密码修改", "修改成功", QMessageBox::Ok);
}


void AdminInterface::on_cancelUserBtn_clicked()
{
    auto item = ui->userList->selectedItems();
    if(!item.isEmpty())
        cancelUser(item.at(0)->text());
    else
        QMessageBox::critical(this, "Error", "未选中行");
}


void AdminInterface::on_cancelLibrarianBtn_clicked()
{
    auto item = ui->librarianList->selectedItems();
    if(!item.isEmpty())
        cancelLibrarian(item.at(0)->text());
    else
        QMessageBox::critical(this, "Error", "未选中行");
}

