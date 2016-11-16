#ifndef SETKEY_H
#define SETKEY_H

#include <QDialog>

namespace Ui {
class setKey;
}

class setKey : public QDialog
{
    Q_OBJECT

public:
    explicit setKey(QWidget *parent = 0);
    ~setKey();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::setKey *ui;
};

#endif // SETKEY_H
