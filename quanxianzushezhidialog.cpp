#include "dbconnect.h"
#include "quanxianzushezhidialog.h"
#include <QtGui/QStandardItemModel>
#include <QtGui/QStandardItem>
#include <QtGui/QIcon>
#include <QtCore/QDebug>
QuanxianzuShezhiDialog::QuanxianzuShezhiDialog(QWidget *parent, DBConnect *dbcon, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i, bool j, bool k, bool l, QString *mingcheng)
    :QDialog(parent)
{
    setupUi(this);
    this->dbcon = dbcon;
    this->fangyuan = new QIcon(":/images/tianjiafangyuan.png");
    this->keyuan = new QIcon(":/images/tianjiakehu.png");
    this->genjin = new QIcon(":/images/genjinchaxun.png");
    this->qianyue = new QIcon(":/images/qianyuechengjiao.png");
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
    this->canshuShezhi = new QStandardItem(*(this->xitong), tr("参数设置"));

    //this->fangyuanGuanli->setCheckable(true);
    //this->keyuanGuanli->setCheckable(true);
    //this->genjinGuanli->setCheckable(true);
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
    this->canshuShezhi->setCheckable(true);

    if(a)
        this->chushouFangyuan->setCheckState(Qt::Checked);
    if(b)
        this->chuzuFangyuan->setCheckState(Qt::Checked);
    if(c)
        this->hezuFangyuan->setCheckState(Qt::Checked);
    if(d)
        this->qiugouKehu->setCheckState(Qt::Checked);
    if(e)
        this->qiuzuKehu->setCheckState(Qt::Checked);
    if(f)
        this->hezuKehu->setCheckState(Qt::Checked);
    if(g)
        this->fangyuanGenjin->setCheckState(Qt::Checked);
    if(h)
        this->keyuanGenjin->setCheckState(Qt::Checked);
    if(i)
        this->qianyueGuanli->setCheckState(Qt::Checked);
    if(j)
        this->yuangongGuanli->setCheckState(Qt::Checked);
    if(k)
        this->quanxianzuguanli->setCheckState(Qt::Checked);
    if(l)
        this->canshuShezhi->setCheckState(Qt::Checked);
    if(mingcheng){
        this->lineEdit->setText(*mingcheng);
        this->lineEdit->setEnabled(false);
    }
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
    this->xitongshezhi->appendRow(this->canshuShezhi);


}

QuanxianzuShezhiDialog::~QuanxianzuShezhiDialog()
{
    free(fangyuanGuanli);
    free(chushouFangyuan);
    free(chuzuFangyuan);
    free(hezuFangyuan);
    free(keyuanGuanli);
    free(qiuzuKehu);
    free(qiugouKehu);
    free(hezuKehu);
    free(genjinGuanli);
    free(fangyuanGenjin);
    free(keyuanGenjin);
    free(qianyueGuanli);
    free(xitongshezhi);
    free(yuangongGuanli);
    free(quanxianzuguanli);
    free(canshuShezhi);
    free(fangyuan);
    free(keyuan);
    free(genjin);
    free(qianyue);
    free(xitong);
    free(yuangong);
    free(quanxianzu);
}

void QuanxianzuShezhiDialog::accept()
{
    //qDebug() << "quanxianshezhi 102" << this->chushouFangyuan->checkState();
    this->dbcon->insertIntoQuanxianZu(&(this->lineEdit->text()),
                                      this->chushouFangyuan->checkState() != 0,
                                      this->chuzuFangyuan->checkState() != 0,
                                      this->hezuFangyuan->checkState() != 0,
                                      this->qiugouKehu->checkState() != 0,
                                      this->qiuzuKehu->checkState() != 0,
                                      this->hezuKehu->checkState() != 0,
                                      this->fangyuanGenjin->checkState() != 0,
                                      this->keyuanGenjin->checkState() != 0,
                                      this->qianyueGuanli->checkState() != 0,
                                      this->yuangongGuanli->checkState() != 0,
                                      this->quanxianzuguanli->checkState() !=0,
                                      this->canshuShezhi->checkState() != 0);
    QDialog::accept();
}
