#include "librarianinterface.h"
#include "ui_librarianinterface.h"
#include <QMessageBox>
#include <QDate>
#include "bookmanagement.h"

namespace LibrarianUtils {
QString switchCategoryEnumToQString(enum Category category) {
    qDebug() <<  category;
    switch(category) {
    case Category::Aerospace :
        return "Aerospace";
    case Category::Argiculture:
        return "Argiculture";
    case Category::Art :
        return "Art";
    case Category::BiologicalScience:
        return "BiologicalScience";
    case Category::Comprehensive:
        return "Comprehensive";
    case Category::Economic:
        return "Economic";
    case Category::Education:
        return "Education";
    case Category::HistoryAndGeography:
        return "HistoryAndGeography";
    case Category::IndustrialTechnology:
        return "IndustrialTechnology";
    case Category::LanguageAndWriting:
        return "LanguageAndWriting";
    case Category::Literature:
        return "Literature";
    case Category::MathematicalAndChemistry:
        return "MathematicalAndChemistry";
    case Category::Military:
        return "Military";
    case Category::Philosophy:
        return "Philosophy";
    case Category::ScienceFiction:
        return "ScienceFiction";
    case Category::SocialScience:
        return "SocialScience";
    case Category::PoliticalAndLaw:
        return "PoliticalAndLaw";
    case Category::Transportation:
        return "Transportation";
    case Category::MedicineAndHealth:
        return "MedicineAndHealth";
    case Category::EnvironmentScience:
        return "EnvironmentScience";
    default:
        return "";
    };
}

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
}


LibrarianInterface::LibrarianInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibrarianInterface)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;

    ui->bookNameRadio->setChecked(true);

    // 设置列表不可编辑,只能选择一行,表头自适应
    // 搜索列表
    ui->bookList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->bookList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->bookList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView *bookInfoHeaderView = ui->bookList->horizontalHeader();
    bookInfoHeaderView->setSectionResizeMode(QHeaderView::Stretch);

    ui->deleteBookList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->deleteBookList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->deleteBookList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    bookInfoHeaderView = ui->deleteBookList->horizontalHeader();
    bookInfoHeaderView->setSectionResizeMode(QHeaderView::Stretch);


    // 设置图书管理员个人信息的ID无法修改
    ui->librarianId->setEnabled(false);

    // 设置发布公告页的信息无法编辑
    ui->publishTime->setEnabled(false);
    ui->publisherName->setEnabled(false);

    // 拉取图书信息
    pullBookInfoList();
}

LibrarianInterface::~LibrarianInterface()
{
    delete ui;
}

void LibrarianInterface::setUserID(QString userID)
{
    this->userID = userID;
}

void LibrarianInterface::pullBookInfoList()
{
    QString sqlStr = QString("select %1, %2, %3, %4, %5 from book").arg("isbn", "b_name", "author", "category", "press");
    model->setQuery(sqlStr);

    // 填充数据
    for(int i = 0; i < model->rowCount(); i++) {
        ui->bookList->insertRow(ui->bookList->rowCount());
        for(int j = 0; j < model->columnCount(); j++) {
            QModelIndex item_index = model->index(i, j);
            ui->bookList->setItem(i, j, new QTableWidgetItem(model->data(item_index).toString()));
            ui->bookList->item(i, j)->setTextAlignment(Qt::AlignCenter); // 设置文字居中
        }
    }
}

bool LibrarianInterface::checkInput()
{
    return true;
}

void LibrarianInterface::modifyUserInfo()
{
    QString name = ui->librarianName->text();
    QString passwd = ui->librarianPassword->text();
    QString mail = ui->librarianMail->text();

    if(checkInput()) {
        QString sqlStr = QString("update librarian set l_name = '%1', l_password = '%2', l_mail = '%3' where l_id = %4")
                .arg(name, passwd, mail, userID);
        model->setQuery(sqlStr);
        getUserInfo();
        QMessageBox::information(this, "修改信息", "修改成功", QMessageBox::Ok);
    }
}

void LibrarianInterface::getUserInfo()
{
    QString sqlStr = QString("select * from librarian where l_id = '%1'").arg(userID);
    model->setQuery(sqlStr);

    // 从数据库获取个人信息并显示到UI上
    QModelIndex index = model->index(0, 0);
    ui->librarianId->setText(model->data(index).toString());

    index = model->index(0, 1);
    ui->librarianName->setText(model->data(index).toString());

    index = model->index(0, 2);
    ui->librarianMail->setText(model->data(index).toString());

    index = model->index(0, 3);
    ui->librarianPassword->setText(model->data(index).toString());
}

void LibrarianInterface::searchAndShow(QWidget *inputUI, QWidget *showUI, SearchWay way)
{
    bookManagement = new BookManagement;
    auto show = static_cast<QTableWidget*>(showUI);
    auto inputText = qobject_cast<QLineEdit*>(inputUI)->text();

    // 清空列表
    while(show->rowCount() > 0)
        show->removeRow(0);

    if(inputText != nullptr) {
        bookManagement->searchBook(inputText, way);

        // 显示搜索出来的信息
        for(int i = 0; i < bookManagement->bookList.length(); i++) {
            QString temp = LibrarianUtils::switchCategoryEnumToQString(bookManagement->bookList.at(i)->category);
            show->insertRow(show->rowCount());
            show->setItem(i, 0, new QTableWidgetItem(bookManagement->bookList.at(i)->ISBN));
            show->setItem(i, 1, new QTableWidgetItem(bookManagement->bookList.at(i)->bookName));
            show->setItem(i, 2, new QTableWidgetItem(bookManagement->bookList.at(i)->author));
            show->setItem(i, 3, new QTableWidgetItem(temp));
            show->setItem(i, 4, new QTableWidgetItem(bookManagement->bookList.at(i)->press));

            // 设置文字居中
            for(int j = 0; j < ui->bookList->columnCount(); j++) {
                show->item(i, j)->setTextAlignment(Qt::AlignCenter);
            }
        }

    }
}



// 获取公告发布者姓名
QString LibrarianInterface::getPublisherName()
{
    QString sqlStr = QString("select l_name from librarian where l_id = '%1'").arg(userID);
    model->setQuery(sqlStr);
    QModelIndex index = model->index(0, 0);
    return model->data(index).toString();
}

void LibrarianInterface::publishAnnouncement()
{
    QString date = ui->publishTime->text();
    QString content = ui->announcementContent->toPlainText();

    QString sqlStr = QString("insert into announcement (a_time, a_p_id, content) values ('%1', '%2', '%3')")
            .arg(date, userID, content);

    if(content != nullptr) {
        model->setQuery(sqlStr);
        QMessageBox::information(this, "message", "发布成功");
        ui->announcementContent->clear();
    }
    else
        QMessageBox::critical(this, "Error", "公告内容不得为空");
}

void LibrarianInterface::addNewBook()
{
    QString isbn = ui->addISBN->text();
    QString bookName = ui->addBookName->text();
    QString author = ui->addAuthor->text() != nullptr ? ui->addAuthor->text() : "佚名";
    QString shelfLife = ui->dateEdit->date().toString("yy-MM-dd");
    QString price = ui->addPrice->text();
    QString category = ui->addCategory->currentText().split("（")[0];
    QString press = ui->addPress->text();
    QString inventory = ui->addInventory->text();

    QString sqlStr = QString("insert into book (isbn, inventory, b_name, author, shelf_life, price, category, press) values ('%1', %2, '%3', '%4', '%5', %6, '%7', '%8')")
            .arg(isbn, inventory, bookName, author, shelfLife, price, category, press);

    qDebug() << sqlStr;

    model->setQuery(sqlStr);
    QMessageBox::information(this, "Message", "添加成功");
    clearAddInfo();
}

void LibrarianInterface::clearAddInfo()
{
    ui->addISBN->clear();
    ui->addBookName->clear();
    ui->addAuthor->clear();
    ui->addPrice->clear();
    ui->addPress->clear();
    ui->addInventory->clear();
    ui->addCategory->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
}




void LibrarianInterface::on_tabWidget_tabBarClicked(int index)
{
    // 获取个人信息
    getUserInfo();
    // 设置发布公告基本信息
    ui->publishTime->setText(QDate::currentDate().toString("yyyy-MM-dd"));
    ui->publisherName->setText(getPublisherName());

    pullBookInfoList();
}


void LibrarianInterface::on_editInfoBtn_clicked()
{
    modifyUserInfo();
}


void LibrarianInterface::on_publishBtn_clicked()
{
    publishAnnouncement();
}


void LibrarianInterface::on_bookSearchBtn_clicked()
{
    if(ui->bookNameRadio->isChecked())
        searchAndShow(ui->bookSearchInput, ui->bookList, SearchWay::ByName);
    else if(ui->authorRadio->isChecked())
        searchAndShow(ui->bookSearchInput, ui->bookList, SearchWay::ByAuthor);
    else if(ui->isbnRadio->isChecked())
        searchAndShow(ui->bookSearchInput, ui->bookList, SearchWay::ByBookISBN);
}


void LibrarianInterface::on_addBookBtn_clicked()
{
    addNewBook();
}


void LibrarianInterface::on_bookInfoClear_clicked()
{
    clearAddInfo();
}


void LibrarianInterface::on_deleteSearchBtn_clicked()
{
    searchAndShow(ui->deleteSearchInput, ui->deleteBookList, SearchWay::ByBookISBN);
}

