#include "bookmanagement.h"
#include "Common.h"
#include <QMessageBox>

BookManagement::BookManagement()
{
    model = new QSqlQueryModel;
}

BookManagement::~BookManagement()
{
    delete model;
}

void BookManagement::searchBook(QString keyword, SearchWay way)
{
    switch(way) {
    case SearchWay::ByName: {
        QString sqlStr = QString("select * from book where b_name = '%1'").arg(keyword);
        insertData(sqlStr);
        break;
    }
    case SearchWay::ByAuthor: {
         QString sqlStr = QString("select * from book where author = '%1'").arg(keyword);
        insertData(sqlStr);
        break;
    }
    case SearchWay::ByBookISBN: {
        QString sqlStr = QString("select * from book where isbn = '%1'").arg(keyword);
        insertData(sqlStr);
        break;
    }
    default: {
        qDebug() << "into default";
        break;
    }

    }

}

void BookManagement::insertData(QString sqlStr)
{
    model->setQuery(sqlStr);

    for(int i = 0; i < model->rowCount(); i++) {
        Book *book = new Book();
        for(int j = 0; j < model->columnCount(); j++) {
            QModelIndex index = model->index(i, j);
            QString data = model->data(index).toString();
            switch(j) {
            case 0:
                book->id =data;
                break;
            case 1:
                book->ISBN = data;
                break;
            case 2:
                book->inventory = data.toInt();
                break;
            case 3:
                book->bookName = data;
                break;
            case 4:
                book->author = data;
                break;
            case 5:
                book->shelfLife = data;
                break;
            case 6:
                book->price = data.toDouble();
                break;
            case 7:
                book->press = data;
                break;
            case 8:
                book->loanStatus = data == "OnLean" ? LeanStatus::OnLean :
                                                      data == "NotOnLean" ? LeanStatus::NotOnLead : LeanStatus::Ordered;
                break;
            default:
                qDebug() << "default";
                break;
            }
        }
        bookList.push_back(book);
    }

}
