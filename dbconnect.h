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
    void getChushouFangyuan(int bianhao,
                            QString * dqzt,
                            QString *zygw,
                            QString* fwly,
                            QString * szcq,
                            int * fwjg,
                            QString * fwlx,
                            QString * cq,
                            float * fwmj,
                            int * jcnd,
                            int * szlc,
                            QString * zxbz,
                            int * lczs,
                            QString * jtdz,
                            bool * a,
                            bool * b,
                            bool * c,
                            bool *d ,
                            bool *e,
                            bool *f,
                            bool *g,
                            bool *h,
                            bool * i,
                            bool *j ,
                            bool * k,
                            bool* l,
                            bool *m ,
                            bool *n,
                            QString * fyxxx,
                            QString * yzum,
                            QString * lxdh,
                            QString * lxsj,
                            QString * yzsm);
    void getChuzuFangyuan(int bianhao,
                            QString * dqzt,
                            QString *zygw,
                            QString* fwly,
                            QString * szcq,
                            int * fwjg,
                            QString * fwlx,
                            QString * cq,
                            float * fwmj,
                            int * jcnd,
                            int * szlc,
                            QString * zxbz,
                            int * lczs,
                            QString * jtdz,
                            bool * a,
                            bool * b,
                            bool * c,
                            bool *d ,
                            bool *e,
                            bool *f,
                            bool *g,
                            bool *h,
                            bool * i,
                            bool *j ,
                            bool * k,
                            bool* l,
                            bool *m ,
                            bool *n,
                            QString * fyxxx,
                            QString * yzum,
                            QString * lxdh,
                            QString * lxsj,
                            QString * yzsm);

    void getHezuFangyuan(int bianhao,
                            QString * dqzt,
                            QString *zygw,
                            QString* fwly,
                            QString * szcq,
                            int * fwjg,
                            QString * fwlx,
                            QString * cq,
                            float * fwmj,
                            int * jcnd,
                            int * szlc,
                            QString * zxbz,
                            int * lczs,
                            QString * jtdz,
                            bool * a,
                            bool * b,
                            bool * c,
                            bool *d ,
                            bool *e,
                            bool *f,
                            bool *g,
                            bool *h,
                            bool * i,
                            bool *j ,
                            bool * k,
                            bool* l,
                            bool *m ,
                            bool *n,
                            QString * fyxxx,
                            QString * yzum,
                            QString * lxdh,
                            QString * lxsj,
                            QString * yzsm);


    bool insertChushouFangyuan(int bianhao,
                             QString  dqzt,
                             QString zygw,
                             QString fwly,
                             QString  szcq,
                             int  fwjg,
                             QString  fwlx,
                             QString  cq,
                             float  fwmj,
                             int jcnd,
                             int  szlc,
                             QString  zxbz,
                             int  lczs,
                             QString  jtdz,
                             bool  a,
                             bool  b,
                             bool  c,
                             bool d ,
                             bool e,
                             bool f,
                             bool g,
                             bool h,
                             bool  i,
                             bool j ,
                             bool  k,
                             bool l,
                             bool m ,
                             bool n,
                             QString  fyxxx,
                             QString  yzum,
                             QString  lxdh,
                             QString lxsj,
                             QString  yzsm);

    bool insertChuzuFangyuan(int bianhao,
                             QString  dqzt,
                             QString zygw,
                             QString fwly,
                             QString  szcq,
                             int  fwjg,
                             QString  fwlx,
                             QString  cq,
                             float  fwmj,
                             int jcnd,
                             int  szlc,
                             QString  zxbz,
                             int  lczs,
                             QString  jtdz,
                             bool  a,
                             bool  b,
                             bool  c,
                             bool d ,
                             bool e,
                             bool f,
                             bool g,
                             bool h,
                             bool  i,
                             bool j ,
                             bool  k,
                             bool l,
                             bool m ,
                             bool n,
                             QString  fyxxx,
                             QString  yzum,
                             QString  lxdh,
                             QString lxsj,
                             QString  yzsm);

    bool insertHezuFangyuan(int bianhao,
                             QString  dqzt,
                             QString zygw,
                             QString fwly,
                             QString  szcq,
                             int  fwjg,
                             QString  fwlx,
                             QString  xbqx,
                             float  fwmj,
                             int jcnd,
                             int  szlc,
                             QString  zxbz,
                             int  lczs,
                             QString  jtdz,
                             bool  a,
                             bool  b,
                             bool  c,
                             bool d ,
                             bool e,
                             bool f,
                             bool g,
                             bool h,
                             bool  i,
                             bool j ,
                             bool  k,
                             bool l,
                             bool m ,
                             bool n,
                             QString  fyxxx,
                             QString  yzum,
                             QString  lxdh,
                             QString lxsj,
                             QString  yzsm);
    bool deleteFromChushoufangyuan(int bianhao);
    bool deleteFromChuzufangyuan(int bianhao);
    bool deleteFromHezufangyuan(int bianhao);
    QString & parseBool(bool a);
    QSqlTableModel * yuangongModel;

    QSqlTableModel * canshu_fangkelaiyuan;
    QSqlTableModel * canshu_fangyuanzhuangtai;
    QSqlTableModel * canshu_kehuzhuangtai;
    QSqlTableModel * canshu_genjinfangshi;
    QSqlTableModel * canshu_fukuanfangshi;
    QSqlTableModel * canshu_fenchengshuoming;
    QSqlTableModel * canshu_chengqu;
    QSqlTableModel * chushoufangyuan;
    QSqlTableModel * chuzufangyuan;
    QSqlTableModel * hezufangyuan;

    QStringList * quanxianzuList();
    QStringList * chengquList();
    QStringList * fangwuZhuangtaiList();
    QStringList * kekuZhuangtaiList();
    QStringList * fangkeLaiyuanList();

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
