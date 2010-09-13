#ifndef DBCONNECT_H
#define DBCONNECT_H
#include <QtCore/QObject>
#include <QtCore/QString>
class QString;
class DBConnect : public QObject
{
    Q_OBJECT
public:
    DBConnect();
    ~DBConnect();
signals:
    void loginSuccessed();
    void loginFailed();
public slots:
    void login(const QString & loginName, const QString & passwd);
};

#endif // DBCONNECT_H
