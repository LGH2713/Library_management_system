#ifndef BOOKMANAGEMENT_H
#define BOOKMANAGEMENT_H
#include "book.h"


class BookManagement: public Book
{
public:
    BookManagement();
    ~BookManagement();
    void searchBook(QString keyword, enum SearchWay way); // 查询书籍

    QList<Book*> bookList;

private:
    QSqlQueryModel *model;
    void insertData(QString sqlStr);
};

#endif // BOOKMANAGEMENT_H
