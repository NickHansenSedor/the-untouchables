#include "dialog.h"
#include "ui_dialog.h"
#include <QtSql>

#define Path_to_DB "C:\\Users\\Jamie\\Downloads\\users.db" //put DB location here
//IMPORTANT DONT FORGET TO CHANGE THIS PATH TO THE CORRECT ONE

Dialog::Dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);

    if(myDB.open()){
         ui->lblResult->setText("[+]Connected to Database.");
    }else{
         ui->lblResult->setText("[!]Database doesn't exist.");
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnClear_clicked()
{
    ui->txtPassword->setText("");
    ui->txtUser->setText("");
}

void Dialog::on_btnLogin_pressed()
{
    QString Username,Password;
    Username = ui->txtUser->text();
    Password = ui->txtPassword->text();

    if(!myDB.isOpen()){
        QMessageBox::warning(this,"Error:","No connection to server!");
        return;
    }

    QSqlQuery qry;
    if(qry.exec("SELECT *, * FROM Users WHERE Username = \'" + Username + "\' AND Password = \'" + Password + "\'")){
        if(qry.next()){
            ui->lblResult->setText("[+]Logging in...");
            this->close();
            MainWindow *myMainWindow = new MainWindow;
            myMainWindow->show();
        }else{
            ui->lblResult->setText("[!]Wrong Username or Password.");
            return;
        }
    }
}
