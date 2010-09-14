#include "canshuguanlidialog.h"
#include <QtCore/QDebug>
#include <QtCore/QPoint>
CanshuGuanliDialog::CanshuGuanliDialog(QWidget *parent, DBConnect *dbcon)
    :QDialog(parent)
{
    setupUi(this);
    this->dbcon = dbcon;;
    this->fangkeLaiyuanTableView->setModel(dbcon->canshu_fangkelaiyuan);
    this->fangyuanZhuangTaiTableView->setModel(dbcon->canshu_fangyuanzhuangtai);
    this->kehuZhuangtaiTableView->setModel(dbcon->canshu_kehuzhuangtai);
    this->genjinFangshiTableView->setModel(dbcon->canshu_genjinfangshi);
    this->fukuanFangshiTableView->setModel(dbcon->canshu_fukuanfangshi);
    this->fenchengShuomingTableView->setModel(dbcon->canshu_fenchengshuoming);
}
CanshuGuanliDialog::~CanshuGuanliDialog()
{

}
void CanshuGuanliDialog::on_canshuFenleiTreeWidget_itemActivated(QTreeWidgetItem *item, int cl)
{
    QString * canshu = &(item->text(0));
    this->label->setText(*canshu);
    if(*canshu == tr("房屋/客户来源")){
        this->stackedWidget->setCurrentIndex(0);
        qDebug() << 0;
    }else if(*canshu == tr("房源状态")){
        this->stackedWidget->setCurrentIndex(1);
        qDebug() << 1;
    }else if(*canshu == tr("客户状态")){
        this->stackedWidget->setCurrentIndex(2);
        qDebug() << 2;
    }else if(*canshu == tr("跟进方式")){
        this->stackedWidget->setCurrentIndex(3);
        qDebug() << 3;
    }else if(*canshu == tr("付款方式")){
        this->stackedWidget->setCurrentIndex(4);
        qDebug() << 4;
    }else if(*canshu == tr("分成说明")){
        this->stackedWidget->setCurrentIndex(5);
        qDebug() << 5;
    }
}
void CanshuGuanliDialog::on_addPushButton_clicked()
{
    switch(this->stackedWidget->currentIndex())
    {
    case 0:
        this->fangkeLaiyuanTableView->model()->insertRow(this->fangkeLaiyuanTableView->model()->rowCount());
        break;
    case 1:
        this->fangyuanZhuangTaiTableView->model()->insertRow(this->fangyuanZhuangTaiTableView->model()->rowCount());
        break;
    case 2:
        this->kehuZhuangtaiTableView->model()->insertRow(this->kehuZhuangtaiTableView->model()->rowCount());
        break;
    case 3:
        this->genjinFangshiTableView->model()->insertRow(this->genjinFangshiTableView->model()->rowCount());
        break;
    case 4:
        this->fukuanFangshiTableView->model()->insertRow(this->fukuanFangshiTableView->model()->rowCount());
        break;
    case 5:
        this->fenchengShuomingTableView->model()->insertRow(this->fenchengShuomingTableView->model()->rowCount());
        break;

    }
}

void CanshuGuanliDialog::on_modifyPushButton_clicked()
{
    QTableView * view;
    switch(this->stackedWidget->currentIndex())
    {
    case 0:
        view = this->fangkeLaiyuanTableView;
        break;
    case 1:
        view = this->fangyuanZhuangTaiTableView;
        break;
    case 2:
        view = this->kehuZhuangtaiTableView;
        break;
    case 3:
        view = this->genjinFangshiTableView;
        break;
    case 4:
        view = this->fukuanFangshiTableView;
        break;
    case 5:
        view = this->fenchengShuomingTableView;
        break;
    }
    view->edit(view->currentIndex());
}

void CanshuGuanliDialog::on_deletePushButton_clicked()
{
    QTableView * view;
    switch(this->stackedWidget->currentIndex())
    {
    case 0:
        view = this->fangkeLaiyuanTableView;
        break;
    case 1:
        view = this->fangyuanZhuangTaiTableView;
        break;
    case 2:
        view = this->kehuZhuangtaiTableView;
        break;
    case 3:
        view = this->genjinFangshiTableView;
        break;
    case 4:
        view = this->fukuanFangshiTableView;
        break;
    case 5:
        view = this->fenchengShuomingTableView;
        break;
    }
    view->model()->removeRow(view->currentIndex().row());
}
