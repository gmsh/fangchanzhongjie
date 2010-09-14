#include "quanxianzushezhidialog.h"
#include <QtGui/QStandardItemModel>
#include <QtGui/QStandardItem>
#include <QtGui/QIcon>
QuanxianzuShezhiDialog::QuanxianzuShezhiDialog(QWidget *parent)
    :QDialog(parent)
{
    setupUi(this);
    this->fangyuan = new QIcon(":/images/tianjiafangyuan.png");
    this->keyuan = new QIcon(":/images/tianjiakehu.png");
    this->genjin = new QIcon(":/images/genjinchaxun.png");
    this->qianyue = new QIcon(":/images/qianyueguanli.png");
    this->xitong = new QIcon(":/images/xitongshezhi.png");
    this->yuangong = new QIcon(":/images/qiehuandenglu.png");
    this->quanxianzu = new QIcon(":/images/quanxian.png");
    QStandardItemModel * standardModel = new QStandardItemModel();
    treeView->setModel(standardModel);
    //standardModel->setHeaderData(0,Qt::Horizontal, "权限管理");
    this->fangyuanGuanli = new QStandardItem(*(this->fangyuan), tr("房源管理"));
    this->chushouFangyuan = new QStandardItem(*(this->fangyuan), tr("出售房源"));
    this->chuzuFangyuan = new QStandardItem(*(this->fangyuan), tr("出租房源"));
    this->hezuFangyuan = new QStandardItem(*(this->fangyuan), tr("合租房源"));
    this->keyuanGuanli = new QStandardItem(*(this->keyuan), tr("客源管理"));
    this->qiugouKehu = new QStandardItem(*(this->keyuan), tr("求购客户"));
    this->qiuzuKehu = new QStandardItem(*(this->keyuan), tr("求租客户"));
    this->hezuKehu = new QStandardItem(*(this->keyuan), tr("合租客户"));
    this->genjinGuanli = new QStandardItem(*(this->genjin), tr("跟进管理"));
    this->fangyuanGenjin = new QStandardItem(*(this->fangyuan), tr("房源跟进"));
    this->keyuanGenjin = new QStandardItem(*(this->keyuan), tr("客源跟进"));
    this->qianyueGuanli = new QStandardItem(*(this->qianyue), tr("签约管理"));
    this->xitongshezhi = new QStandardItem(*(this->xitong), tr("系统设置"));
    this->yuangongGuanli = new QStandardItem(*(this->yuangong), tr("员工管理"));
    this->quanxianzuguanli = new QStandardItem(*(this->quanxianzu), tr("权限组管理"));

    this->fangyuanGuanli->setCheckable(true);
    this->keyuanGuanli->setCheckable(true);
    this->genjinGuanli->setCheckable(true);
    this->qianyueGuanli->setCheckable(true);
    this->chushouFangyuan->setCheckable(true);
    this->chuzuFangyuan->setCheckable(true);
    this->hezuFangyuan->setCheckable(true);
    this->qiugouKehu->setCheckable(true);
    this->qiuzuKehu->setCheckable(true);
    this->hezuKehu->setCheckable(true);
    this->fangyuanGenjin->setCheckable(true);
    this->keyuanGenjin->setCheckable(true);
    this->yuangongGuanli->setCheckable(true);
    this->quanxianzuguanli->setCheckable(true);

    standardModel->appendRow(this->fangyuanGuanli);
    standardModel->appendRow(this->keyuanGuanli);
    standardModel->appendRow(this->genjinGuanli);
    standardModel->appendRow(this->qianyueGuanli);
    standardModel->appendRow(this->xitongshezhi);
    this->fangyuanGuanli->appendRow(this->chushouFangyuan);
    this->fangyuanGuanli->appendRow(this->chuzuFangyuan);
    this->fangyuanGuanli->appendRow(this->hezuFangyuan);
    this->keyuanGuanli->appendRow(this->qiugouKehu);
    this->keyuanGuanli->appendRow(this->qiuzuKehu);
    this->keyuanGuanli->appendRow(this->hezuKehu);
    this->genjinGuanli->appendRow(this->fangyuanGenjin);
    this->genjinGuanli->appendRow(this->keyuanGenjin);
    this->xitongshezhi->appendRow(this->yuangongGuanli);
    this->xitongshezhi->appendRow(this->quanxianzuguanli);


}

QuanxianzuShezhiDialog::~QuanxianzuShezhiDialog()
{

}
