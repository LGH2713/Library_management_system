#include "bookmanagement.h"
#include <QMessageBox>

enum Category switchCategoryQStringToEnum(QString category) {
    if(category == "Aerospace")
        return  Category::Aerospace;
    else if(category == "Argiculture")
        return Category::Argiculture;
    else if(category == "Art")
        return  Category::Art ;
    else if(category == "BiologicalScience")
        return Category::BiologicalScience;
    else if(category == "Comprehensive")
        return Category::Comprehensive;
    else if(category == "Economic")
        return  Category::Economic;
    else if(category == "Education")
        return  Category::Education;
    else if(category == "HistoryAndGeography")
        return  Category::HistoryAndGeography;
    else if(category == "IndustrialTechnology")
        return Category::IndustrialTechnology;
    else if(category == "LanguageAndWriting")
        return Category::LanguageAndWriting;
    else if(category == "Literature")
        return Category::Literature;
    else if(category == "MathematicalAndChemistry")
        return Category::MathematicalAndChemistry;
    else if(category == "Military")
        return Category::Military;
    else if(category == "Philosophy")
        return Category::Philosophy;
    else if(category == "ScienceFiction")
        return Category::ScienceFiction;
    else if(category == "SocialScience")
        return  Category::SocialScience;
    else if(category == "PoliticalAndLaw")
        return Category::PoliticalAndLaw;
    else if(category == "Transportation")
        return Category::Transportation;
    else if(category == "MedicineAndHealth")
        return Category::MedicineAndHealth;
    else if(category == "EnvironmentScience")
        return Category::EnvironmentScience;
    else
        return Category::Comprehensive;
}

BookManagement::BookManagement()
{
    model = new QSqlQueryModel;
}

BookManagement::~BookManagement()
{
    delete model;
}

void BookManagement::searchBook(QString keyword, enum SearchWay way)
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
                book->category = switchCategoryQStringToEnum(data);
            case 8:
                book->press = data;
                break;
            case 9:
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
