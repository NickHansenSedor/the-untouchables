#ifndef ENCRYPTWINDOW_H
#define ENCRYPTWINDOW_H

#include <QDialog>
#include <QString>
#include <Qfile>
#include "cryptfiledevice.h"

namespace Ui {
class encryptWindow;
}

class encryptWindow : public QDialog
{
    Q_OBJECT

public:
    explicit encryptWindow(QWidget *parent = 0);

    ~encryptWindow();

private slots:
    void on_buttonBox_accepted();

private:
   bool encryptFile(const QString &pathToEnc, const QString &pathToPlain);
    Ui::encryptWindow *ui;
    CryptFileDevice *m_cryptFileDevice = nullptr;
    QString key;
};

#endif // ENCRYPTWINDOW_H
