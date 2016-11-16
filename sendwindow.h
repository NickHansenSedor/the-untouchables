#ifndef SENDWINDOW_H
#define SENDWINDOW_H

#include <QDialog>

namespace Ui {
class SendWindow;
}

class SendWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SendWindow(QWidget *parent = 0);
    ~SendWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::SendWindow *ui;
};

#endif // SENDWINDOW_H
