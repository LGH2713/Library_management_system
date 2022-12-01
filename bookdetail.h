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
    void getDetail(bool isEdit); // 从数据库获取书本详情
    void showEditMode(); // 显示编辑模式

private slots:
    void on_intoEditMode_clicked();

    void on_editBookInfoBtn_clicked();

private:
    Ui::BookDetail *ui;
    QString isbn;
    QSqlQueryModel *model;

    void setEditable(bool isEdit); // 设置详情能否编辑
};

#endif // BOOKDETAIL_H
