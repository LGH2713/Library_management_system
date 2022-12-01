#ifndef BOOKDETAIL_H
#define BOOKDETAIL_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class BookDetail;
}

class BookDetail : public QDialog
{
    Q_OBJECT

public:
    explicit BookDetail(QWidget *parent = nullptr);
    ~BookDetail();
    void setIsbn(QString isbn);
    void getDetail(); // 从数据库获取书本详情

private:
    Ui::BookDetail *ui;
    QString isbn;
    QSqlQueryModel *model;
};

#endif // BOOKDETAIL_H
