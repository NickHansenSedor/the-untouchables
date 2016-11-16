#include "decryptwindow.h"
#include "ui_decryptwindow.h"
#include "cryptfiledevice.h"
#include <QFile>
#include <QFile>
#include <QDialog>
#include <QString>
#include <QMessageBox>

decryptWindow::decryptWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::decryptWindow)
{
    ui->setupUi(this);
}

decryptWindow::~decryptWindow()
{
    delete ui;
}
/*qint64 decryptWindow:: readData(char *buffer, qint64 maxlen){
    qint64 result = m_cryptFileDevice->read(buffer, maxlen);
}
*/
void decryptWindow::on_pushButton_2_clicked()
{
    ui->file_path->setText("");
    ui->password->setText("");
}

void decryptWindow::on_pushButton_clicked()
{
    QString file_path, pass;
    file_path = ui->file_path->text();
    pass = ui->password->text();
    const QString filePath = file_path;
    QFile plainFile(qApp->applicationDirPath()+"/test.decrypted");
    QFile encFile(filePath);
    if (!plainFile.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this,"Error","Cant open source file!!");
            return;
        }

        if (!encFile.open(QIODevice::ReadOnly))
        {
            plainFile.close();
            QMessageBox::warning(this,"Error","Cant open new ecrypted file!!");
            return;
        }
    //qint64 len = encFile.size();
    QFile::copy(file_path,qApp->applicationDirPath()+"/test.decrypted" );
    QByteArray passw = pass.toUtf8();
    m_cryptFileDevice = new CryptFileDevice;
    m_cryptFileDevice->setFileDevice(&plainFile);
    m_cryptFileDevice->setFileName("test.decrypted");
    m_cryptFileDevice->setPassword(passw);
    m_cryptFileDevice->setSalt(passw);
    m_cryptFileDevice->readAll();
  plainFile.close();
  encFile.close();
return;
 }
