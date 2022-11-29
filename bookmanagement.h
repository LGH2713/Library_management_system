#ifndef BOOKMANAGEMENT_H
#define BOOKMANAGEMENT_H
#include "book.h"

class BookManagement: public Book
{
public:
    BookManagement();

    QVector<Book*> bookList;
};

#endif // BOOKMANAGEMENT_H
