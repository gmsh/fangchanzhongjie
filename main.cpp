#include <QtSql>
#include <QtGui/QApplication>
#include <QtCore/QStringList>
#include <QtCore/QTextCodec>
#include "logindialog.h"
#include "dbconnect.h"
#include "yuangongguanlidialog.h"
#include "canshuguanlidialog.h"
#include "quanxianzushezhidialog.h"
#include "quanxianzuguanlidialog.h"
#include "fangyuandialog.h"
#include "keyuandialog.h"
#include "mainwindow.h"
#include "chengjiaoqianyuedialog.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    DBConnect dbcon;
    LoginDialog * loginDialog = new LoginDialog(0, dbcon.loginNames());
    QObject::connect(loginDialog, SIGNAL(loggined(QString,QString)), &dbcon, SLOT(login(QString,QString)));
    QObject::connect(&dbcon, SIGNAL(loginSuccessed()), loginDialog, SLOT(loginSuccessed()));
    QObject::connect(&dbcon, SIGNAL(loginFailed()), loginDialog, SLOT(loginFailed()));
    loginDialog->exec();
    if(!loginDialog->logginSuccess)
        exit(0);

    MainWindow mainWindow(&dbcon, new QString(loginDialog->loginNameComboBox->currentText()));

    mainWindow.show();


    return app.exec();
}
