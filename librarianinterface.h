#ifndef LIBRARIANINTERFACE_H
#define LIBRARIANINTERFACE_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class LibrarianInterface;
}

class LibrarianInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit LibrarianInterface(QWidget *parent = nullptr);
    ~LibrarianInterface();

private:
    Ui::LibrarianInterface *ui;
    QString stringItemList;
    QSqlDatabase *dbconn; // 数据库连接
};

#endif // LIBRARIANINTERFACE_H
