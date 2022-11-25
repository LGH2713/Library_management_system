#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include "Common.h"

class Book
{
public:
    Book();
    bool getLoanStatus();

private:
    QString id;             // 编号
    QString ISBN;           // ISBN号
    unsigned int inventory; // 库存量
    QString bookName;       // 书名
    QString author;         // 作者名
    QString shelfLife;      // 上架时间
    double price;           // 价格
    Category category;      // 类别
    QString press;          // 出版社
    bool loanStatus;        // 出借状态
};

#endif // BOOK_H
