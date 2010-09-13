#include "dbconnect.h"
#include <QtCore/QString>
#include <QtCore/QDebug>
DBConnect::DBConnect()
    : QObject()
{

}

DBConnect::~DBConnect()
{

}

void DBConnect::login(const QString &loginName, const QString &passwd)
{
    qDebug() << loginName << "," << passwd;
    if(passwd == "888")//test only
        emit loginSuccessed();
    else
        emit loginFailed();

}

