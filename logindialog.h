#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QtGui/QDialog>
#include "ui_logindialog.h"
class QStringList;
class LoginDialog : public QDialog, public Ui::LoginDialog
{
    Q_OBJECT
public:
    LoginDialog(QWidget *parent = 0, QStringList * list = 0);
signals:
    void loggined(const QString & loginName, const QString & passwd);
private slots:
    void on_passwdLineEdit_textChanged();
public slots:
    void accept();
    void loginFailed();
    void loginSuccessed();
private:
    QStringList * nameList;
};

#endif // LOGINDIALOG_H
