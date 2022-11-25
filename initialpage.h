#ifndef INITIALPAGE_H
#define INITIALPAGE_H
#include <QDialog>

namespace Ui {
class InitialPage;
}

class InitialPage : public QDialog
{
    Q_OBJECT

public:
    explicit InitialPage(QWidget *parent = nullptr);
    ~InitialPage();

    QString btnType;

public slots:
    void featureSignal();

private:
    Ui::InitialPage *ui;
};

#endif // INITIALPAGE_H
