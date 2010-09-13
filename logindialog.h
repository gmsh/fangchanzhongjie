#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QtGui/QDialog>
#include "ui_logindialog.h"
class QStringList;
class LoginDialog : public QDialog, public Ui::LoginDialog
{
    Q_OBJECT
public:
    LoginDialog(QWidget *parent = 0);
    void setLoginNames(const QStringList & list);
signals:
    void loggined(const QString & loginName, const QString & passwd);
private slots:
    void on_passwdLineEdit_textChanged();
public slots:
    void accept();
    void loginFailed();
    void loginSuccessed();
};

#endif // LOGINDIALOG_H
