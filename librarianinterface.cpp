#include "librarianinterface.h"
#include "ui_librarianinterface.h"
#include <QMessageBox>
#include <QDate>

LibrarianInterface::LibrarianInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibrarianInterface)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;

    // 设置图书管理员个人信息的ID无法修改
    ui->librarianId->setEnabled(false);

    // 设置发布公告页的信息无法编辑
    ui->publishTime->setEnabled(false);
    ui->publisherName->setEnabled(false);
}

LibrarianInterface::~LibrarianInterface()
{
    delete ui;
}

void LibrarianInterface::setUserID(QString userID)
{
    this->userID = userID;
}

void LibrarianInterface::pullBookInfoList()
{

}

bool LibrarianInterface::checkInput()
{
    return true;
}

void LibrarianInterface::modifyUserInfo()
{
    QString name = ui->librarianName->text();
    QString passwd = ui->librarianPassword->text();
    QString mail = ui->librarianMail->text();

    if(checkInput()) {
        QString sqlStr = QString("update librarian set l_name = '%1', l_password = '%2', l_mail = '%3' where l_id = %4")
                .arg(name, passwd, mail, userID);
        model->setQuery(sqlStr);
        getUserInfo();
        QMessageBox::information(this, "修改信息", "修改成功", QMessageBox::Ok);
    }
}

void LibrarianInterface::getUserInfo()
{
    QString sqlStr = QString("select * from librarian where l_id = '%1'").arg(userID);
    model->setQuery(sqlStr);
    qDebug() << "sqlStr = " << sqlStr;

    // 从数据库获取个人信息并显示到UI上
    QModelIndex index = model->index(0, 0);
    ui->librarianId->setText(model->data(index).toString());

    index = model->index(0, 1);
    ui->librarianName->setText(model->data(index).toString());

    index = model->index(0, 2);
    ui->librarianMail->setText(model->data(index).toString());

    index = model->index(0, 3);
    ui->librarianPassword->setText(model->data(index).toString());
}

void LibrarianInterface::searchAndShow(QWidget *item, QWidget *showUI, SearchWay way)
{

}

QString LibrarianInterface::getPublisherName()
{
    QString sqlStr = QString("select l_name from librarian where l_id = '%1'").arg(userID);
    model->setQuery(sqlStr);
    QModelIndex index = model->index(0, 0);
    qDebug() << "model->data(index).toString() = " << model->data(index).toString();
    return model->data(index).toString();
}




void LibrarianInterface::on_tabWidget_tabBarClicked(int index)
{
    // 获取个人信息
    getUserInfo();
    // 设置发布公告基本信息
    ui->publishTime->setText(QDate::currentDate().toString("yyyy-MM-dd"));
    ui->publisherName->setText(getPublisherName());
}


void LibrarianInterface::on_editInfoBtn_clicked()
{
    modifyUserInfo();
}

