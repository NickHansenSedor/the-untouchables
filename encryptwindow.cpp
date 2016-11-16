#include "encryptwindow.h"
#include "ui_encryptwindow.h"
#include "cryptfiledevice.h"
#include "setkey.h"
#include <QFile>
#include <QDialog>
#include <QString>
#include <QMessageBox>



encryptWindow::encryptWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::encryptWindow)
{
    ui->setupUi(this);
}

encryptWindow::~encryptWindow()
{
    delete ui;
}

void encryptWindow::on_buttonBox_accepted()
{
   QString srcFilepath,encFilepath;
   srcFilepath = ui->src_filepath->text();
   encFilepath = ui->enc_filepath->text();
   if(ui->lineEdit->text()== ui->lineEdit_2->text())
       key = ui->lineEdit->text();
   else
       QMessageBox::warning(this,"Error","Your too passwords dont match");

   QFile plainFile(srcFilepath);
   QFile encryptedFile(qApp->applicationDirPath()+encFilepath +".enc");
   //qint64 len = plainFile.size();

   if (!plainFile.open(QIODevice::ReadOnly))
       {
           QMessageBox::warning(this,"Error","Cant open source file!!");
           return;
       }

       if (!encryptedFile.open(QIODevice::ReadOnly))
       {
           plainFile.close();
           QMessageBox::warning(this,"Error","Cant open new ecrypted file!!");
           return;
       }
       QByteArray key1 = key.toUtf8();
       QString fileS = qApp->applicationDirPath()+"/.enc";
       QFile felDev(fileS);

       QFile::copy(srcFilepath, encFilepath);
       m_cryptFileDevice = new CryptFileDevice;
       m_cryptFileDevice->setFileDevice(&encryptedFile);
       m_cryptFileDevice->setFileName(encFilepath);
       m_cryptFileDevice->setPassword(key1);
       m_cryptFileDevice->setSalt(key1);
if(m_cryptFileDevice->isEncrypted()== false){
    QMessageBox::warning(this,"Error","File is not encypted");
        return;
}
else{
       plainFile.close();
       encryptedFile.close();
       return;
}
}

//random stuff disregard
//       m_cryptFileDevice->insertHeader();
//       m_cryptFileDevice->initCipher();
       //QDataStream dataStream(&src_Filepath);
//       QDataStream encStream(&encFilepath);
//       int size= qrand()% 256;
//       QByteArray data_enc(size,' ');
       //QByteArray data_src(size, ' ');
       //m_cryptFileDevice->encrypt(, len);
//      m_cryptFileDevice->setHeader();

