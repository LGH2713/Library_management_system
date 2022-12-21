#include "announcementdetail.h"
#include "ui_announcementdetail.h"

AnnouncementDetail::AnnouncementDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnnouncementDetail)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;

    ui->time->setEnabled(false);
    ui->content->setEnabled(false);
    ui->publisher->setEnabled(false);
}

AnnouncementDetail::~AnnouncementDetail()
{
    delete ui;
}

void AnnouncementDetail::setData(QString id)
{
    QString sqlStr = QString("select a.a_time, a.content, b.l_name "
                             "from announcement as a inner  join librarian as b  "
                             "where a.a_p_id =  b.l_id "
                             "and a.a_id = %1").arg(id);
    model->setQuery(sqlStr);
    QModelIndex index = model->index(0, 0);
    ui->time->setText(model->data(index).toString());
    index = model->index(0, 1);
    ui->content->setText(model->data(index).toString());
    index = model->index(0, 2);
    ui->publisher->setText(model->data(index).toString());
}
