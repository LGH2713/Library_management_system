#include "announcementdetail.h"
#include "ui_announcementdetail.h"

AnnouncementDetail::AnnouncementDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnnouncementDetail)
{
    ui->setupUi(this);
}

AnnouncementDetail::~AnnouncementDetail()
{
    delete ui;
}
