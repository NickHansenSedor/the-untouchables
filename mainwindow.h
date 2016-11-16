#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "encryptwindow.h"
#include "sendwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_encBtn_clicked();

    void on_sendBtn_clicked();

    void on_logoutBtn_clicked();

    void on_upload_btn_clicked();

private:
    Ui::MainWindow *ui;
    encryptWindow *encWin;
    SendWindow *sendWin;
};

#endif // MAINWINDOW_H
