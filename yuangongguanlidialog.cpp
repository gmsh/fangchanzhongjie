#include <QtCore/QDebug>
#include "yuangongguanlidialog.h"
#include "datedelegate.h"
#include "combodelegate.h"
#include "dbconnect.h"
YuangongGuanliDialog::YuangongGuanliDialog(QWidget *parent, DBConnect *dbcon)
    :QDialog(parent)
{
    setupUi(this);
    this->dbcon = dbcon;
    this->setTableModel(this->dbcon->yuangongModel);
}
YuangongGuanliDialog::~YuangongGuanliDialog()
{

}
void YuangongGuanliDialog::setTableModel(QSqlTableModel *tableModel)
{
    this->tableModel = tableModel;
    this->tableView->setModel(this->tableModel);

    QStringList * xingbieList = new QStringList;
    *xingbieList << tr("男") << tr("女");
    this->xingbieDelegate = new ComboDelegate(this,xingbieList);
    this->tableView->setItemDelegateForColumn(1, this->xingbieDelegate);

    QStringList * xueliList = new QStringList;
    *xueliList << tr("小学") << tr("初中") << tr("高中") << tr("本科") << tr("硕士") << tr("博士");
    this->xueliDelegate = new ComboDelegate(this, xueliList);
    this->tableView->setItemDelegateForColumn(3, this->xueliDelegate);

    QStringList * hunyinZhuangkuangList = new QStringList;
    *hunyinZhuangkuangList << tr("单身") << tr("已婚");
    this->hunyinZhuangkuangDelegate = new  ComboDelegate(this, hunyinZhuangkuangList);
    this->tableView->setItemDelegateForColumn(5, this->hunyinZhuangkuangDelegate);

    this->suozaiQuanxianzuDelegate = new ComboDelegate(this, this->dbcon->quanxianzuList());
    this->tableView->setItemDelegateForColumn(10, this->suozaiQuanxianzuDelegate);

    this->dateDelegate = new DateDelegate;
    this->tableView->setItemDelegateForColumn(7, this->dateDelegate);
    this->tableView->setItemDelegateForColumn(9,this->dateDelegate);
    this->tableView->selectRow(0);

    this->tableView->resizeColumnsToContents();

}
void YuangongGuanliDialog::on_addPushButton_clicked()
{
    //qDebug() << "addPushButton clicked";
    this->tableView->model()->insertRow(this->tableView->model()->rowCount());
}

void YuangongGuanliDialog::on_modifyPushButton_clicked()
{
    this->tableView->edit(this->tableView->currentIndex());
}

void YuangongGuanliDialog::on_deletePushButton_clicked()
{
    qDebug() << "deletePushButton clicked" << this->tableView->currentIndex().row();;
    this->tableView->model()->removeRow(this->tableView->currentIndex().row());
}
