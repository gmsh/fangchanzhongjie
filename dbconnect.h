#ifndef DBCONNECT_H
#define DBCONNECT_H
#include <QtCore/QObject>
#include <QtCore/QString>
class QString;
class QSqlTableModel;
class QSqlDatabase;
class DBConnect : public QObject
{
    Q_OBJECT
public:
    DBConnect();
    ~DBConnect();
    bool connectDB();
    QSqlTableModel * yuangongModel;

    QSqlTableModel * canshu_fangkelaiyuan;
    QSqlTableModel * canshu_fangyuanzhuangtai;
    QSqlTableModel * canshu_kehuzhuangtai;
    QSqlTableModel * canshu_genjinfangshi;
    QSqlTableModel * canshu_fukuanfangshi;
    QSqlTableModel * canshu_fenchengshuoming;

signals:
    void loginSuccessed();
    void loginFailed();
    void sendCanshuModel(QSqlTableModel * model);
public slots:
    void login(const QString & loginName, const QString & passwd);
private:
    QSqlDatabase * db;
};

#endif // DBCONNECT_H
