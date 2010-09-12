#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QtGui/QDialog>
#include "ui_logindialog.h"

class LoginDialog : public QDialog, public Ui::LoginDialog
{
    Q_OBJECT
public:
    LoginDialog(QWidget *parent = 0);
private slots:
    void on_passwdLineEdit_textChanged();
};

#endif // LOGINDIALOG_H
