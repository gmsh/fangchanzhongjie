#include <QtSql>
#include <QtGui/QApplication>
#include <QtCore/QStringList>
#include <QtCore/QTextCodec>
#include "logindialog.h"
#include "dbconnect.h"
#include "yuangongguanlidialog.h"
#include "canshuguanlidialog.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    DBConnect dbcon;
    LoginDialog * loginDialog = new LoginDialog(0, dbcon.loginNames());
    QObject::connect(loginDialog, SIGNAL(loggined(QString,QString)), &dbcon, SLOT(login(QString,QString)));
    QObject::connect(&dbcon, SIGNAL(loginSuccessed()), loginDialog, SLOT(loginSuccessed()));
    QObject::connect(&dbcon, SIGNAL(loginFailed()), loginDialog, SLOT(loginFailed()));
    if(loginDialog->exec() == LoginDialog::Accepted){
        //
    }
    /*YuangongGuanliDialog yuangongGuanliDialog(0);
    yuangongGuanliDialog.setTableModel(dbcon.yuangongModel);
    yuangongGuanliDialog.show();*/

    /*CanshuGuanliDialog canshuGuanliDialog(0, &dbcon);
    canshuGuanliDialog.show();*/


    return app.exec();
}

bool connectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("h6n4t2i5shz$");
    return db.open();
}
