#include <QtSql>
#include <QtCore/qcoreapplication.h>
bool connectDB();

int main(int argc, char * argv[])
{
    QCoreApplication app(argc, argv);
    if(connectDB()){
        qDebug() << "success.";
    }else{
        qDebug() << "failed.";
    }
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
