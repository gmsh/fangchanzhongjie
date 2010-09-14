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
}

DBConnect::~DBConnect()
{

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
    while(query.next())
    {
        *list << query.value(0).toString();
    }
    return list;
}
