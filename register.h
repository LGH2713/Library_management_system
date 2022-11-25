#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class Register;
}

enum Sex {
    male,
    female,
};

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

    QString btnType;
    QString username;
    QString password;
    QString mail;
    Sex sex;

    // 单选框
    QButtonGroup *buttonGroup;


public slots:
    void registerSignal();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
