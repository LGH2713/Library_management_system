#ifndef ANNOUNCEMENTDETAIL_H
#define ANNOUNCEMENTDETAIL_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class AnnouncementDetail;
}

class AnnouncementDetail : public QDialog
{
    Q_OBJECT

public:
    explicit AnnouncementDetail(QWidget *parent = nullptr);
    ~AnnouncementDetail();
    void setData(QString id);

private:
    Ui::AnnouncementDetail *ui;
    QSqlQueryModel *model;
};

#endif // ANNOUNCEMENTDETAIL_H
