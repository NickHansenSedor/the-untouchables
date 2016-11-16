#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>

#include "MainWindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_btnClear_clicked();

    void on_btnLogin_pressed();

private:
    Ui::Dialog *ui;

    QSqlDatabase myDB;
};

#endif // DIALOG_H
