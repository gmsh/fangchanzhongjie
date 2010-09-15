#ifndef DBCONNECT_H
#define DBCONNECT_H
#include <QtCore/QObject>
class QString;
class QStringList;
class QSqlTableModel;
class QSqlDatabase;
class DBConnect : public QObject
{
    Q_OBJECT
public:
    DBConnect();
    ~DBConnect();
    bool connectDB();
    QStringList * loginNames();
    bool insertIntoQuanxianZu(QString * mingcheng, bool a, bool b, bool c, bool d, bool e, bool f
                                                 , bool g, bool h, bool i, bool j, bool k, bool l);
    bool deleteQuanxianZu(QString * mingcheng);
    void getQuanxian(QString * mingcheng, bool * a,bool * b,bool * c,bool * d,bool * e,bool * f,bool * g,bool * h,bool * i,bool * j,bool * k,bool * l);
    QString & parseBool(bool a);
    QSqlTableModel * yuangongModel;

    QSqlTableModel * canshu_fangkelaiyuan;
    QSqlTableModel * canshu_fangyuanzhuangtai;
    QSqlTableModel * canshu_kehuzhuangtai;
    QSqlTableModel * canshu_genjinfangshi;
    QSqlTableModel * canshu_fukuanfangshi;
    QSqlTableModel * canshu_fenchengshuoming;
    QSqlTableModel * canshu_chengqu;

    QStringList * quanxianzuList();

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
