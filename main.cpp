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
//mainWindow.show();
    if(loginDialog->exec() != LoginDialog::Accepted)
        qApp->quit();

    MainWindow mainWindow(&dbcon, new QString(loginDialog->loginNameComboBox->currentText()));

        mainWindow.show();
    //qDebug() << *(dbcon.getSuozaiQuanxianzu(new QString(QObject::tr("测试姓名"))));

    /*bool a, b, c, d, e, f, g, h, i, j, k, l;
    QString * suozaiquanxianzu = dbcon.getSuozaiQuanxianzu(new QString(QObject::tr("测试姓名")));
    dbcon.getQuanxian(suozaiquanxianzu, &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l);
    qDebug() << *suozaiquanxianzu;*/
    /*YuangongGuanliDialog yuangongGuanliDialog(0);
    yuangongGuanliDialog.setTableModel(dbcon.yuangongModel);
    yuangongGuanliDialog.show();*/

    /*CanshuGuanliDialog canshuGuanliDialog(0, &dbcon);
    canshuGuanliDialog.show();*/

    /*QuanxianzuShezhiDialog quanxianzuShezhiDialog;
    quanxianzuShezhiDialog.show();*/

    /*QuanxianzuGuanliDialog quanxianzuGuanliDialog(0,&dbcon);
    quanxianzuGuanliDialog.show();*/

    /*ChengjiaoQianyueDialog chengjiaoqianyuedialog(0, &dbcon);
    chengjiaoqianyuedialog.exec();*/

    /*FangyuanDialog fangyuanDialog(0, &dbcon);
    fangyuanDialog.show();*/

    /*KeyuanDialog keyuanDialog(0, &dbcon);
    keyuanDialog.show();*/

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
