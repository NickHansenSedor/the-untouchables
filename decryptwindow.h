#ifndef SENDWINDOW_H
#define SENDWINDOW_H

#include <QDialog>
#include <QString>
#include <Qfile>
#include "cryptfiledevice.h"

namespace Ui {
class decryptWindow;
}

class decryptWindow : public QDialog
{
    Q_OBJECT

public:
    explicit decryptWindow(QWidget *parent = 0);
    ~decryptWindow();
    qint64 readData(char *buffer, qint64 maxlen);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::decryptWindow *ui;
    CryptFileDevice *m_cryptFileDevice = nullptr;
};

#endif // SENDWINDOW_H
