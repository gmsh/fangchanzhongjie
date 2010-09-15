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
