#include "uploadwindow.h"
#include "ui_uploadwindow.h"

//need to finish uploading to server as of now we only have local file encryption.
UploadWindow::UploadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UploadWindow)
{
    ui->setupUi(this);
}

UploadWindow::~UploadWindow()
{
    delete ui;
}
