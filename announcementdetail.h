#ifndef ANNOUNCEMENTDETAIL_H
#define ANNOUNCEMENTDETAIL_H

#include <QDialog>

namespace Ui {
class AnnouncementDetail;
}

class AnnouncementDetail : public QDialog
{
    Q_OBJECT

public:
    explicit AnnouncementDetail(QWidget *parent = nullptr);
    ~AnnouncementDetail();

private:
    Ui::AnnouncementDetail *ui;
};

#endif // ANNOUNCEMENTDETAIL_H
