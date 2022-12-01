#include "userinterface.h"
#include "ui_userinterface.h"
#include <QMessageBox>
#include <QDate>
#include "bookmanagement.h"

namespace UserUtils {
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


UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;
    bookDetail = new BookDetail;

    ui->maleRadio->setChecked(true);
    ui->bookNameRadio->setChecked(true);

    // 设置列表不可编辑,只能选择一行,表头自适应
    // 搜索列表
    ui->bookList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->bookList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->bookList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView *bookInfoHeaderView = ui->bookList->horizontalHeader();
    bookInfoHeaderView->setSectionResizeMode(QHeaderView::Stretch);

    // 预约列表
    ui->orderList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->orderList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->orderList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    bookInfoHeaderView = ui->orderList->horizontalHeader();
    bookInfoHeaderView->setSectionResizeMode(QHeaderView::Stretch);

    // 公告列表
    ui->announcementList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->announcementList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->announcementList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    bookInfoHeaderView = ui->announcementList->horizontalHeader();
    bookInfoHeaderView->setSectionResizeMode(QHeaderView::Stretch);

    // 用户ID不可编辑
    ui->userId->setEnabled(false);

    // 拉取图书信息
    pullBookInfoList();
    // 拉取公告信息
    getAnnouncementList();
}

UserInterface::~UserInterface()
{
    delete ui;
    delete model;
    delete bookDetail;
}

void UserInterface::setUserID(QString userID)
{
    this->userID = userID;
}

void UserInterface::pullBookInfoList()
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

bool UserInterface::checkInput()
{
    return true;
}

void UserInterface::modifyUserInfo()
{
    QString name = ui->userName->text();
    QString passwd = ui->userPassword->text();
    QString mail = ui->userMail->text();
    QString sex = ui->maleRadio->isChecked() ? "mele" : "female";

    if(checkInput()) {
        QString sqlStr = QString("update user set u_name = '%1', u_password = '%2', u_mail = '%3', u_sex = '%4' where u_id = '%5'")
                .arg(name, passwd, mail, sex, userID);
        model->setQuery(sqlStr);
        getUserInfo();
        QMessageBox::information(this, "修改信息", "修改成功", QMessageBox::Ok);
    }
}

void UserInterface::getUserInfo()
{
    QString sqlStr = QString("select u_id, u_name, u_password, u_mail, u_sex from user where u_id = '%1'").arg(userID);
    model->setQuery(sqlStr);

    // 从数据库获取个人信息并显示到UI上
    QModelIndex index = model->index(0, 0);
    ui->userId->setText(model->data(index).toString());

    index = model->index(0, 1);
    ui->userName->setText(model->data(index).toString());

    index = model->index(0, 2);
    ui->userPassword->setText(model->data(index).toString());

    index = model->index(0, 3);
    ui->userMail->setText(model->data(index).toString());

    index = model->index(0, 4);
    QString sex = model->data(index).toString();
    ui->maleRadio->setChecked(sex == "male");
}

void UserInterface::searchAndShow(QWidget *inputUI, QWidget *showUI, SearchWay way)
{
    bookManagement = new BookManagement;
    auto show = static_cast<QTableWidget*>(showUI);
    auto inputText = qobject_cast<QLineEdit*>(inputUI)->text();

    // 清空列表
    qDebug() << "ui->bookList->rowCount() = " << show->rowCount();
    while(show->rowCount() > 0)
        show->removeRow(0);

    qDebug() << "start3";

    if(inputText != nullptr) {
        bookManagement->searchBook(inputText, way);

        // 显示搜索出来的信息
        for(int i = 0; i < bookManagement->bookList.length(); i++) {
            QString temp = UserUtils::switchCategoryEnumToQString(bookManagement->bookList.at(i)->category);
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

void UserInterface::getAnnouncementList()
{
    QString sqlStr = QString("select a.a_id, a.a_time, b.l_name from announcement a inner join librarian b on a.a_p_id = b.l_id");
    model->setQuery(sqlStr);

    for(int i = 0; i < model->rowCount(); i++) {
        ui->announcementList->insertRow(ui->announcementList->rowCount());
        for(int j = 0; j < model->columnCount(); j++) {
            QModelIndex index = model->index(i, j);
            ui->announcementList->setItem(i, j, new QTableWidgetItem(model->data(index).toString()));
        }
    }
}

void UserInterface::showDetails(QString isbn)
{
    bookDetail->setWindowTitle("书本详情");
    bookDetail->setIsbn(isbn);
    bookDetail->getDetail(false);
    bookDetail->show();

}

void UserInterface::borrowBook(QString isbn)
{
    QModelIndex index;
    QString start_time = QDate::currentDate().toString("yyyy-MM-dd");
    QString deadline = QDate::currentDate().addDays(30).toString("yyyy-MM-dd");

    QString sqlBookStr = QString("select isbn, b_name from  book where isbn = '%1'").arg(isbn);
    model->setQuery(sqlBookStr);
    index = model->index(0,  0);
    QString b_isbn = model->data(index).toString();
    index = model->index(0, 1);
    QString b_name = model->data(index).toString();

    QString sqlUserName = QString("select u_name from user where u_id = '%1'").arg(userID);
    model->setQuery(sqlUserName);
    index = model->index(0, 0);
    QString userName = model->data(index).toString();

    QString sqlBorrowBook = QString("insert into borrow_books (bb_isbn, bb_name, bb_book_name, bb_start_time, bb_deadline) values "
                                    "('%1', '%2',  '%3', '%4', '%5')").arg(b_isbn, userName, b_name, start_time, deadline);

    qDebug() << sqlBorrowBook;

    model->setQuery(sqlBorrowBook);
    QMessageBox::information(this, "Message", "已发送借书请求");
}

void UserInterface::on_tabWidget_tabBarClicked(int index)
{
    getUserInfo();
}

void UserInterface::on_infoEditBtn_clicked()
{
    modifyUserInfo();
}

void UserInterface::on_bookSearchBtn_clicked()
{
    if(ui->bookNameRadio->isChecked())
        searchAndShow(ui->bookSearchInput, ui->bookList, SearchWay::ByName);
    else if(ui->authorRadio->isChecked())
        searchAndShow(ui->bookSearchInput, ui->bookList, SearchWay::ByAuthor);
    else if(ui->isbnRadio->isChecked())
        searchAndShow(ui->bookSearchInput, ui->bookList, SearchWay::ByBookISBN);
}


void UserInterface::on_orderSearchBtn_clicked()
{
    searchAndShow(ui->orderSearch, ui->orderList, SearchWay::ByBookISBN);
}


void UserInterface::on_bookList_clicked(const QModelIndex &index)
{
    int currentRow = ui->bookList->selectionModel()->currentIndex().row();
    QString isbn = ui->bookList->item(currentRow, 0)->text();
    showDetails(isbn);
}


void UserInterface::on_pushButton_2_clicked()
{
    auto  item  = ui->orderList->selectedItems();
    if(!item.isEmpty())
        borrowBook(item.at(0)->text());
    else
        QMessageBox::critical(this, "Error", "请选择书籍");
}

