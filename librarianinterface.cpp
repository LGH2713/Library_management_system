#include "librarianinterface.h"
#include "ui_librarianinterface.h"

LibrarianInterface::LibrarianInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibrarianInterface)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;

    ui->librarianId->setEnabled(false);
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




void LibrarianInterface::on_tabWidget_tabBarClicked(int index)
{
    getUserInfo();
}

