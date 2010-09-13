#include <QtSql>
#include <QtGui/QApplication>
#include <QtCore/QStringList>
#include <QtCore/QTextCodec>
#include "logindialog.h"
#include "dbconnect.h"
bool connectDB();

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    LoginDialog * loginDialog = new LoginDialog();
    QStringList loginNames;
    loginNames << "admin" << "user1" << "user2";
    loginDialog->setLoginNames(loginNames);
    DBConnect dbcon;
    //QObject::connect(loginDialog, SIGNAL(loggined(QString,QString)), db, SLOT(login(QString,QString)));
    QObject::connect(loginDialog, SIGNAL(loggined(QString,QString)), &dbcon, SLOT(login(QString,QString)));
    QObject::connect(&dbcon, SIGNAL(loginSuccessed()), loginDialog, SLOT(loginSuccessed()));
    QObject::connect(&dbcon, SIGNAL(loginFailed()), loginDialog, SLOT(loginFailed()));
    if(loginDialog->exec() == LoginDialog::Accepted){
        //
    }
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
