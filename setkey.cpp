#include "setkey.h"
#include "ui_setkey.h"
#include <QMessageBox>

setKey::setKey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setKey)
{
    ui->setupUi(this);
}

setKey::~setKey()
{
    delete ui;
}

void setKey::on_buttonBox_rejected()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}


void setKey::on_buttonBox_accepted()
{
    QString key;
    if(ui->lineEdit->text()== ui->lineEdit_2->text())
        key = ui->lineEdit->text();
    else
        QMessageBox::warning(this,"Error","Your too passwords dont match");
}
