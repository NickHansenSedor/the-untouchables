#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encryptwindow.h"
#include "sendwindow.h"
#include "uploadwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->addItem("heyoh!");
    ui->listWidget->addItem("Line");
    ui->listWidget->addItem("Line");
    ui->listWidget->addItem("Line");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_encBtn_clicked()
{
    encryptWindow encWin;
    encWin.setModal(true);
    encWin.exec();
    //encryptWindow = new encryptWindow(this);
    //encryptWindow->show.();
}

void MainWindow::on_sendBtn_clicked()
{
    SendWindow sendWin;
    sendWin.setModal(true);
    sendWin.exec();
    //SendWindow = new SendWindow(this);
    //SendWindow->show.();
}

void MainWindow::on_logoutBtn_clicked()
{
    auto childList = findChildren<QMainWindow*>();
    for (auto child : childList)
    {
        child->close();
    }
    this->close();
    Dialog *myLogin = new Dialog;
    myLogin->show();
}

void MainWindow::on_upload_btn_clicked()
{
    UploadWindow upload_file;
    upload_file.setModal(true);
    upload_file.exec();

}
