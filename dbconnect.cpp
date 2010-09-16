#include "dbconnect.h"
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
DBConnect::DBConnect()
    : QObject()
{
    if(!this->connectDB())
        qDebug() << "打开数据库失败";
    this->yuangongModel = new QSqlTableModel(this);
    this->yuangongModel->setTable("yuangong");
    this->yuangongModel->setHeaderData(0,Qt::Horizontal,tr("员工编号"));
    this->yuangongModel->setHeaderData(1,Qt::Horizontal,tr("性别"));
    this->yuangongModel->setHeaderData(2,Qt::Horizontal,tr("员工姓名"));
    this->yuangongModel->setHeaderData(3,Qt::Horizontal,tr("学历"));
    this->yuangongModel->setHeaderData(4,Qt::Horizontal,tr("身份证号"));
    this->yuangongModel->setHeaderData(5,Qt::Horizontal,tr("婚姻状况"));
    this->yuangongModel->setHeaderData(6,Qt::Horizontal,tr("联系电话"));
    this->yuangongModel->setHeaderData(7,Qt::Horizontal,tr("出生日期"));
    this->yuangongModel->setHeaderData(8,Qt::Horizontal,tr("籍贯"));
    this->yuangongModel->setHeaderData(9,Qt::Horizontal,tr("就职日期"));
    this->yuangongModel->setHeaderData(10,Qt::Horizontal,tr("所在权限组"));
    this->yuangongModel->setHeaderData(11,Qt::Horizontal,tr("密码"));
    this->yuangongModel->setHeaderData(12,Qt::Horizontal,tr("住址"));
    this->yuangongModel->setHeaderData(13,Qt::Horizontal,tr("备注"));
    this->yuangongModel->select();
    this->canshu_fangkelaiyuan = new QSqlTableModel(this);
    this->canshu_fangkelaiyuan->setTable("canshu_fangkelaiyuan");
    this->canshu_fangkelaiyuan->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->canshu_fangkelaiyuan->setHeaderData(1, Qt::Horizontal, tr("名称"));
    this->canshu_fangkelaiyuan->select();
    this->canshu_fangyuanzhuangtai = new QSqlTableModel(this);
    this->canshu_fangyuanzhuangtai->setTable("canshu_fangyuanzhuangtai");
    this->canshu_fangyuanzhuangtai->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->canshu_fangyuanzhuangtai->setHeaderData(1, Qt::Horizontal, tr("名称"));
    this->canshu_fangyuanzhuangtai->select();
    this->canshu_kehuzhuangtai = new QSqlTableModel(this);
    this->canshu_kehuzhuangtai->setTable("canshu_kehuzhuangtai");
    this->canshu_kehuzhuangtai->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->canshu_kehuzhuangtai->setHeaderData(1, Qt::Horizontal, tr("名称"));
    this->canshu_kehuzhuangtai->select();
    this->canshu_genjinfangshi = new QSqlTableModel(this);
    this->canshu_genjinfangshi->setTable("canshu_genjinfangshi");
    this->canshu_genjinfangshi->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->canshu_genjinfangshi->setHeaderData(1, Qt::Horizontal, tr("名称"));
    this->canshu_genjinfangshi->select();
    this->canshu_fukuanfangshi = new QSqlTableModel(this);
    this->canshu_fukuanfangshi->setTable("canshu_fukuanfangshi");
    this->canshu_fukuanfangshi->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->canshu_fukuanfangshi->setHeaderData(1, Qt::Horizontal, tr("名称"));
    this->canshu_fukuanfangshi->select();
    this->canshu_fenchengshuoming = new QSqlTableModel(this);
    this->canshu_fenchengshuoming->setTable("canshu_fenchengshuoming");
    this->canshu_fenchengshuoming->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->canshu_fenchengshuoming->setHeaderData(1, Qt::Horizontal, tr("名称"));
    this->canshu_fenchengshuoming->select();
    this->canshu_chengqu = new QSqlTableModel(this);
    this->canshu_chengqu->setTable("canshu_chengqu");
    this->canshu_chengqu->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->canshu_chengqu->setHeaderData(1, Qt::Horizontal, tr("名称"));
    this->chushoufangyuan = new QSqlTableModel(this);
    this->chushoufangyuan->setTable("chushoufangyuan");
    this->chushoufangyuan->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->chushoufangyuan->setHeaderData(1, Qt::Horizontal, tr("房屋状态"));
    this->chushoufangyuan->setHeaderData(2, Qt::Horizontal, tr("置业顾问"));
    this->chushoufangyuan->setHeaderData(3, Qt::Horizontal, tr("房屋来源"));
    this->chushoufangyuan->setHeaderData(4, Qt::Horizontal, tr("所在城区"));
    this->chushoufangyuan->setHeaderData(6, Qt::Horizontal, tr("户型"));
    this->chushoufangyuan->setHeaderData(7, Qt::Horizontal, tr("产权"));
    this->chushoufangyuan->setHeaderData(9, Qt::Horizontal, tr("建设年代"));
    this->chushoufangyuan->setHeaderData(11, Qt::Horizontal, tr("装修标准"));
    //this->chushoufangyuan->setHeaderData(13, Qt::Horizontal, tr("具体地址"));

    this->chushoufangyuan->select();

    this->chuzufangyuan = new QSqlTableModel(this);
    this->chuzufangyuan->setTable("chuzufangyuan");

    this->chuzufangyuan->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->chuzufangyuan->setHeaderData(1, Qt::Horizontal, tr("房屋状态"));
    this->chuzufangyuan->setHeaderData(2, Qt::Horizontal, tr("置业顾问"));
    this->chuzufangyuan->setHeaderData(3, Qt::Horizontal, tr("房屋来源"));
    this->chuzufangyuan->setHeaderData(4, Qt::Horizontal, tr("所在城区"));
    this->chuzufangyuan->setHeaderData(6, Qt::Horizontal, tr("户型"));
    this->chuzufangyuan->setHeaderData(7, Qt::Horizontal, tr("产权"));
    this->chuzufangyuan->setHeaderData(9, Qt::Horizontal, tr("建设年代"));
    this->chuzufangyuan->setHeaderData(11, Qt::Horizontal, tr("装修标准"));

    this->chuzufangyuan->select();

    this->hezufangyuan = new QSqlTableModel(this);
    this->hezufangyuan->setTable("hezufangyuan");


    this->hezufangyuan->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->hezufangyuan->setHeaderData(1, Qt::Horizontal, tr("房屋状态"));
    this->hezufangyuan->setHeaderData(2, Qt::Horizontal, tr("置业顾问"));
    this->hezufangyuan->setHeaderData(3, Qt::Horizontal, tr("房屋来源"));
    this->hezufangyuan->setHeaderData(4, Qt::Horizontal, tr("所在城区"));
    this->hezufangyuan->setHeaderData(6, Qt::Horizontal, tr("户型"));
    this->hezufangyuan->setHeaderData(7, Qt::Horizontal, tr("性别倾向"));
    this->hezufangyuan->setHeaderData(9, Qt::Horizontal, tr("建设年代"));
    this->hezufangyuan->setHeaderData(11, Qt::Horizontal, tr("装修标准"));

    this->hezufangyuan->select();

    this->qiugoukehu = new QSqlTableModel(this);
    this->qiugoukehu->setTable("qiugoukehu");
    this->qiugoukehu->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->qiugoukehu->setHeaderData(1, Qt::Horizontal, tr("房屋状态"));
    this->qiugoukehu->setHeaderData(2, Qt::Horizontal, tr("置业顾问"));
    this->qiugoukehu->setHeaderData(3, Qt::Horizontal, tr("房屋来源"));
    this->qiugoukehu->setHeaderData(4, Qt::Horizontal, tr("所在城区"));
    this->qiugoukehu->setHeaderData(6, Qt::Horizontal, tr("户型"));
    this->qiugoukehu->setHeaderData(7, Qt::Horizontal, tr("产权"));
    this->qiugoukehu->setHeaderData(9, Qt::Horizontal, tr("新旧程度"));
    this->qiugoukehu->setHeaderData(11, Qt::Horizontal, tr("装修标准"));

    this->qiugoukehu->select();

    this->qiuzukehu = new QSqlTableModel(this);
    this->qiuzukehu->setTable("qiuzukehu");
    this->qiuzukehu->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->qiuzukehu->setHeaderData(1, Qt::Horizontal, tr("房屋状态"));
    this->qiuzukehu->setHeaderData(2, Qt::Horizontal, tr("置业顾问"));
    this->qiuzukehu->setHeaderData(3, Qt::Horizontal, tr("房屋来源"));
    this->qiuzukehu->setHeaderData(4, Qt::Horizontal, tr("所在城区"));
    this->qiuzukehu->setHeaderData(6, Qt::Horizontal, tr("户型"));
    this->qiuzukehu->setHeaderData(7, Qt::Horizontal, tr("产权"));
    this->qiuzukehu->setHeaderData(9, Qt::Horizontal, tr("新旧程度"));
    this->qiuzukehu->setHeaderData(11, Qt::Horizontal, tr("装修标准"));

    this->qiuzukehu->select();

    this->hezukehu = new QSqlTableModel(this);
    this->hezukehu->setTable("hezukehu");
    this->hezukehu->setHeaderData(0, Qt::Horizontal, tr("编号"));
    this->hezukehu->setHeaderData(1, Qt::Horizontal, tr("房屋状态"));
    this->hezukehu->setHeaderData(2, Qt::Horizontal, tr("置业顾问"));
    this->hezukehu->setHeaderData(3, Qt::Horizontal, tr("房屋来源"));
    this->hezukehu->setHeaderData(4, Qt::Horizontal, tr("所在城区"));
    this->hezukehu->setHeaderData(6, Qt::Horizontal, tr("户型"));
    this->hezukehu->setHeaderData(7, Qt::Horizontal, tr("性别倾向"));
    this->hezukehu->setHeaderData(9, Qt::Horizontal, tr("新旧程度"));
    this->hezukehu->setHeaderData(11, Qt::Horizontal, tr("装修标准"));

    this->hezukehu->select();

}

DBConnect::~DBConnect()
{
    this->db->close();
}

void DBConnect::login(const QString &loginName, const QString &passwd)
{
    QSqlQuery query;
    query.exec("select mima from yuangong where yuangongxingming = '" + loginName + "'");
    query.next();
    if(passwd == query.value(0).toString())
        emit loginSuccessed();
    else
        emit loginFailed();

}

bool DBConnect::connectDB()
{
    this->db = new QSqlDatabase;
    *(this->db) = QSqlDatabase::addDatabase("QMYSQL");
    db->setHostName("localhost");
    db->setDatabaseName("fangchan");
    db->setUserName("root");
    db->setPassword("h6n4t2i5shz$");
    return db->open();
}

QStringList * DBConnect::loginNames()
{
    QStringList * list = new QStringList;
    QSqlQuery query;
    query.exec("select yuangongxingming from yuangong");
    while(query.next()){
        *list << query.value(0).toString();
    }
    return list;
}

QStringList * DBConnect::quanxianzuList()
{
    QSqlQuery query;
    query.exec("select mingcheng from quanxianzu");
    QStringList * list = new QStringList;
    while(query.next()){
        //qDebug() << "dbcon 111 add " << query.value(0).toString();
        *list << query.value(0).toString();
    }
    return list;
}

bool DBConnect::insertIntoQuanxianZu(QString *mingcheng, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i, bool j, bool k, bool l)
{
    QSqlQuery query;
    query.exec("delete from quanxianzu where mingcheng = '" + *mingcheng + "'");
    QString sql = "insert into quanxianzu values( '";
    sql += *mingcheng;
    sql += "' ,";
    sql += parseBool(a);
    sql += ", ";
    sql += parseBool(b);
    sql += ", ";
    sql += parseBool(c);
    sql += ", ";
    sql += parseBool(d);
    sql += ", ";
    sql += parseBool(e);
    sql += ", ";
    sql += parseBool(f);
    sql += ", ";
    sql += parseBool(g);
    sql += ", ";
    sql += parseBool(h);
    sql += ", ";
    sql += parseBool(i);
    sql += ", ";
    sql += parseBool(j);
    sql += ", ";
    sql += parseBool(k);
    sql += ", ";
    sql += parseBool(l);
    sql += ")";
    qDebug() << sql;
    return query.exec(sql);
    //return true;
}

QString & DBConnect::parseBool(bool a)
{
    if(a)
        return *(new QString("true"));
    else
        return *(new QString("false"));
}

bool DBConnect::deleteQuanxianZu(QString *mingcheng)
{
    QSqlQuery query;
    return query.exec("delete from quanxianzu where mingcheng = '" + *mingcheng + "'");
    //return true;
}

void DBConnect::getQuanxian(QString *mingcheng, bool *a, bool *b, bool *c, bool *d, bool *e, bool *f, bool *g, bool *h, bool *i, bool *j, bool *k, bool *l)
{
    QSqlQuery query;
    query.exec("select * from quanxianzu where mingcheng = '" + *mingcheng + "'");
    query.next();

    *a = query.value(1).toBool();
    *b = query.value(2).toBool();
    *c = query.value(3).toBool();
    *d = query.value(4).toBool();
    *e = query.value(5).toBool();
    *f = query.value(6).toBool();
    *g = query.value(7).toBool();
    *h = query.value(8).toBool();
    *i = query.value(9).toBool();
    *j = query.value(10).toBool();
    *k = query.value(11).toBool();
    *l = query.value(12).toBool();
}

QStringList * DBConnect::chengquList()
{
    QStringList * list = new QStringList;
    QSqlQuery query;
    query.exec("select mingcheng from canshu_chengqu");
    while(query.next()){
        *list << query.value(0).toString();
    }
    return list;
}

QStringList * DBConnect::fangwuZhuangtaiList()
{
    QStringList * list = new QStringList;
    QSqlQuery query;
    query.exec("select mingcheng from canshu_fangyuanzhuangtai");
    while(query.next()){
        *list << query.value(0).toString();
    }
    return list;
}

QStringList * DBConnect::kekuZhuangtaiList()
{
    QStringList * list = new QStringList;
    QSqlQuery query;
    query.exec("select mingcheng from canshu_kehuzhuangtai");
    while(query.next()){
        *list << query.value(0).toString();
    }
    return list;
}

QStringList * DBConnect::fangkeLaiyuanList()
{
    QStringList * list = new QStringList;
    QSqlQuery query;
    query.exec("select mingcheng from canshu_fangkelaiyuan");
    while(query.next()){
        *list << query.value(0).toString();
    }
    return list;
}

void DBConnect::getChushouFangyuan(int bianhao, QString *dqzt, QString *zygw, QString *fwly, QString *szcq, int *fwjg, QString *fwlx, QString *cq, float *fwmj, int *jcnd, int *szlc, QString *zxbz, int *lczs, QString *jtdz, bool *a, bool *b, bool *c, bool *d, bool *e, bool *f, bool *g, bool *h, bool *i, bool *j, bool *k, bool *l, bool *m, bool *n, QString *fyxxx, QString *yzum, QString *lxdh, QString *lxsj, QString *yzsm)
{
    QSqlQuery query;
    QString bianhaostr;
    bianhaostr.setNum(bianhao);
    query.exec("select * from chushoufangyuan where fangwubianhao = " + bianhaostr);
    query.next();
    *dqzt = query.value(1).toString();
    *zygw = query.value(2).toString();
    *fwly = query.value(3).toString();
    *szcq = query.value(4).toString();
    *fwjg = query.value(5).toInt();
    *fwlx = query.value(6).toString();
    *cq = query.value(7).toString();
    *fwmj = query.value(8).toFloat();
    * jcnd = query.value( 9).toInt();
    * szlc = query.value( 10).toInt();
    * zxbz = query.value( 11).toString();
    * lczs = query.value(12 ).toInt();
    * jtdz = query.value(13 ).toString();
    * a = query.value(14 ).toBool();
    * b = query.value(15 ).toBool();
    * c = query.value( 16).toBool();
    *d  = query.value( 17).toBool();
    *e = query.value( 18).toBool();
    *f = query.value(19 ).toBool();
    *g = query.value(20 ).toBool();
    *h = query.value( 21).toBool();
    * i = query.value( 22).toBool();
    *j  = query.value( 23).toBool();
    * k = query.value( 24).toBool();
    * l = query.value( 25).toBool();
    *m  = query.value( 26).toBool();
    *n = query.value( 27).toBool();
    * fyxxx = query.value(28 ).toString();
    * yzum = query.value( 29).toString();
    * lxdh = query.value( 30).toString();
    * lxsj = query.value( 31).toString();
    * yzsm = query.value( 32).toString();
}

void DBConnect::getChuzuFangyuan(int bianhao, QString *dqzt, QString *zygw, QString *fwly, QString *szcq, int *fwjg, QString *fwlx, QString *cq, float *fwmj, int *jcnd, int *szlc, QString *zxbz, int *lczs, QString *jtdz, bool *a, bool *b, bool *c, bool *d, bool *e, bool *f, bool *g, bool *h, bool *i, bool *j, bool *k, bool *l, bool *m, bool *n, QString *fyxxx, QString *yzum, QString *lxdh, QString *lxsj, QString *yzsm)
{
    QSqlQuery query;
    QString bianhaostr;
    bianhaostr.setNum(bianhao);
    query.exec("select * from chuzufangyuan where fangwubianhao = " + bianhaostr);
    query.next();
    *dqzt = query.value(1).toString();
    *zygw = query.value(2).toString();
    *fwly = query.value(3).toString();
    *szcq = query.value(4).toString();
    *fwjg = query.value(5).toInt();
    *fwlx = query.value(6).toString();
    *cq = query.value(7).toString();
    *fwmj = query.value(8).toFloat();
    * jcnd = query.value( 9).toInt();
    * szlc = query.value( 10).toInt();
    * zxbz = query.value( 11).toString();
    * lczs = query.value(12 ).toInt();
    * jtdz = query.value(13 ).toString();
    * a = query.value(14 ).toBool();
    * b = query.value(15 ).toBool();
    * c = query.value( 16).toBool();
    *d  = query.value( 17).toBool();
    *e = query.value( 18).toBool();
    *f = query.value(19 ).toBool();
    *g = query.value(20 ).toBool();
    *h = query.value( 21).toBool();
    * i = query.value( 22).toBool();
    *j  = query.value( 23).toBool();
    * k = query.value( 24).toBool();
    * l = query.value( 25).toBool();
    *m  = query.value( 26).toBool();
    *n = query.value( 27).toBool();
    * fyxxx = query.value(28 ).toString();
    * yzum = query.value( 29).toString();
    * lxdh = query.value( 30).toString();
    * lxsj = query.value( 31).toString();
    * yzsm = query.value( 32).toString();
}

void DBConnect::getHezuFangyuan(int bianhao, QString *dqzt, QString *zygw, QString *fwly, QString *szcq, int *fwjg, QString *fwlx, QString *cq, float *fwmj, int *jcnd, int *szlc, QString *zxbz, int *lczs, QString *jtdz, bool *a, bool *b, bool *c, bool *d, bool *e, bool *f, bool *g, bool *h, bool *i, bool *j, bool *k, bool *l, bool *m, bool *n, QString *fyxxx, QString *yzum, QString *lxdh, QString *lxsj, QString *yzsm)
{
    QSqlQuery query;
    QString bianhaostr;
    bianhaostr.setNum(bianhao);
    query.exec("select * from hezufangyuan where fangwubianhao = " + bianhaostr);
    query.next();
    *dqzt = query.value(1).toString();
    *zygw = query.value(2).toString();
    *fwly = query.value(3).toString();
    *szcq = query.value(4).toString();
    *fwjg = query.value(5).toInt();
    *fwlx = query.value(6).toString();
    *cq = query.value(7).toString();
    *fwmj = query.value(8).toFloat();
    * jcnd = query.value( 9).toInt();
    * szlc = query.value( 10).toInt();
    * zxbz = query.value( 11).toString();
    * lczs = query.value(12 ).toInt();
    * jtdz = query.value(13 ).toString();
    * a = query.value(14 ).toBool();
    * b = query.value(15 ).toBool();
    * c = query.value( 16).toBool();
    *d  = query.value( 17).toBool();
    *e = query.value( 18).toBool();
    *f = query.value(19 ).toBool();
    *g = query.value(20 ).toBool();
    *h = query.value( 21).toBool();
    * i = query.value( 22).toBool();
    *j  = query.value( 23).toBool();
    * k = query.value( 24).toBool();
    * l = query.value( 25).toBool();
    *m  = query.value( 26).toBool();
    *n = query.value( 27).toBool();
    * fyxxx = query.value(28 ).toString();
    * yzum = query.value( 29).toString();
    * lxdh = query.value( 30).toString();
    * lxsj = query.value( 31).toString();
    * yzsm = query.value( 32).toString();
}

bool DBConnect::insertChushouFangyuan(int bianhao, QString dqzt, QString zygw, QString fwly, QString szcq, int fwjg, QString fwlx, QString cq, float fwmj, int jcnd, int szlc, QString zxbz, int lczs, QString jtdz, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i, bool j, bool k, bool l, bool m, bool n, QString fyxxx, QString yzum, QString lxdh, QString lxsj, QString yzsm)
{
    QSqlQuery query;

    QString str;
    query.exec("delete from chushoufangyuan where fangwubianhao = " + str.setNum(bianhao));
    QString sql = "insert into chushoufangyuan values( ";
    sql += str.setNum(bianhao);
    sql += ", '";
    sql += dqzt;
    sql += "','";
    sql += zygw;
    sql += "','";
    sql += fwly;
    sql += "','";
    sql += szcq;
    sql += "',";
    sql += str.setNum(fwjg);
    sql += ",'";
    sql += fwlx;
    sql += "','";
    sql += cq;
    sql += "',";
    sql += str.setNum(fwmj);
    sql += ",";
    sql += str.setNum(jcnd);
    sql += ",";
    sql += str.setNum(szlc);
    sql += ",'";
    sql += zxbz;
    sql += "',";
    sql += str.setNum(lczs);
    sql += ",'";
    sql += jtdz;
    sql += "',";

    sql += parseBool(a);
    sql += ", ";
    sql += parseBool(b);
    sql += ", ";
    sql += parseBool(c);
    sql += ", ";
    sql += parseBool(d);
    sql += ", ";
    sql += parseBool(e);
    sql += ", ";
    sql += parseBool(f);
    sql += ", ";
    sql += parseBool(g);
    sql += ", ";
    sql += parseBool(h);
    sql += ", ";
    sql += parseBool(i);
    sql += ", ";
    sql += parseBool(j);
    sql += ", ";
    sql += parseBool(k);
    sql += ", ";
    sql += parseBool(l);
    sql += ", ";
    sql += parseBool(m);
    sql += ", ";
    sql += parseBool(n);
    sql += ", '";
    sql += fyxxx;
    sql += "','";
    sql += yzum;
    sql += "','";
    sql += lxdh;
    sql += "','";
    sql += lxsj;
    sql += "','";
    sql += yzsm;
    sql += "')";
    //qDebug() << sql ;
    return query.exec(sql);
}

bool DBConnect::insertChuzuFangyuan(int bianhao, QString dqzt, QString zygw, QString fwly, QString szcq, int fwjg, QString fwlx, QString cq, float fwmj, int jcnd, int szlc, QString zxbz, int lczs, QString jtdz, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i, bool j, bool k, bool l, bool m, bool n, QString fyxxx, QString yzum, QString lxdh, QString lxsj, QString yzsm)
{
    QSqlQuery query;
    QString str;
    query.exec("delete from chuzufangyuan where fangwubianhao = " + str.setNum(bianhao));
    QString sql = "insert into chuzufangyuan values( ";
    sql += str.setNum(bianhao);
    sql += ", '";
    sql += dqzt;
    sql += "','";
    sql += zygw;
    sql += "','";
    sql += fwly;
    sql += "','";
    sql += szcq;
    sql += "',";
    sql += str.setNum(fwjg);
    sql += ",'";
    sql += fwlx;
    sql += "','";
    sql += cq;
    sql += "',";
    sql += str.setNum(fwmj);
    sql += ",";
    sql += str.setNum(jcnd);
    sql += ",";
    sql += str.setNum(szlc);
    sql += ",'";
    sql += zxbz;
    sql += "',";
    sql += str.setNum(lczs);
    sql += ",'";
    sql += jtdz;
    sql += "',";

    sql += parseBool(a);
    sql += ", ";
    sql += parseBool(b);
    sql += ", ";
    sql += parseBool(c);
    sql += ", ";
    sql += parseBool(d);
    sql += ", ";
    sql += parseBool(e);
    sql += ", ";
    sql += parseBool(f);
    sql += ", ";
    sql += parseBool(g);
    sql += ", ";
    sql += parseBool(h);
    sql += ", ";
    sql += parseBool(i);
    sql += ", ";
    sql += parseBool(j);
    sql += ", ";
    sql += parseBool(k);
    sql += ", ";
    sql += parseBool(l);
    sql += ", ";
    sql += parseBool(m);
    sql += ", ";
    sql += parseBool(n);
    sql += ", '";
    sql += fyxxx;
    sql += "','";
    sql += yzum;
    sql += "','";
    sql += lxdh;
    sql += "','";
    sql += lxsj;
    sql += "','";
    sql += yzsm;
    sql += "')";
    //qDebug() << sql ;
    return query.exec(sql);
}

bool DBConnect::insertHezuFangyuan(int bianhao, QString dqzt, QString zygw, QString fwly, QString szcq, int fwjg, QString fwlx, QString xbqx, float fwmj, int jcnd, int szlc, QString zxbz, int lczs, QString jtdz, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i, bool j, bool k, bool l, bool m, bool n, QString fyxxx, QString yzum, QString lxdh, QString lxsj, QString yzsm)
{
    QSqlQuery query;

    QString str;
    query.exec("delete from hezufangyuan where fangwubianhao = " + str.setNum(bianhao));
    QString sql = "insert into hezufangyuan values( ";
    sql += str.setNum(bianhao);
    sql += ", '";
    sql += dqzt;
    sql += "','";
    sql += zygw;
    sql += "','";
    sql += fwly;
    sql += "','";
    sql += szcq;
    sql += "',";
    sql += str.setNum(fwjg);
    sql += ",'";
    sql += fwlx;
    sql += "','";
    sql += xbqx;
    sql += "',";
    sql += str.setNum(fwmj);
    sql += ",";
    sql += str.setNum(jcnd);
    sql += ",";
    sql += str.setNum(szlc);
    sql += ",'";
    sql += zxbz;
    sql += "',";
    sql += str.setNum(lczs);
    sql += ",'";
    sql += jtdz;
    sql += "',";

    sql += parseBool(a);
    sql += ", ";
    sql += parseBool(b);
    sql += ", ";
    sql += parseBool(c);
    sql += ", ";
    sql += parseBool(d);
    sql += ", ";
    sql += parseBool(e);
    sql += ", ";
    sql += parseBool(f);
    sql += ", ";
    sql += parseBool(g);
    sql += ", ";
    sql += parseBool(h);
    sql += ", ";
    sql += parseBool(i);
    sql += ", ";
    sql += parseBool(j);
    sql += ", ";
    sql += parseBool(k);
    sql += ", ";
    sql += parseBool(l);
    sql += ", ";
    sql += parseBool(m);
    sql += ", ";
    sql += parseBool(n);
    sql += ", '";
    sql += fyxxx;
    sql += "','";
    sql += yzum;
    sql += "','";
    sql += lxdh;
    sql += "','";
    sql += lxsj;
    sql += "','";
    sql += yzsm;
    sql += "')";
    //qDebug() << sql ;
    return query.exec(sql);
}

bool DBConnect::deleteFromChushoufangyuan(int bianhao)
{
    QSqlQuery query;
    QString str;
    return query.exec("delete from chushoufangyuan where fangwubianhao = " + str.setNum(bianhao));
}

bool DBConnect::deleteFromChuzufangyuan(int bianhao)
{
    QSqlQuery query;
    QString str;
    return query.exec("delete from chuzufangyuan where fangwubianhao = " + str.setNum(bianhao));
}

bool DBConnect::deleteFromHezufangyuan(int bianhao)
{
    QSqlQuery query;
    QString str;
    return query.exec("delete from hezufangyuan where fangwubianhao = " + str.setNum(bianhao));
}

bool DBConnect::deleteFromQiugouKehu(int bianhao)
{
    QSqlQuery query;
    QString str;
    return query.exec("delete from qiugoukehu where kehubianhao = " + str.setNum(bianhao));
}

bool DBConnect::deleteFromQiuzuKehu(int bianhao)
{
    QSqlQuery query;
    QString str;
    return query.exec("delete from qiuzukehu where kehubianhao = " + str.setNum(bianhao));
}

bool DBConnect::deleteFromHezuKehu(int bianhao)
{
    QSqlQuery query;
    QString str;
    return query.exec("delete from hezukehu where kehubianhao = " + str.setNum(bianhao));
}

bool DBConnect::insertQiugoukehu(int bianhao, QString dqzt, QString zygw, QString fwly, QString szcq, int fwjg, QString fwlx, QString cq, float fwmj, QString xjcd, int szlc, QString zxbz, int lczs, QString jtdz, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i, bool j, bool k, bool l, bool m, bool n, QString fyxxx, QString yzum, QString lxdh, QString lxsj, QString yzsm)
{
    QSqlQuery query;

    QString str;
    query.exec("delete from qiugoukehu where kehubianhao = " + str.setNum(bianhao));
    QString sql = "insert into qiugoukehu values( ";
    sql += str.setNum(bianhao);
    sql += ", '";
    sql += dqzt;
    sql += "','";
    sql += zygw;
    sql += "','";
    sql += fwly;
    sql += "','";
    sql += szcq;
    sql += "',";
    sql += str.setNum(fwjg);
    sql += ",'";
    sql += fwlx;
    sql += "','";
    sql += cq;
    sql += "',";
    sql += str.setNum(fwmj);
    sql += ",'";
    sql += xjcd;
    sql += "',";
    sql += str.setNum(szlc);
    sql += ",'";
    sql += zxbz;
    sql += "',";
    sql += str.setNum(lczs);
    sql += ",'";
    sql += jtdz;
    sql += "',";

    sql += parseBool(a);
    sql += ", ";
    sql += parseBool(b);
    sql += ", ";
    sql += parseBool(c);
    sql += ", ";
    sql += parseBool(d);
    sql += ", ";
    sql += parseBool(e);
    sql += ", ";
    sql += parseBool(f);
    sql += ", ";
    sql += parseBool(g);
    sql += ", ";
    sql += parseBool(h);
    sql += ", ";
    sql += parseBool(i);
    sql += ", ";
    sql += parseBool(j);
    sql += ", ";
    sql += parseBool(k);
    sql += ", ";
    sql += parseBool(l);
    sql += ", ";
    sql += parseBool(m);
    sql += ", ";
    sql += parseBool(n);
    sql += ", '";
    sql += fyxxx;
    sql += "','";
    sql += yzum;
    sql += "','";
    sql += lxdh;
    sql += "','";
    sql += lxsj;
    sql += "','";
    sql += yzsm;
    sql += "')";
    //qDebug() << sql ;
    return query.exec(sql);

}
bool DBConnect::insertQiuzukehu(int bianhao, QString dqzt, QString zygw, QString fwly, QString szcq, int fwjg, QString fwlx, QString cq, float fwmj, QString xjcd, int szlc, QString zxbz, int lczs, QString jtdz, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i, bool j, bool k, bool l, bool m, bool n, QString fyxxx, QString yzum, QString lxdh, QString lxsj, QString yzsm)
{
    QSqlQuery query;

    QString str;
    query.exec("delete from qiuzukehu where kehubianhao = " + str.setNum(bianhao));
    QString sql = "insert into qiuzukehu values( ";
    sql += str.setNum(bianhao);
    sql += ", '";
    sql += dqzt;
    sql += "','";
    sql += zygw;
    sql += "','";
    sql += fwly;
    sql += "','";
    sql += szcq;
    sql += "',";
    sql += str.setNum(fwjg);
    sql += ",'";
    sql += fwlx;
    sql += "','";
    sql += cq;
    sql += "',";
    sql += str.setNum(fwmj);
    sql += ",'";
    sql += xjcd;
    sql += "',";
    sql += str.setNum(szlc);
    sql += ",'";
    sql += zxbz;
    sql += "',";
    sql += str.setNum(lczs);
    sql += ",'";
    sql += jtdz;
    sql += "',";

    sql += parseBool(a);
    sql += ", ";
    sql += parseBool(b);
    sql += ", ";
    sql += parseBool(c);
    sql += ", ";
    sql += parseBool(d);
    sql += ", ";
    sql += parseBool(e);
    sql += ", ";
    sql += parseBool(f);
    sql += ", ";
    sql += parseBool(g);
    sql += ", ";
    sql += parseBool(h);
    sql += ", ";
    sql += parseBool(i);
    sql += ", ";
    sql += parseBool(j);
    sql += ", ";
    sql += parseBool(k);
    sql += ", ";
    sql += parseBool(l);
    sql += ", ";
    sql += parseBool(m);
    sql += ", ";
    sql += parseBool(n);
    sql += ", '";
    sql += fyxxx;
    sql += "','";
    sql += yzum;
    sql += "','";
    sql += lxdh;
    sql += "','";
    sql += lxsj;
    sql += "','";
    sql += yzsm;
    sql += "')";
    //qDebug() << sql ;
    return query.exec(sql);

}
bool DBConnect::insertHezukehu(int bianhao, QString dqzt, QString zygw, QString fwly, QString szcq, int fwjg, QString fwlx, QString cq, float fwmj, QString xjcd, int szlc, QString zxbz, int lczs, QString jtdz, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i, bool j, bool k, bool l, bool m, bool n, QString fyxxx, QString yzum, QString lxdh, QString lxsj, QString yzsm)
{
    QSqlQuery query;

    QString str;
    query.exec("delete from hezukehu where kehubianhao = " + str.setNum(bianhao));
    QString sql = "insert into hezukehu values( ";
    sql += str.setNum(bianhao);
    sql += ", '";
    sql += dqzt;
    sql += "','";
    sql += zygw;
    sql += "','";
    sql += fwly;
    sql += "','";
    sql += szcq;
    sql += "',";
    sql += str.setNum(fwjg);
    sql += ",'";
    sql += fwlx;
    sql += "','";
    sql += cq;
    sql += "',";
    sql += str.setNum(fwmj);
    sql += ",'";
    sql += xjcd;
    sql += "',";
    sql += str.setNum(szlc);
    sql += ",'";
    sql += zxbz;
    sql += "',";
    sql += str.setNum(lczs);
    sql += ",'";
    sql += jtdz;
    sql += "',";

    sql += parseBool(a);
    sql += ", ";
    sql += parseBool(b);
    sql += ", ";
    sql += parseBool(c);
    sql += ", ";
    sql += parseBool(d);
    sql += ", ";
    sql += parseBool(e);
    sql += ", ";
    sql += parseBool(f);
    sql += ", ";
    sql += parseBool(g);
    sql += ", ";
    sql += parseBool(h);
    sql += ", ";
    sql += parseBool(i);
    sql += ", ";
    sql += parseBool(j);
    sql += ", ";
    sql += parseBool(k);
    sql += ", ";
    sql += parseBool(l);
    sql += ", ";
    sql += parseBool(m);
    sql += ", ";
    sql += parseBool(n);
    sql += ", '";
    sql += fyxxx;
    sql += "','";
    sql += yzum;
    sql += "','";
    sql += lxdh;
    sql += "','";
    sql += lxsj;
    sql += "','";
    sql += yzsm;
    sql += "')";
    //qDebug() << sql ;
    return query.exec(sql);

}

void DBConnect::getQiugouKehu(int bianhao, QString *dqzt, QString *zygw, QString *fwly, QString *szcq, int *fwjg, QString *fwlx, QString *cq, float *fwmj, QString *xjcd, int *szlc, QString *zxbz, int *lczs, QString *jtdz, bool *a, bool *b, bool *c, bool *d, bool *e, bool *f, bool *g, bool *h, bool *i, bool *j, bool *k, bool *l, bool *m, bool *n, QString *fyxxx, QString *yzum, QString *lxdh, QString *lxsj, QString *yzsm)
{
    QSqlQuery query;
    QString bianhaostr;
    bianhaostr.setNum(bianhao);
    query.exec("select * from qiugoukehu where kehubianhao = " + bianhaostr);
    query.next();
    *dqzt = query.value(1).toString();
    *zygw = query.value(2).toString();
    *fwly = query.value(3).toString();
    *szcq = query.value(4).toString();
    *fwjg = query.value(5).toInt();
    *fwlx = query.value(6).toString();
    *cq = query.value(7).toString();
    *fwmj = query.value(8).toFloat();
    * xjcd = query.value( 9).toString();
    * szlc = query.value( 10).toInt();
    * zxbz = query.value( 11).toString();
    * lczs = query.value(12 ).toInt();
    * jtdz = query.value(13 ).toString();
    * a = query.value(14 ).toBool();
    * b = query.value(15 ).toBool();
    * c = query.value( 16).toBool();
    *d  = query.value( 17).toBool();
    *e = query.value( 18).toBool();
    *f = query.value(19 ).toBool();
    *g = query.value(20 ).toBool();
    *h = query.value( 21).toBool();
    * i = query.value( 22).toBool();
    *j  = query.value( 23).toBool();
    * k = query.value( 24).toBool();
    * l = query.value( 25).toBool();
    *m  = query.value( 26).toBool();
    *n = query.value( 27).toBool();
    * fyxxx = query.value(28 ).toString();
    * yzum = query.value( 29).toString();
    * lxdh = query.value( 30).toString();
    * lxsj = query.value( 31).toString();
    * yzsm = query.value( 32).toString();

}
void DBConnect::getQiuzuKehu(int bianhao, QString *dqzt, QString *zygw, QString *fwly, QString *szcq, int *fwjg, QString *fwlx, QString *cq, float *fwmj, QString *xjcd, int *szlc, QString *zxbz, int *lczs, QString *jtdz, bool *a, bool *b, bool *c, bool *d, bool *e, bool *f, bool *g, bool *h, bool *i, bool *j, bool *k, bool *l, bool *m, bool *n, QString *fyxxx, QString *yzum, QString *lxdh, QString *lxsj, QString *yzsm)
{
    QSqlQuery query;
    QString bianhaostr;
    bianhaostr.setNum(bianhao);
    query.exec("select * from qiuzukehu where kehubianhao = " + bianhaostr);
    query.next();
    *dqzt = query.value(1).toString();
    *zygw = query.value(2).toString();
    *fwly = query.value(3).toString();
    *szcq = query.value(4).toString();
    *fwjg = query.value(5).toInt();
    *fwlx = query.value(6).toString();
    *cq = query.value(7).toString();
    *fwmj = query.value(8).toFloat();
    * xjcd = query.value( 9).toString();
    * szlc = query.value( 10).toInt();
    * zxbz = query.value( 11).toString();
    * lczs = query.value(12 ).toInt();
    * jtdz = query.value(13 ).toString();
    * a = query.value(14 ).toBool();
    * b = query.value(15 ).toBool();
    * c = query.value( 16).toBool();
    *d  = query.value( 17).toBool();
    *e = query.value( 18).toBool();
    *f = query.value(19 ).toBool();
    *g = query.value(20 ).toBool();
    *h = query.value( 21).toBool();
    * i = query.value( 22).toBool();
    *j  = query.value( 23).toBool();
    * k = query.value( 24).toBool();
    * l = query.value( 25).toBool();
    *m  = query.value( 26).toBool();
    *n = query.value( 27).toBool();
    * fyxxx = query.value(28 ).toString();
    * yzum = query.value( 29).toString();
    * lxdh = query.value( 30).toString();
    * lxsj = query.value( 31).toString();
    * yzsm = query.value( 32).toString();

}
void DBConnect::getHezuKehu(int bianhao, QString *dqzt, QString *zygw, QString *fwly, QString *szcq, int *fwjg, QString *fwlx, QString *cq, float *fwmj, QString *xjcd, int *szlc, QString *zxbz, int *lczs, QString *jtdz, bool *a, bool *b, bool *c, bool *d, bool *e, bool *f, bool *g, bool *h, bool *i, bool *j, bool *k, bool *l, bool *m, bool *n, QString *fyxxx, QString *yzum, QString *lxdh, QString *lxsj, QString *yzsm)
{
    QSqlQuery query;
    QString bianhaostr;
    bianhaostr.setNum(bianhao);
    query.exec("select * from hezukehu where kehubianhao = " + bianhaostr);
    query.next();
    *dqzt = query.value(1).toString();
    *zygw = query.value(2).toString();
    *fwly = query.value(3).toString();
    *szcq = query.value(4).toString();
    *fwjg = query.value(5).toInt();
    *fwlx = query.value(6).toString();
    *cq = query.value(7).toString();
    *fwmj = query.value(8).toFloat();
    * xjcd = query.value( 9).toString();
    * szlc = query.value( 10).toInt();
    * zxbz = query.value( 11).toString();
    * lczs = query.value(12 ).toInt();
    * jtdz = query.value(13 ).toString();
    * a = query.value(14 ).toBool();
    * b = query.value(15 ).toBool();
    * c = query.value( 16).toBool();
    *d  = query.value( 17).toBool();
    *e = query.value( 18).toBool();
    *f = query.value(19 ).toBool();
    *g = query.value(20 ).toBool();
    *h = query.value( 21).toBool();
    * i = query.value( 22).toBool();
    *j  = query.value( 23).toBool();
    * k = query.value( 24).toBool();
    * l = query.value( 25).toBool();
    *m  = query.value( 26).toBool();
    *n = query.value( 27).toBool();
    * fyxxx = query.value(28 ).toString();
    * yzum = query.value( 29).toString();
    * lxdh = query.value( 30).toString();
    * lxsj = query.value( 31).toString();
    * yzsm = query.value( 32).toString();

}
