#include "mainwindow.h"
#include "quanxianzuguanlidialog.h"
#include "yuangongguanlidialog.h"
#include "canshuguanlidialog.h"
#include "fangyuandialog.h"
#include "keyuandialog.h"
#include "dbconnect.h"
#include <QtGui/QMenu>
#include <QtGui/QAction>
#include <QtGui/QMessageBox>
#include <QtCore/QDebug>

MainWindow::MainWindow(DBConnect *dbcon)
{
    this->dbcon = dbcon;
    setupUi(this);

    this->filterChengqu_0 = new QString;
    this->filterLeixing_0 = new QString;
    this->filterZhuangtai_0 = new QString;
    this->filterChengqu_1 = new QString;
    this->filterLeixing_1 = new QString;
    this->filterZhuangtai_1 = new QString;
    this->filterChengqu_2 = new QString;
    this->filterLeixing_2 = new QString;
    this->filterZhuangtai_2 = new QString;
    this->filterChengqu_3 = new QString;
    this->filterLeixing_3 = new QString;
    this->filterZhuangtai_3 = new QString;
    this->filterChengqu_4 = new QString;
    this->filterLeixing_4 = new QString;
    this->filterZhuangtai_4 = new QString;
    this->filterChengqu_5 = new QString;
    this->filterLeixing_5 = new QString;
    this->filterZhuangtai_5 = new QString;

    this->xitongShezhiMenu = new QMenu;

    this->fangwuLeixingComboBox_0->addItem((tr("不限")));
    this->fangwuLeixingComboBox_0->addItem(tr("1室"));
    this->fangwuLeixingComboBox_0->addItem(tr("1室1厅"));
    this->fangwuLeixingComboBox_0->addItem(tr("2室"));
    this->fangwuLeixingComboBox_0->addItem(tr("2室1厅"));
    this->fangwuLeixingComboBox_0->addItem(tr("2室2厅"));
    this->fangwuLeixingComboBox_0->addItem(tr("3室"));
    this->fangwuLeixingComboBox_0->addItem(tr("3室1厅"));
    this->fangwuLeixingComboBox_0->addItem(tr("3室2厅"));
    this->fangwuLeixingComboBox_0->addItem(tr("写字楼"));
    this->fangwuLeixingComboBox_0->addItem(tr("办公室"));
    this->fangwuLeixingComboBox_0->addItem(tr("商住两用"));
    this->fangwuLeixingComboBox_0->addItem(tr("门面房"));
    this->fangwuLeixingComboBox_0->addItem(tr("商铺"));
    this->fangwuLeixingComboBox_0->addItem(tr("厂房"));
    this->fangwuLeixingComboBox_0->addItem(tr("仓库"));
    this->fangwuLeixingComboBox_0->addItem(tr("别墅"));
    this->fangwuLeixingComboBox_0->addItem(tr("地皮"));
    this->fangwuLeixingComboBox_0->addItem(tr("其他"));

    this->fangwuLeixingComboBox_1->addItem((tr("不限")));
    this->fangwuLeixingComboBox_1->addItem(tr("1室"));
    this->fangwuLeixingComboBox_1->addItem(tr("1室1厅"));
    this->fangwuLeixingComboBox_1->addItem(tr("2室"));
    this->fangwuLeixingComboBox_1->addItem(tr("2室1厅"));
    this->fangwuLeixingComboBox_1->addItem(tr("2室2厅"));
    this->fangwuLeixingComboBox_1->addItem(tr("3室"));
    this->fangwuLeixingComboBox_1->addItem(tr("3室1厅"));
    this->fangwuLeixingComboBox_1->addItem(tr("3室2厅"));
    this->fangwuLeixingComboBox_1->addItem(tr("写字楼"));
    this->fangwuLeixingComboBox_1->addItem(tr("办公室"));
    this->fangwuLeixingComboBox_1->addItem(tr("商住两用"));
    this->fangwuLeixingComboBox_1->addItem(tr("门面房"));
    this->fangwuLeixingComboBox_1->addItem(tr("商铺"));
    this->fangwuLeixingComboBox_1->addItem(tr("厂房"));
    this->fangwuLeixingComboBox_1->addItem(tr("仓库"));
    this->fangwuLeixingComboBox_1->addItem(tr("别墅"));
    this->fangwuLeixingComboBox_1->addItem(tr("地皮"));
    this->fangwuLeixingComboBox_1->addItem(tr("其他"));

    this->fangwuLeixingComboBox_2->addItem((tr("不限")));
    this->fangwuLeixingComboBox_2->addItem(tr("1室"));
    this->fangwuLeixingComboBox_2->addItem(tr("1室1厅"));
    this->fangwuLeixingComboBox_2->addItem(tr("2室"));
    this->fangwuLeixingComboBox_2->addItem(tr("2室1厅"));
    this->fangwuLeixingComboBox_2->addItem(tr("2室2厅"));
    this->fangwuLeixingComboBox_2->addItem(tr("3室"));
    this->fangwuLeixingComboBox_2->addItem(tr("3室1厅"));
    this->fangwuLeixingComboBox_2->addItem(tr("3室2厅"));
    this->fangwuLeixingComboBox_2->addItem(tr("写字楼"));
    this->fangwuLeixingComboBox_2->addItem(tr("办公室"));
    this->fangwuLeixingComboBox_2->addItem(tr("商住两用"));
    this->fangwuLeixingComboBox_2->addItem(tr("门面房"));
    this->fangwuLeixingComboBox_2->addItem(tr("商铺"));
    this->fangwuLeixingComboBox_2->addItem(tr("厂房"));
    this->fangwuLeixingComboBox_2->addItem(tr("仓库"));
    this->fangwuLeixingComboBox_2->addItem(tr("别墅"));
    this->fangwuLeixingComboBox_2->addItem(tr("地皮"));
    this->fangwuLeixingComboBox_2->addItem(tr("其他"));

    this->fangwuLeixingComboBox_3->addItem((tr("不限")));
    this->fangwuLeixingComboBox_3->addItem(tr("1室"));
    this->fangwuLeixingComboBox_3->addItem(tr("1室1厅"));
    this->fangwuLeixingComboBox_3->addItem(tr("2室"));
    this->fangwuLeixingComboBox_3->addItem(tr("2室1厅"));
    this->fangwuLeixingComboBox_3->addItem(tr("2室2厅"));
    this->fangwuLeixingComboBox_3->addItem(tr("3室"));
    this->fangwuLeixingComboBox_3->addItem(tr("3室1厅"));
    this->fangwuLeixingComboBox_3->addItem(tr("3室2厅"));
    this->fangwuLeixingComboBox_3->addItem(tr("写字楼"));
    this->fangwuLeixingComboBox_3->addItem(tr("办公室"));
    this->fangwuLeixingComboBox_3->addItem(tr("商住两用"));
    this->fangwuLeixingComboBox_3->addItem(tr("门面房"));
    this->fangwuLeixingComboBox_3->addItem(tr("商铺"));
    this->fangwuLeixingComboBox_3->addItem(tr("厂房"));
    this->fangwuLeixingComboBox_3->addItem(tr("仓库"));
    this->fangwuLeixingComboBox_3->addItem(tr("别墅"));
    this->fangwuLeixingComboBox_3->addItem(tr("地皮"));
    this->fangwuLeixingComboBox_3->addItem(tr("其他"));

    this->fangwuLeixingComboBox_4->addItem((tr("不限")));
    this->fangwuLeixingComboBox_4->addItem(tr("1室"));
    this->fangwuLeixingComboBox_4->addItem(tr("1室1厅"));
    this->fangwuLeixingComboBox_4->addItem(tr("2室"));
    this->fangwuLeixingComboBox_4->addItem(tr("2室1厅"));
    this->fangwuLeixingComboBox_4->addItem(tr("2室2厅"));
    this->fangwuLeixingComboBox_4->addItem(tr("3室"));
    this->fangwuLeixingComboBox_4->addItem(tr("3室1厅"));
    this->fangwuLeixingComboBox_4->addItem(tr("3室2厅"));
    this->fangwuLeixingComboBox_4->addItem(tr("写字楼"));
    this->fangwuLeixingComboBox_4->addItem(tr("办公室"));
    this->fangwuLeixingComboBox_4->addItem(tr("商住两用"));
    this->fangwuLeixingComboBox_4->addItem(tr("门面房"));
    this->fangwuLeixingComboBox_4->addItem(tr("商铺"));
    this->fangwuLeixingComboBox_4->addItem(tr("厂房"));
    this->fangwuLeixingComboBox_4->addItem(tr("仓库"));
    this->fangwuLeixingComboBox_4->addItem(tr("别墅"));
    this->fangwuLeixingComboBox_4->addItem(tr("地皮"));
    this->fangwuLeixingComboBox_4->addItem(tr("其他"));

    this->fangwuLeixingComboBox_5->addItem((tr("不限")));
    this->fangwuLeixingComboBox_5->addItem(tr("1室"));
    this->fangwuLeixingComboBox_5->addItem(tr("1室1厅"));
    this->fangwuLeixingComboBox_5->addItem(tr("2室"));
    this->fangwuLeixingComboBox_5->addItem(tr("2室1厅"));
    this->fangwuLeixingComboBox_5->addItem(tr("2室2厅"));
    this->fangwuLeixingComboBox_5->addItem(tr("3室"));
    this->fangwuLeixingComboBox_5->addItem(tr("3室1厅"));
    this->fangwuLeixingComboBox_5->addItem(tr("3室2厅"));
    this->fangwuLeixingComboBox_5->addItem(tr("写字楼"));
    this->fangwuLeixingComboBox_5->addItem(tr("办公室"));
    this->fangwuLeixingComboBox_5->addItem(tr("商住两用"));
    this->fangwuLeixingComboBox_5->addItem(tr("门面房"));
    this->fangwuLeixingComboBox_5->addItem(tr("商铺"));
    this->fangwuLeixingComboBox_5->addItem(tr("厂房"));
    this->fangwuLeixingComboBox_5->addItem(tr("仓库"));
    this->fangwuLeixingComboBox_5->addItem(tr("别墅"));
    this->fangwuLeixingComboBox_5->addItem(tr("地皮"));
    this->fangwuLeixingComboBox_5->addItem(tr("其他"));

    QStringList * list = this->dbcon->chengquList();
    this->chengquComboBox_0->addItem(tr("不限"));
    this->chengquComboBox_1->addItem(tr("不限"));
    this->chengquComboBox_2->addItem(tr("不限"));
    this->chengquComboBox_3->addItem(tr("不限"));
    this->chengquComboBox_4->addItem(tr("不限"));
    this->chengquComboBox_5->addItem(tr("不限"));
    this->chengquComboBox_0->addItems(*(list));
    this->chengquComboBox_1->addItems(*(list));
    this->chengquComboBox_2->addItems(*(list));
    this->chengquComboBox_3->addItems(*(list));
    this->chengquComboBox_4->addItems(*(list));
    this->chengquComboBox_5->addItems(*(list));

    list = this->dbcon->fangwuZhuangtaiList();
    this->fangwuZhuangtaiComboBox_0->addItem(tr("不限"));
    this->fangwuZhuangtaiComboBox_1->addItem(tr("不限"));
    this->fangwuZhuangtaiComboBox_2->addItem(tr("不限"));
    this->fangwuZhuangtaiComboBox_0->addItems(*list);
    this->fangwuZhuangtaiComboBox_1->addItems(*list);
    this->fangwuZhuangtaiComboBox_2->addItems(*list);

    list = this->dbcon->kekuZhuangtaiList();
    this->kehuZhuangtaiComboBox_3->addItem(tr("不限"));
    this->kehuZhuangtaiComboBox_4->addItem(tr("不限"));
    this->kehuZhuangtaiComboBox_5->addItem(tr("不限"));
    this->kehuZhuangtaiComboBox_3->addItems(*list);
    this->kehuZhuangtaiComboBox_4->addItems(*list);
    this->kehuZhuangtaiComboBox_5->addItems(*list);


    this->quanxianzuIcon = new QIcon(":/images/quanxian.png");
    this->actionYuangongGuanli = new QAction(this->actionQiehuanDenglu->icon(),tr("员工管理"), this);
    this->actionQuanxianzuGuanli = new QAction(*(this->quanxianzuIcon), tr("权限组管理"), this);
    this->actionCanshuShezhi = new QAction(this->actionXitongShezhi->icon(), tr("参数设置"), this);
    this->xitongShezhiMenu->addAction(this->actionYuangongGuanli);
    this->xitongShezhiMenu->addAction(this->actionQuanxianzuGuanli);
    this->xitongShezhiMenu->addAction(this->actionCanshuShezhi);
    this->actionXitongShezhi->setMenu(this->xitongShezhiMenu);

    this->tableView_0->setModel(dbcon->chushoufangyuan);
    this->tableView_1->setModel(dbcon->chuzufangyuan);
    this->tableView_2->setModel(dbcon->hezufangyuan);

    this->tableView_0->setColumnHidden(5,true);
    this->tableView_0->setColumnHidden(8,true);
    this->tableView_0->setColumnHidden(10,true);
    this->tableView_0->setColumnHidden(12,true);
    this->tableView_0->setColumnHidden(13,true);
    this->tableView_0->setColumnHidden(14,true);
    this->tableView_0->setColumnHidden(15,true);
    this->tableView_0->setColumnHidden(16,true);
    this->tableView_0->setColumnHidden(17,true);
    this->tableView_0->setColumnHidden(18,true);
    this->tableView_0->setColumnHidden(19,true);
    this->tableView_0->setColumnHidden(20,true);
    this->tableView_0->setColumnHidden(21,true);
    this->tableView_0->setColumnHidden(22,true);
    this->tableView_0->setColumnHidden(23,true);
    this->tableView_0->setColumnHidden(24,true);
    this->tableView_0->setColumnHidden(25,true);
    this->tableView_0->setColumnHidden(26,true);
    this->tableView_0->setColumnHidden(27,true);
    this->tableView_0->setColumnHidden(28,true);
    this->tableView_0->setColumnHidden(29,true);
    this->tableView_0->setColumnHidden(30,true);
    this->tableView_0->setColumnHidden(31,true);
    this->tableView_0->setColumnHidden(32,true);
    this->tableView_1->setColumnHidden(5,true);
    this->tableView_1->setColumnHidden(8,true);
    this->tableView_1->setColumnHidden(10,true);
    this->tableView_1->setColumnHidden(12,true);
    this->tableView_1->setColumnHidden(13,true);
    this->tableView_1->setColumnHidden(14,true);
    this->tableView_1->setColumnHidden(15,true);
    this->tableView_1->setColumnHidden(16,true);
    this->tableView_1->setColumnHidden(17,true);
    this->tableView_1->setColumnHidden(18,true);
    this->tableView_1->setColumnHidden(19,true);
    this->tableView_1->setColumnHidden(20,true);
    this->tableView_1->setColumnHidden(21,true);
    this->tableView_1->setColumnHidden(22,true);
    this->tableView_1->setColumnHidden(23,true);
    this->tableView_1->setColumnHidden(24,true);
    this->tableView_1->setColumnHidden(25,true);
    this->tableView_1->setColumnHidden(26,true);
    this->tableView_1->setColumnHidden(27,true);
    this->tableView_1->setColumnHidden(28,true);
    this->tableView_1->setColumnHidden(29,true);
    this->tableView_1->setColumnHidden(30,true);
    this->tableView_1->setColumnHidden(31,true);
    this->tableView_1->setColumnHidden(32,true);
    this->tableView_2->setColumnHidden(5,true);
    this->tableView_2->setColumnHidden(8,true);
    this->tableView_2->setColumnHidden(10,true);
    this->tableView_2->setColumnHidden(12,true);
    this->tableView_2->setColumnHidden(13,true);
    this->tableView_2->setColumnHidden(14,true);
    this->tableView_2->setColumnHidden(15,true);
    this->tableView_2->setColumnHidden(16,true);
    this->tableView_2->setColumnHidden(17,true);
    this->tableView_2->setColumnHidden(18,true);
    this->tableView_2->setColumnHidden(19,true);
    this->tableView_2->setColumnHidden(20,true);
    this->tableView_2->setColumnHidden(21,true);
    this->tableView_2->setColumnHidden(22,true);
    this->tableView_2->setColumnHidden(23,true);
    this->tableView_2->setColumnHidden(24,true);
    this->tableView_2->setColumnHidden(25,true);
    this->tableView_2->setColumnHidden(26,true);
    this->tableView_2->setColumnHidden(27,true);
    this->tableView_2->setColumnHidden(28,true);
    this->tableView_2->setColumnHidden(29,true);
    this->tableView_2->setColumnHidden(30,true);
    this->tableView_2->setColumnHidden(31,true);
    this->tableView_2->setColumnHidden(32,true);
    this->tableView_0->resizeColumnsToContents();
    this->tableView_1->resizeColumnsToContents();
    this->tableView_2->resizeColumnsToContents();

    this->tableView_0->setSelectionMode(QTableView::SingleSelection);
    this->tableView_0->setSelectionBehavior(QTableView::SelectRows);
    this->tableView_0->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->tableView_1->setSelectionMode(QTableView::SingleSelection);
    this->tableView_1->setSelectionBehavior(QTableView::SelectRows);
    this->tableView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->tableView_2->setSelectionMode(QTableView::SingleSelection);
    this->tableView_2->setSelectionBehavior(QTableView::SelectRows);
    this->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);



    connect(this->actionYuangongGuanli, SIGNAL(triggered()), this, SLOT(on_actionYuangongGuanli_triggerd()));
    connect(this->actionQuanxianzuGuanli, SIGNAL(triggered()), this, SLOT(on_actionQuanxianzuGuanli_triggered()));
    connect(this->actionCanshuShezhi, SIGNAL(triggered()), this, SLOT(on_actionCanshuShezhi_triggerd()));

    connect(this->addPushButton_0, SIGNAL(clicked()), this, SLOT(on_actionTianjiaFangyuan_triggered()));
    connect(this->addPushButton_1, SIGNAL(clicked()), this, SLOT(on_actionTianjiaFangyuan_triggered()));
    connect(this->addPushButton_2, SIGNAL(clicked()), this, SLOT(on_actionTianjiaFangyuan_triggered()));

    connect(this->modifyPushButton_0, SIGNAL(clicked()), this, SLOT(on_modifyPushButton_0_triggerd()));
    connect(this->modifyPushButton_1, SIGNAL(clicked()), this, SLOT(on_modifyPushButton_0_triggerd()));
    connect(this->modifyPushButton_2, SIGNAL(clicked()), this, SLOT(on_modifyPushButton_0_triggerd()));

    connect(this->deletePushButton_0, SIGNAL(clicked()), this,  SLOT(on_deletePushButton_0_triggerd()));
    connect(this->deletePushButton_1, SIGNAL(clicked()), this,  SLOT(on_deletePushButton_0_triggerd()));
    connect(this->deletePushButton_2, SIGNAL(clicked()), this,  SLOT(on_deletePushButton_0_triggerd()));
    //
    //    connect(this->tableView_1, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tableView_0_clicked()));
    //    connect(this->tableView_1, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tableView_0_clicked()));

    this->tableView_0->selectRow(0);
    this->tableView_1->selectRow(0);
    this->tableView_2->selectRow(0);
    this->on_tableView_0_clicked();
    //this->tableView_0->
}

MainWindow::~MainWindow()
{
    free(this->xitongShezhiMenu);
}

void MainWindow::on_actionXitongShezhi_triggered()
{
    this->xitongShezhiMenu->popup(QCursor::pos());
}

void MainWindow::on_actionRuanjianBangzhu_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionTuichuXitong_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionYuangongGuanli_triggerd()
{
    YuangongGuanliDialog yuangongGuanliDialog(this, this->dbcon);
    yuangongGuanliDialog.exec();
}

void MainWindow::on_actionQuanxianzuGuanli_triggered()
{
    QuanxianzuGuanliDialog quanxianzuGuanliDialog(0,this->dbcon);
    quanxianzuGuanliDialog.exec();
}

void MainWindow::on_actionCanshuShezhi_triggerd()
{
    CanshuGuanliDialog canshuGuanliDialog(0, this->dbcon);
    canshuGuanliDialog.exec();
}

void MainWindow::on_taskTreeWidget_itemActivated(QTreeWidgetItem *item, int column)
{
    //qDebug() << item->text(0);
    QString * itemText = &(item->text(0));
    if(*itemText == tr("出售房源") ){
        this->stackedWidget->setCurrentIndex(0);
    }else if(*itemText == tr("出租房源")){
        this->stackedWidget->setCurrentIndex(1);
    }else if(*itemText == tr("合租房源")){
        this->stackedWidget->setCurrentIndex(2);
    }else if(*itemText == tr("求购信息")){
        this->stackedWidget->setCurrentIndex(3);
    }else if(*itemText == tr("求租信息")){
        this->stackedWidget->setCurrentIndex(4);
    }else if(*itemText == tr("求合租信息")){
        this->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_stackedWidget_currentChanged(int index)
{
    qDebug() << "current index " << index;
    this->on_tableView_0_clicked();
}

void MainWindow::on_actionTianjiaFangyuan_triggered()
{
    FangyuanDialog fangyuanDialog(this, this->dbcon);
    switch(this->stackedWidget->currentIndex()){
    case 0:
        fangyuanDialog.fangyuanLeixingComboBox->setCurrentIndex(0);
        fangyuanDialog.fangyuanLeixingComboBox->setEnabled(false);
        if(fangyuanDialog.exec() == QDialog::Accepted){
            dbcon->insertChushouFangyuan(fangyuanDialog.fangwuBianhaoSpinBox->text().toInt(),
                                         fangyuanDialog.dangqianZhuangtaiComboBox->currentText(),
                                         fangyuanDialog.zhiyeGuwenComboBox->currentText(),
                                         fangyuanDialog.fangwuLaiyuanComboBox->currentText(),
                                         fangyuanDialog.suozaiChengquComboBox->currentText(),
                                         fangyuanDialog.fangwuJiageSpinBox->text().toInt(),
                                         fangyuanDialog.fangwuLeixingComboBox->currentText(),
                                         fangyuanDialog.chanquanXingbieComboBox->currentText(),
                                         fangyuanDialog.fangwuMianjiDoubleSpinBox->text().toFloat(),
                                         fangyuanDialog.jianchengNiandaiSpinBox->text().toInt(),
                                         fangyuanDialog.suozaiLoucengSpinBox->text().toInt(),
                                         fangyuanDialog.zhuangxiuBiaozhunComboBox->currentText(),
                                         fangyuanDialog.loucengZongshuSpinBox->text().toInt(),
                                         fangyuanDialog.jutiDizhiLineEdit->text(),
                                         fangyuanDialog.chufangCheckBox->isChecked(),
                                         fangyuanDialog.chuangCheckBox->isChecked(),
                                         fangyuanDialog.jiajuCheckBox->isChecked(),
                                         fangyuanDialog.youxianDianshiCheckBox->isChecked(),
                                         fangyuanDialog.kuaidaiwangCheckBox->isChecked(),
                                         fangyuanDialog.dianhuaCheckBox->isChecked(),
                                         fangyuanDialog.reshuiqiCheckBox->isChecked(),
                                         fangyuanDialog.dianshijiCheckBox->isChecked(),
                                         fangyuanDialog.kongtiaoCheckBox->isChecked(),
                                         fangyuanDialog.xiyijiCheckBox->isChecked(),
                                         fangyuanDialog.bingxiangCheckBox->isChecked(),
                                         fangyuanDialog.meiqiCheckBox->isChecked(),
                                         fangyuanDialog.nuanqiCheckBox->isChecked(),
                                         fangyuanDialog.qichekuCheckBox->isChecked(),
                                         fangyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->toPlainText(),
                                         fangyuanDialog.yezhuXingmingLineEdit->text(),
                                         fangyuanDialog.lianxiDianhuaLineEdit->text(),
                                         fangyuanDialog.lianxiShoujiLineEdit->text(),
                                         fangyuanDialog.yezhuShuomingLineEdit->text());
        }
        this->dbcon->chushoufangyuan->select();
        break;

        case 1:
        fangyuanDialog.fangyuanLeixingComboBox->setCurrentIndex(1);
        fangyuanDialog.fangyuanLeixingComboBox->setEnabled(false);
        if(fangyuanDialog.exec() == QDialog::Accepted){
            dbcon->insertChuzuFangyuan(fangyuanDialog.fangwuBianhaoSpinBox->text().toInt(),
                                       fangyuanDialog.dangqianZhuangtaiComboBox->currentText(),
                                       fangyuanDialog.zhiyeGuwenComboBox->currentText(),
                                       fangyuanDialog.fangwuLaiyuanComboBox->currentText(),
                                       fangyuanDialog.suozaiChengquComboBox->currentText(),
                                       fangyuanDialog.fangwuJiageSpinBox->text().toInt(),
                                       fangyuanDialog.fangwuLeixingComboBox->currentText(),
                                       fangyuanDialog.chanquanXingbieComboBox->currentText(),
                                       fangyuanDialog.fangwuMianjiDoubleSpinBox->text().toFloat(),
                                       fangyuanDialog.jianchengNiandaiSpinBox->text().toInt(),
                                       fangyuanDialog.suozaiLoucengSpinBox->text().toInt(),
                                       fangyuanDialog.zhuangxiuBiaozhunComboBox->currentText(),
                                       fangyuanDialog.loucengZongshuSpinBox->text().toInt(),
                                       fangyuanDialog.jutiDizhiLineEdit->text(),
                                       fangyuanDialog.chufangCheckBox->isChecked(),
                                       fangyuanDialog.chuangCheckBox->isChecked(),
                                       fangyuanDialog.jiajuCheckBox->isChecked(),
                                       fangyuanDialog.youxianDianshiCheckBox->isChecked(),
                                       fangyuanDialog.kuaidaiwangCheckBox->isChecked(),
                                       fangyuanDialog.dianhuaCheckBox->isChecked(),
                                       fangyuanDialog.reshuiqiCheckBox->isChecked(),
                                       fangyuanDialog.dianshijiCheckBox->isChecked(),
                                       fangyuanDialog.kongtiaoCheckBox->isChecked(),
                                       fangyuanDialog.xiyijiCheckBox->isChecked(),
                                       fangyuanDialog.bingxiangCheckBox->isChecked(),
                                       fangyuanDialog.meiqiCheckBox->isChecked(),
                                       fangyuanDialog.nuanqiCheckBox->isChecked(),
                                       fangyuanDialog.qichekuCheckBox->isChecked(),
                                       fangyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->toPlainText(),
                                       fangyuanDialog.yezhuXingmingLineEdit->text(),
                                       fangyuanDialog.lianxiDianhuaLineEdit->text(),
                                       fangyuanDialog.lianxiShoujiLineEdit->text(),
                                       fangyuanDialog.yezhuShuomingLineEdit->text());
        }
        this->dbcon->chuzufangyuan->select();
        break;
        case 2:

        fangyuanDialog.fangyuanLeixingComboBox->setCurrentIndex(2);
        fangyuanDialog.fangyuanLeixingComboBox->setEnabled(false);
        fangyuanDialog.asHezu();
        if(fangyuanDialog.exec() == QDialog::Accepted){
            dbcon->insertHezuFangyuan(fangyuanDialog.fangwuBianhaoSpinBox->text().toInt(),
                                      fangyuanDialog.dangqianZhuangtaiComboBox->currentText(),
                                      fangyuanDialog.zhiyeGuwenComboBox->currentText(),
                                      fangyuanDialog.fangwuLaiyuanComboBox->currentText(),
                                      fangyuanDialog.suozaiChengquComboBox->currentText(),
                                      fangyuanDialog.fangwuJiageSpinBox->text().toInt(),
                                      fangyuanDialog.fangwuLeixingComboBox->currentText(),
                                      fangyuanDialog.chanquanXingbieComboBox->currentText(),
                                      fangyuanDialog.fangwuMianjiDoubleSpinBox->text().toFloat(),
                                      fangyuanDialog.jianchengNiandaiSpinBox->text().toInt(),
                                      fangyuanDialog.suozaiLoucengSpinBox->text().toInt(),
                                      fangyuanDialog.zhuangxiuBiaozhunComboBox->currentText(),
                                      fangyuanDialog.loucengZongshuSpinBox->text().toInt(),
                                      fangyuanDialog.jutiDizhiLineEdit->text(),
                                      fangyuanDialog.chufangCheckBox->isChecked(),
                                      fangyuanDialog.chuangCheckBox->isChecked(),
                                      fangyuanDialog.jiajuCheckBox->isChecked(),
                                      fangyuanDialog.youxianDianshiCheckBox->isChecked(),
                                      fangyuanDialog.kuaidaiwangCheckBox->isChecked(),
                                      fangyuanDialog.dianhuaCheckBox->isChecked(),
                                      fangyuanDialog.reshuiqiCheckBox->isChecked(),
                                      fangyuanDialog.dianshijiCheckBox->isChecked(),
                                      fangyuanDialog.kongtiaoCheckBox->isChecked(),
                                      fangyuanDialog.xiyijiCheckBox->isChecked(),
                                      fangyuanDialog.bingxiangCheckBox->isChecked(),
                                      fangyuanDialog.meiqiCheckBox->isChecked(),
                                      fangyuanDialog.nuanqiCheckBox->isChecked(),
                                      fangyuanDialog.qichekuCheckBox->isChecked(),
                                      fangyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->toPlainText(),
                                      fangyuanDialog.yezhuXingmingLineEdit->text(),
                                      fangyuanDialog.lianxiDianhuaLineEdit->text(),
                                      fangyuanDialog.lianxiShoujiLineEdit->text(),
                                      fangyuanDialog.yezhuShuomingLineEdit->text());
        }
        this->dbcon->hezufangyuan->select();
        break;
    }

}

void MainWindow::on_modifyPushButton_0_triggerd()
{
    qDebug() << "modify";

    int fangwubianhao, fangwujiage, jianzhuniandai, suozailouceng, loucengzongshu;
    QString dangqianzhuangtai, zhiyeguwen, fangwulaiyuan, suozaichengqu, fangwuleixing, chanquanxingbie,zhuangxiubiaozhun, jutidizhi, fangyuanxiangxixinxi, yezhuxingming, lianxidianghua, lianxishouji, yezhushuoming;
    bool a, b, c, d, e, f, g, h, i, j, k, l, m, n;
    float fangwumianji;
    FangyuanDialog fangyuanDialog(this, this->dbcon);
    QComboBox * combo;
    switch(this->stackedWidget->currentIndex())
    {
    case 0:

        fangyuanDialog.fangyuanLeixingComboBox->setCurrentIndex(0);
        fangyuanDialog.asChushouChuzu();
        this->tableView_0->selectRow(this->tableView_0->currentIndex().row());
        fangwubianhao = this->tableView_0->currentIndex().data().toInt();
        this->dbcon->getChushouFangyuan(fangwubianhao, &dangqianzhuangtai, &zhiyeguwen, &fangwulaiyuan, &suozaichengqu,&fangwujiage, &fangwuleixing, &chanquanxingbie, &fangwumianji, & jianzhuniandai, &suozailouceng, &zhuangxiubiaozhun, &loucengzongshu, &jutidizhi,
                                        &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &fangyuanxiangxixinxi,&yezhuxingming, &lianxidianghua, &lianxishouji, & yezhushuoming);
        fangyuanDialog.fangwuBianhaoSpinBox->setValue(fangwubianhao);
        fangyuanDialog.fangwuBianhaoSpinBox->setEnabled(false);
        fangyuanDialog.fangyuanLeixingComboBox->setEnabled(false);
        combo = fangyuanDialog.dangqianZhuangtaiComboBox;
        combo ->setCurrentIndex(combo->findText(dangqianzhuangtai));
        combo = fangyuanDialog.zhiyeGuwenComboBox;
        combo ->setCurrentIndex(combo->findText(zhiyeguwen));
        combo = fangyuanDialog.fangwuLaiyuanComboBox;
        combo ->setCurrentIndex(combo->findText(fangwulaiyuan));
        combo = fangyuanDialog.suozaiChengquComboBox;
        combo ->setCurrentIndex(combo->findText(suozaichengqu));
        combo = fangyuanDialog.fangwuLeixingComboBox;
        combo ->setCurrentIndex(combo->findText(fangwuleixing));
        combo = fangyuanDialog.chanquanXingbieComboBox;
        combo ->setCurrentIndex(combo->findText(chanquanxingbie));
        combo = fangyuanDialog.zhuangxiuBiaozhunComboBox;
        combo ->setCurrentIndex(combo->findText(zhuangxiubiaozhun));

        fangyuanDialog.fangwuJiageSpinBox->setValue(fangwujiage);
        fangyuanDialog.fangwuMianjiDoubleSpinBox->setValue(fangwumianji);
        fangyuanDialog.jianchengNiandaiSpinBox->setValue(jianzhuniandai);
        fangyuanDialog.suozaiLoucengSpinBox->setValue(suozailouceng);
        fangyuanDialog.loucengZongshuSpinBox->setValue(loucengzongshu);
        fangyuanDialog.jutiDizhiLineEdit->setText(jutidizhi);

        if(a)
            fangyuanDialog.chufangCheckBox->setCheckState(Qt::Checked);
        if(b)
            fangyuanDialog.chuangCheckBox->setCheckState(Qt::Checked);
        if(c)
            fangyuanDialog.jiajuCheckBox->setCheckState(Qt::Checked);
        if(d)
            fangyuanDialog.youxianDianshiCheckBox->setCheckState(Qt::Checked);
        if(e)
            fangyuanDialog.kuaidaiwangCheckBox->setCheckState(Qt::Checked);
        if(f)
            fangyuanDialog.dianhuaCheckBox->setCheckState(Qt::Checked);
        if(g)
            fangyuanDialog.reshuiqiCheckBox->setCheckState(Qt::Checked);
        if(h)
            fangyuanDialog.dianshijiCheckBox->setCheckState(Qt::Checked);
        if(i)
            fangyuanDialog.kongtiaoCheckBox->setCheckState(Qt::Checked);
        if(j)
            fangyuanDialog.xiyijiCheckBox->setCheckState(Qt::Checked);
        if(k)
            fangyuanDialog.bingxiangCheckBox->setCheckState(Qt::Checked);
        if(l)
            fangyuanDialog.meiqiCheckBox->setCheckState(Qt::Checked);
        if(m)
            fangyuanDialog.nuanqiCheckBox->setCheckState(Qt::Checked);
        if(n)
            fangyuanDialog.qichekuCheckBox->setCheckState(Qt::Checked);

        fangyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->setPlainText(fangyuanxiangxixinxi);
        fangyuanDialog.yezhuXingmingLineEdit->setText(yezhuxingming);
        fangyuanDialog.lianxiDianhuaLineEdit->setText(lianxidianghua);
        fangyuanDialog.lianxiShoujiLineEdit->setText(lianxishouji);
        fangyuanDialog.yezhuShuomingLineEdit->setText(yezhushuoming);
        if(fangyuanDialog.exec() == QDialog::Accepted){
            dbcon->insertChushouFangyuan(fangyuanDialog.fangwuBianhaoSpinBox->text().toInt(),
                                         fangyuanDialog.dangqianZhuangtaiComboBox->currentText(),
                                         fangyuanDialog.zhiyeGuwenComboBox->currentText(),
                                         fangyuanDialog.fangwuLaiyuanComboBox->currentText(),
                                         fangyuanDialog.suozaiChengquComboBox->currentText(),
                                         fangyuanDialog.fangwuJiageSpinBox->text().toInt(),
                                         fangyuanDialog.fangwuLeixingComboBox->currentText(),
                                         fangyuanDialog.chanquanXingbieComboBox->currentText(),
                                         fangyuanDialog.fangwuMianjiDoubleSpinBox->text().toFloat(),
                                         fangyuanDialog.jianchengNiandaiSpinBox->text().toInt(),
                                         fangyuanDialog.suozaiLoucengSpinBox->text().toInt(),
                                         fangyuanDialog.zhuangxiuBiaozhunComboBox->currentText(),
                                         fangyuanDialog.loucengZongshuSpinBox->text().toInt(),
                                         fangyuanDialog.jutiDizhiLineEdit->text(),
                                         fangyuanDialog.chufangCheckBox->isChecked(),
                                         fangyuanDialog.chuangCheckBox->isChecked(),
                                         fangyuanDialog.jiajuCheckBox->isChecked(),
                                         fangyuanDialog.youxianDianshiCheckBox->isChecked(),
                                         fangyuanDialog.kuaidaiwangCheckBox->isChecked(),
                                         fangyuanDialog.dianhuaCheckBox->isChecked(),
                                         fangyuanDialog.reshuiqiCheckBox->isChecked(),
                                         fangyuanDialog.dianshijiCheckBox->isChecked(),
                                         fangyuanDialog.kongtiaoCheckBox->isChecked(),
                                         fangyuanDialog.xiyijiCheckBox->isChecked(),
                                         fangyuanDialog.bingxiangCheckBox->isChecked(),
                                         fangyuanDialog.meiqiCheckBox->isChecked(),
                                         fangyuanDialog.nuanqiCheckBox->isChecked(),
                                         fangyuanDialog.qichekuCheckBox->isChecked(),
                                         fangyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->toPlainText(),
                                         fangyuanDialog.yezhuXingmingLineEdit->text(),
                                         fangyuanDialog.lianxiDianhuaLineEdit->text(),
                                         fangyuanDialog.lianxiShoujiLineEdit->text(),
                                         fangyuanDialog.yezhuShuomingLineEdit->text());
        }
        this->dbcon->chushoufangyuan->select();
        break;

        case 1:

        fangyuanDialog.fangyuanLeixingComboBox->setCurrentIndex(1);
        fangyuanDialog.asChushouChuzu();
        this->tableView_1->selectRow(this->tableView_1->currentIndex().row());
        fangwubianhao = this->tableView_1->currentIndex().data().toInt();
        this->dbcon->getChuzuFangyuan(fangwubianhao, &dangqianzhuangtai, &zhiyeguwen, &fangwulaiyuan, &suozaichengqu,&fangwujiage, &fangwuleixing, &chanquanxingbie, &fangwumianji, & jianzhuniandai, &suozailouceng, &zhuangxiubiaozhun, &loucengzongshu, &jutidizhi,
                                      &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &fangyuanxiangxixinxi,&yezhuxingming, &lianxidianghua, &lianxishouji, & yezhushuoming);
        fangyuanDialog.fangwuBianhaoSpinBox->setValue(fangwubianhao);
        fangyuanDialog.fangwuBianhaoSpinBox->setEnabled(false);
        fangyuanDialog.fangyuanLeixingComboBox->setEnabled(false);
        combo = fangyuanDialog.dangqianZhuangtaiComboBox;
        combo ->setCurrentIndex(combo->findText(dangqianzhuangtai));
        combo = fangyuanDialog.zhiyeGuwenComboBox;
        combo ->setCurrentIndex(combo->findText(zhiyeguwen));
        combo = fangyuanDialog.fangwuLaiyuanComboBox;
        combo ->setCurrentIndex(combo->findText(fangwulaiyuan));
        combo = fangyuanDialog.suozaiChengquComboBox;
        combo ->setCurrentIndex(combo->findText(suozaichengqu));
        combo = fangyuanDialog.fangwuLeixingComboBox;
        combo ->setCurrentIndex(combo->findText(fangwuleixing));
        combo = fangyuanDialog.chanquanXingbieComboBox;
        combo ->setCurrentIndex(combo->findText(chanquanxingbie));
        combo = fangyuanDialog.zhuangxiuBiaozhunComboBox;
        combo ->setCurrentIndex(combo->findText(zhuangxiubiaozhun));

        fangyuanDialog.fangwuJiageSpinBox->setValue(fangwujiage);
        fangyuanDialog.fangwuMianjiDoubleSpinBox->setValue(fangwumianji);
        fangyuanDialog.jianchengNiandaiSpinBox->setValue(jianzhuniandai);
        fangyuanDialog.suozaiLoucengSpinBox->setValue(suozailouceng);
        fangyuanDialog.loucengZongshuSpinBox->setValue(loucengzongshu);
        fangyuanDialog.jutiDizhiLineEdit->setText(jutidizhi);

        if(a)
            fangyuanDialog.chufangCheckBox->setCheckState(Qt::Checked);
        if(b)
            fangyuanDialog.chuangCheckBox->setCheckState(Qt::Checked);
        if(c)
            fangyuanDialog.jiajuCheckBox->setCheckState(Qt::Checked);
        if(d)
            fangyuanDialog.youxianDianshiCheckBox->setCheckState(Qt::Checked);
        if(e)
            fangyuanDialog.kuaidaiwangCheckBox->setCheckState(Qt::Checked);
        if(f)
            fangyuanDialog.dianhuaCheckBox->setCheckState(Qt::Checked);
        if(g)
            fangyuanDialog.reshuiqiCheckBox->setCheckState(Qt::Checked);
        if(h)
            fangyuanDialog.dianshijiCheckBox->setCheckState(Qt::Checked);
        if(i)
            fangyuanDialog.kongtiaoCheckBox->setCheckState(Qt::Checked);
        if(j)
            fangyuanDialog.xiyijiCheckBox->setCheckState(Qt::Checked);
        if(k)
            fangyuanDialog.bingxiangCheckBox->setCheckState(Qt::Checked);
        if(l)
            fangyuanDialog.meiqiCheckBox->setCheckState(Qt::Checked);
        if(m)
            fangyuanDialog.nuanqiCheckBox->setCheckState(Qt::Checked);
        if(n)
            fangyuanDialog.qichekuCheckBox->setCheckState(Qt::Checked);

        fangyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->setPlainText(fangyuanxiangxixinxi);
        fangyuanDialog.yezhuXingmingLineEdit->setText(yezhuxingming);
        fangyuanDialog.lianxiDianhuaLineEdit->setText(lianxidianghua);
        fangyuanDialog.lianxiShoujiLineEdit->setText(lianxishouji);
        fangyuanDialog.yezhuShuomingLineEdit->setText(yezhushuoming);
        if(fangyuanDialog.exec() == QDialog::Accepted){
            dbcon->insertChuzuFangyuan(fangyuanDialog.fangwuBianhaoSpinBox->text().toInt(),
                                       fangyuanDialog.dangqianZhuangtaiComboBox->currentText(),
                                       fangyuanDialog.zhiyeGuwenComboBox->currentText(),
                                       fangyuanDialog.fangwuLaiyuanComboBox->currentText(),
                                       fangyuanDialog.suozaiChengquComboBox->currentText(),
                                       fangyuanDialog.fangwuJiageSpinBox->text().toInt(),
                                       fangyuanDialog.fangwuLeixingComboBox->currentText(),
                                       fangyuanDialog.chanquanXingbieComboBox->currentText(),
                                       fangyuanDialog.fangwuMianjiDoubleSpinBox->text().toFloat(),
                                       fangyuanDialog.jianchengNiandaiSpinBox->text().toInt(),
                                       fangyuanDialog.suozaiLoucengSpinBox->text().toInt(),
                                       fangyuanDialog.zhuangxiuBiaozhunComboBox->currentText(),
                                       fangyuanDialog.loucengZongshuSpinBox->text().toInt(),
                                       fangyuanDialog.jutiDizhiLineEdit->text(),
                                       fangyuanDialog.chufangCheckBox->isChecked(),
                                       fangyuanDialog.chuangCheckBox->isChecked(),
                                       fangyuanDialog.jiajuCheckBox->isChecked(),
                                       fangyuanDialog.youxianDianshiCheckBox->isChecked(),
                                       fangyuanDialog.kuaidaiwangCheckBox->isChecked(),
                                       fangyuanDialog.dianhuaCheckBox->isChecked(),
                                       fangyuanDialog.reshuiqiCheckBox->isChecked(),
                                       fangyuanDialog.dianshijiCheckBox->isChecked(),
                                       fangyuanDialog.kongtiaoCheckBox->isChecked(),
                                       fangyuanDialog.xiyijiCheckBox->isChecked(),
                                       fangyuanDialog.bingxiangCheckBox->isChecked(),
                                       fangyuanDialog.meiqiCheckBox->isChecked(),
                                       fangyuanDialog.nuanqiCheckBox->isChecked(),
                                       fangyuanDialog.qichekuCheckBox->isChecked(),
                                       fangyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->toPlainText(),
                                       fangyuanDialog.yezhuXingmingLineEdit->text(),
                                       fangyuanDialog.lianxiDianhuaLineEdit->text(),
                                       fangyuanDialog.lianxiShoujiLineEdit->text(),
                                       fangyuanDialog.yezhuShuomingLineEdit->text());
        }
        this->dbcon->chuzufangyuan->select();

        break;

        case 2:

        fangyuanDialog.fangyuanLeixingComboBox->setCurrentIndex(2);
        fangyuanDialog.asHezu();
        this->tableView_2->selectRow(this->tableView_2->currentIndex().row());
        fangwubianhao = this->tableView_2->currentIndex().data().toInt();
        this->dbcon->getHezuFangyuan(fangwubianhao, &dangqianzhuangtai, &zhiyeguwen, &fangwulaiyuan, &suozaichengqu,&fangwujiage, &fangwuleixing, &chanquanxingbie, &fangwumianji, & jianzhuniandai, &suozailouceng, &zhuangxiubiaozhun, &loucengzongshu, &jutidizhi,
                                     &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &fangyuanxiangxixinxi,&yezhuxingming, &lianxidianghua, &lianxishouji, & yezhushuoming);
        fangyuanDialog.fangwuBianhaoSpinBox->setValue(fangwubianhao);
        fangyuanDialog.fangwuBianhaoSpinBox->setEnabled(false);
        fangyuanDialog.fangyuanLeixingComboBox->setEnabled(false);
        combo = fangyuanDialog.dangqianZhuangtaiComboBox;
        combo ->setCurrentIndex(combo->findText(dangqianzhuangtai));
        combo = fangyuanDialog.zhiyeGuwenComboBox;
        combo ->setCurrentIndex(combo->findText(zhiyeguwen));
        combo = fangyuanDialog.fangwuLaiyuanComboBox;
        combo ->setCurrentIndex(combo->findText(fangwulaiyuan));
        combo = fangyuanDialog.suozaiChengquComboBox;
        combo ->setCurrentIndex(combo->findText(suozaichengqu));
        combo = fangyuanDialog.fangwuLeixingComboBox;
        combo ->setCurrentIndex(combo->findText(fangwuleixing));
        combo = fangyuanDialog.chanquanXingbieComboBox;
        combo ->setCurrentIndex(combo->findText(chanquanxingbie));
        combo = fangyuanDialog.zhuangxiuBiaozhunComboBox;
        combo ->setCurrentIndex(combo->findText(zhuangxiubiaozhun));

        fangyuanDialog.fangwuJiageSpinBox->setValue(fangwujiage);
        fangyuanDialog.fangwuMianjiDoubleSpinBox->setValue(fangwumianji);
        fangyuanDialog.jianchengNiandaiSpinBox->setValue(jianzhuniandai);
        fangyuanDialog.suozaiLoucengSpinBox->setValue(suozailouceng);
        fangyuanDialog.loucengZongshuSpinBox->setValue(loucengzongshu);
        fangyuanDialog.jutiDizhiLineEdit->setText(jutidizhi);

        if(a)
            fangyuanDialog.chufangCheckBox->setCheckState(Qt::Checked);
        if(b)
            fangyuanDialog.chuangCheckBox->setCheckState(Qt::Checked);
        if(c)
            fangyuanDialog.jiajuCheckBox->setCheckState(Qt::Checked);
        if(d)
            fangyuanDialog.youxianDianshiCheckBox->setCheckState(Qt::Checked);
        if(e)
            fangyuanDialog.kuaidaiwangCheckBox->setCheckState(Qt::Checked);
        if(f)
            fangyuanDialog.dianhuaCheckBox->setCheckState(Qt::Checked);
        if(g)
            fangyuanDialog.reshuiqiCheckBox->setCheckState(Qt::Checked);
        if(h)
            fangyuanDialog.dianshijiCheckBox->setCheckState(Qt::Checked);
        if(i)
            fangyuanDialog.kongtiaoCheckBox->setCheckState(Qt::Checked);
        if(j)
            fangyuanDialog.xiyijiCheckBox->setCheckState(Qt::Checked);
        if(k)
            fangyuanDialog.bingxiangCheckBox->setCheckState(Qt::Checked);
        if(l)
            fangyuanDialog.meiqiCheckBox->setCheckState(Qt::Checked);
        if(m)
            fangyuanDialog.nuanqiCheckBox->setCheckState(Qt::Checked);
        if(n)
            fangyuanDialog.qichekuCheckBox->setCheckState(Qt::Checked);

        fangyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->setPlainText(fangyuanxiangxixinxi);
        fangyuanDialog.yezhuXingmingLineEdit->setText(yezhuxingming);
        fangyuanDialog.lianxiDianhuaLineEdit->setText(lianxidianghua);
        fangyuanDialog.lianxiShoujiLineEdit->setText(lianxishouji);
        fangyuanDialog.yezhuShuomingLineEdit->setText(yezhushuoming);
        if(fangyuanDialog.exec() == QDialog::Accepted){
            dbcon->insertHezuFangyuan(fangyuanDialog.fangwuBianhaoSpinBox->text().toInt(),
                                      fangyuanDialog.dangqianZhuangtaiComboBox->currentText(),
                                      fangyuanDialog.zhiyeGuwenComboBox->currentText(),
                                      fangyuanDialog.fangwuLaiyuanComboBox->currentText(),
                                      fangyuanDialog.suozaiChengquComboBox->currentText(),
                                      fangyuanDialog.fangwuJiageSpinBox->text().toInt(),
                                      fangyuanDialog.fangwuLeixingComboBox->currentText(),
                                      fangyuanDialog.chanquanXingbieComboBox->currentText(),
                                      fangyuanDialog.fangwuMianjiDoubleSpinBox->text().toFloat(),
                                      fangyuanDialog.jianchengNiandaiSpinBox->text().toInt(),
                                      fangyuanDialog.suozaiLoucengSpinBox->text().toInt(),
                                      fangyuanDialog.zhuangxiuBiaozhunComboBox->currentText(),
                                      fangyuanDialog.loucengZongshuSpinBox->text().toInt(),
                                      fangyuanDialog.jutiDizhiLineEdit->text(),
                                      fangyuanDialog.chufangCheckBox->isChecked(),
                                      fangyuanDialog.chuangCheckBox->isChecked(),
                                      fangyuanDialog.jiajuCheckBox->isChecked(),
                                      fangyuanDialog.youxianDianshiCheckBox->isChecked(),
                                      fangyuanDialog.kuaidaiwangCheckBox->isChecked(),
                                      fangyuanDialog.dianhuaCheckBox->isChecked(),
                                      fangyuanDialog.reshuiqiCheckBox->isChecked(),
                                      fangyuanDialog.dianshijiCheckBox->isChecked(),
                                      fangyuanDialog.kongtiaoCheckBox->isChecked(),
                                      fangyuanDialog.xiyijiCheckBox->isChecked(),
                                      fangyuanDialog.bingxiangCheckBox->isChecked(),
                                      fangyuanDialog.meiqiCheckBox->isChecked(),
                                      fangyuanDialog.nuanqiCheckBox->isChecked(),
                                      fangyuanDialog.qichekuCheckBox->isChecked(),
                                      fangyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->toPlainText(),
                                      fangyuanDialog.yezhuXingmingLineEdit->text(),
                                      fangyuanDialog.lianxiDianhuaLineEdit->text(),
                                      fangyuanDialog.lianxiShoujiLineEdit->text(),
                                      fangyuanDialog.yezhuShuomingLineEdit->text());
        }
        this->dbcon->hezufangyuan->select();

        break;

    }
}

void MainWindow::on_deletePushButton_0_triggerd()
{
    int fangwubianhao;
    switch(this->stackedWidget->currentIndex())
    {
    case 0:

        this->tableView_0->selectRow(this->tableView_0->currentIndex().row());
        fangwubianhao = this->tableView_0->currentIndex().data().toInt();
        this->dbcon->deleteFromChushoufangyuan(fangwubianhao);
        this->dbcon->chushoufangyuan->select();
        break;
    case 1:
        this->tableView_1->selectRow(this->tableView_1->currentIndex().row());
        fangwubianhao = this->tableView_1->currentIndex().data().toInt();
        this->dbcon->deleteFromChuzufangyuan(fangwubianhao);
        this->dbcon->chuzufangyuan->select();
        break;
    case 2:

        this->tableView_2->selectRow(this->tableView_2->currentIndex().row());
        fangwubianhao = this->tableView_2->currentIndex().data().toInt();
        this->dbcon->deleteFromHezufangyuan(fangwubianhao);
        this->dbcon->hezufangyuan->select();
        break;

    }
}

void MainWindow::on_actionTianjiaKehu_triggered()
{
    KeyuanDialog keyuanDialog(this, this->dbcon);
    keyuanDialog.exec();
}

void MainWindow::on_tableView_0_clicked(){//set tabWidget data;
    qDebug() << "clicked";
    int fangwubianhao, fangwujiage, jianzhuniandai, suozailouceng, loucengzongshu;
    QString dangqianzhuangtai, zhiyeguwen, fangwulaiyuan, suozaichengqu, fangwuleixing, chanquanxingbie,zhuangxiubiaozhun, jutidizhi, fangyuanxiangxixinxi, yezhuxingming, lianxidianghua, lianxishouji, yezhushuoming;
    bool a, b, c, d, e, f, g, h, i, j, k, l, m, n;
    float fangwumianji;
    QString str;
    switch(this->stackedWidget->currentIndex())
    {
    case 0:
        this->tableView_0->selectRow(this->tableView_0->currentIndex().row());
        fangwubianhao = this->tableView_0->currentIndex().data().toInt();

        this->dbcon->getChushouFangyuan(fangwubianhao, &dangqianzhuangtai, &zhiyeguwen, &fangwulaiyuan, &suozaichengqu,&fangwujiage, &fangwuleixing, &chanquanxingbie, &fangwumianji, & jianzhuniandai, &suozailouceng, &zhuangxiubiaozhun, &loucengzongshu, &jutidizhi,
                                        &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &fangyuanxiangxixinxi,&yezhuxingming, &lianxidianghua, &lianxishouji, & yezhushuoming);
        this->jiageLabel_0->setText(str.setNum(fangwujiage));
        this->mianjiLabel_0->setText(str.setNum(fangwumianji));
        this->chufangLabel_0->setVisible(a);
        this->chuangLabel_0->setVisible(b);
        this->jiajuLabel_0->setVisible(c);
        this->youxianLabel_0->setVisible(d);
        this->kuandaiLabel_0->setVisible(e);
        this->dianhuaLabel_0->setVisible(f);
        this->reshuiqiLabel_0->setVisible(g);
        this->dianshiLabel_0->setVisible(h);
        this->kongtiaoLabel_0->setVisible(i);
        this->xiyijiLabel_0->setVisible(j);
        this->bingxiangLabel_0->setVisible(k);
        this->meiqiLabel_0->setVisible(l);
        this->nuanqiLabel_0->setVisible(m);
        this->chekuLabel_0->setVisible(n);
        this->dizhiLabel_0->setText(jutidizhi);

        this->xingmingLabel_0->setText(yezhuxingming);
        this->lianxiDianhuaLabel_0->setText(lianxidianghua);
        this->shoujiLabel_0->setText(lianxishouji);
        this->beizhuLabel_0->setText(yezhushuoming);

        break;
    case 1:
        this->tableView_1->selectRow(this->tableView_1->currentIndex().row());
        fangwubianhao = this->tableView_1->currentIndex().data().toInt();

        this->dbcon->getChuzuFangyuan(fangwubianhao, &dangqianzhuangtai, &zhiyeguwen, &fangwulaiyuan, &suozaichengqu,&fangwujiage, &fangwuleixing, &chanquanxingbie, &fangwumianji, & jianzhuniandai, &suozailouceng, &zhuangxiubiaozhun, &loucengzongshu, &jutidizhi,
                                      &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &fangyuanxiangxixinxi,&yezhuxingming, &lianxidianghua, &lianxishouji, & yezhushuoming);
        this->jiageLabel_1->setText(str.setNum(fangwujiage));
        this->mianjiLabel_1->setText(str.setNum(fangwumianji));
        this->chufangLabel_1->setVisible(a);
        this->chuangLabel_1->setVisible(b);
        this->jiajuLabel_1->setVisible(c);
        this->youxianLabel_1->setVisible(d);
        this->kuandaiLabel_1->setVisible(e);
        this->dianhuaLabel_1->setVisible(f);
        this->reshuiqiLabel_1->setVisible(g);
        this->dianshiLabel_1->setVisible(h);
        this->kongtiaoLabel_1->setVisible(i);
        this->xiyijiLabel_1->setVisible(j);
        this->bingxiangLabel_1->setVisible(k);
        this->meiqiLabel_1->setVisible(l);
        this->nuanqiLabel_1->setVisible(m);
        this->chekuLabel_1->setVisible(n);
        this->dizhiLabel_1->setText(jutidizhi);

        this->xingmingLabel_1->setText(yezhuxingming);
        this->lianxiDianhuaLabel_1->setText(lianxidianghua);
        this->shoujiLabel_1->setText(lianxishouji);
        this->beizhuLabel_1->setText(yezhushuoming);

        break;
    case 2:
        this->tableView_2->selectRow(this->tableView_2->currentIndex().row());
        fangwubianhao = this->tableView_2->currentIndex().data().toInt();

        this->dbcon->getHezuFangyuan(fangwubianhao, &dangqianzhuangtai, &zhiyeguwen, &fangwulaiyuan, &suozaichengqu,&fangwujiage, &fangwuleixing, &chanquanxingbie, &fangwumianji, & jianzhuniandai, &suozailouceng, &zhuangxiubiaozhun, &loucengzongshu, &jutidizhi,
                                     &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &fangyuanxiangxixinxi,&yezhuxingming, &lianxidianghua, &lianxishouji, & yezhushuoming);
        this->jiageLabel_2->setText(str.setNum(fangwujiage));
        this->mianjiLabel_2->setText(str.setNum(fangwumianji));
        this->chufangLabel_2->setVisible(a);
        this->chuangLabel_2->setVisible(b);
        this->jiajuLabel_2->setVisible(c);
        this->youxianLabel_2->setVisible(d);
        this->kuandaiLabel_2->setVisible(e);
        this->dianhuaLabel_2->setVisible(f);
        this->reshuiqiLabel_2->setVisible(g);
        this->dianshiLabel_2->setVisible(h);
        this->kongtiaoLabel_2->setVisible(i);
        this->xiyijiLabel_2->setVisible(j);
        this->bingxiangLabel_2->setVisible(k);
        this->meiqiLabel_2->setVisible(l);
        this->nuanqiLabel_2->setVisible(m);
        this->chekuLabel_2->setVisible(n);
        this->dizhiLabel_2->setText(jutidizhi);

        this->xingmingLabel_2->setText(yezhuxingming);
        this->lianxiDianhuaLabel_2->setText(lianxidianghua);
        this->shoujiLabel_2->setText(lianxishouji);
        this->beizhuLabel_2->setText(yezhushuoming);

        break;

    }
}

void MainWindow::on_tableView_1_clicked()
{
    on_tableView_0_clicked();
}

void MainWindow::on_tableView_2_clicked()
{
    on_tableView_0_clicked();
}

void MainWindow::on_chengquComboBox_0_currentIndexChanged(const QString &text)
{
    qDebug() << text;
    if(text == tr("不限")){
        this->filterChengqu_0->clear();
        this->filterChengqu_0->append(tr(" 1 "));
    }else
    {
        this->filterChengqu_0->clear();
        this->filterChengqu_0->append(tr(" suozaichengqu = '")).append(text).append(" ' ");
    }
    this->dbcon->chushoufangyuan->setFilter (*(this->filterChengqu_0) + tr("and") + *(this->filterLeixing_0) +tr("and") +*(this->filterZhuangtai_0));
    this->dbcon->chushoufangyuan->select();

}
void MainWindow::on_chengquComboBox_1_currentIndexChanged(const QString &text)
{
    qDebug() << text;
    if(text == tr("不限")){
        this->filterChengqu_1->clear();
        this->filterChengqu_1->append(tr(" 1 "));
    }else
    {
        this->filterChengqu_1->clear();
        this->filterChengqu_1->append(tr(" suozaichengqu = '")).append(text).append(" ' ");
    }
    this->dbcon->chuzufangyuan->setFilter (*(this->filterChengqu_1) + tr("and") + *(this->filterLeixing_1) +tr("and") +*(this->filterZhuangtai_1));
    this->dbcon->chuzufangyuan->select();
}
void MainWindow::on_chengquComboBox_2_currentIndexChanged(const QString &text)
{
    qDebug() << text;
    if(text == tr("不限")){
        this->filterChengqu_2->clear();
        this->filterChengqu_2->append(tr(" 1 "));
    }else
    {
        this->filterChengqu_2->clear();
        this->filterChengqu_2->append(tr(" suozaichengqu = '")).append(text).append(" ' ");
    }
    this->dbcon->hezufangyuan->setFilter (*(this->filterChengqu_2) + tr("and") + *(this->filterLeixing_2) +tr("and") +*(this->filterZhuangtai_2));
    this->dbcon->hezufangyuan->select();
}
void MainWindow::on_chengquComboBox_3_currentIndexChanged(const QString &text)
{
    qDebug() << text;
}
void MainWindow::on_chengquComboBox_4_currentIndexChanged(const QString &text)
{
    qDebug() << text;
}
void MainWindow::on_chengquComboBox_5_currentIndexChanged(const QString &text)
{
    qDebug() << text;
}

void MainWindow::on_fangwuLeixingComboBox_0_currentIndexChanged(const QString &text)
{
    qDebug() << text;
    if(text == tr("不限")){
        this->filterLeixing_0->clear();
        this->filterLeixing_0->append(tr(" 1 "));
    }else
    {
        this->filterLeixing_0->clear();
        this->filterLeixing_0->append(tr(" fangwuleixing = '")).append(text).append(" ' ");
    }

    this->dbcon->chushoufangyuan->setFilter (*(this->filterChengqu_0) + tr("and") + *(this->filterLeixing_0) +tr("and") +*(this->filterZhuangtai_0));
    this->dbcon->chushoufangyuan->select();

}
void MainWindow::on_fangwuLeixingComboBox_1_currentIndexChanged(const QString &text)
{
    qDebug() << text;
    if(text == tr("不限")){
        this->filterLeixing_1->clear();
        this->filterLeixing_1->append(tr(" 1 "));
    }else
    {
        this->filterLeixing_1->clear();
        this->filterLeixing_1->append(tr(" fangwuleixing = '")).append(text).append(" ' ");
    }

    this->dbcon->chuzufangyuan->setFilter (*(this->filterChengqu_1) + tr("and") + *(this->filterLeixing_1) +tr("and") +*(this->filterZhuangtai_1));
    this->dbcon->chuzufangyuan->select();
}
void MainWindow::on_fangwuLeixingComboBox_2_currentIndexChanged(const QString &text)
{

    qDebug() << text;
    if(text == tr("不限")){
        this->filterLeixing_2->clear();
        this->filterLeixing_2->append(tr(" 1 "));
    }else
    {
        this->filterLeixing_2->clear();
        this->filterLeixing_2->append(tr(" fangwuleixing = '")).append(text).append(" ' ");
    }

    this->dbcon->hezufangyuan->setFilter (*(this->filterChengqu_2) + tr("and") + *(this->filterLeixing_2) +tr("and") +*(this->filterZhuangtai_2));
    this->dbcon->hezufangyuan->select();
}
void MainWindow::on_fangwuLeixingComboBox_3_currentIndexChanged(const QString &text)
{
    qDebug() << text;
}
void MainWindow::on_fangwuLeixingComboBox_4_currentIndexChanged(const QString &text)
{
    qDebug() << text;
}
void MainWindow::on_fangwuLeixingComboBox_5_currentIndexChanged(const QString &text)
{
    qDebug() << text;
}

void MainWindow::on_fangwuZhuangtaiComboBox_0_currentIndexChanged(const QString &text){
    qDebug() << text;
    if(text == tr("不限")){
        this->filterZhuangtai_0->clear();
        this->filterZhuangtai_0->append(tr(" 1 "));
    }else
    {
        this->filterZhuangtai_0->clear();
        this->filterZhuangtai_0->append(tr(" dangqianzhuangtai = '")).append(text).append(" ' ");
    }

    this->dbcon->chushoufangyuan->setFilter (*(this->filterChengqu_0) + tr("and") + *(this->filterLeixing_0) +tr("and") +*(this->filterZhuangtai_0));
    this->dbcon->chushoufangyuan->select();
}
void MainWindow::on_fangwuZhuangtaiComboBox_1_currentIndexChanged(const QString &text){
    qDebug() << text;
    if(text == tr("不限")){
        this->filterZhuangtai_1->clear();
        this->filterZhuangtai_1->append(tr(" 1 "));
    }else
    {
        this->filterZhuangtai_1->clear();
        this->filterZhuangtai_1->append(tr(" dangqianzhuangtai = '")).append(text).append(" ' ");
    }

    this->dbcon->chuzufangyuan->setFilter (*(this->filterChengqu_1) + tr("and") + *(this->filterLeixing_1) +tr("and") +*(this->filterZhuangtai_1));
    this->dbcon->chuzufangyuan->select();
}
void MainWindow::on_fangwuZhuangtaiComboBox_2_currentIndexChanged(const QString &text){
    qDebug() << text;
    if(text == tr("不限")){
        this->filterZhuangtai_2->clear();
        this->filterZhuangtai_2->append(tr(" 1 "));
    }else
    {
        this->filterZhuangtai_2->clear();
        this->filterZhuangtai_2->append(tr(" dangqianzhuangtai = '")).append(text).append(" ' ");
    }

    this->dbcon->hezufangyuan->setFilter (*(this->filterChengqu_2) + tr("and") + *(this->filterLeixing_2) +tr("and") +*(this->filterZhuangtai_2));
    this->dbcon->hezufangyuan->select();
}

void MainWindow::on_kehuZhuangtaiComboBox_3_currentIndexChanged(const QString &text){
    qDebug() << text;
}
void MainWindow::on_kehuZhuangtaiComboBox_4_currentIndexChanged(const QString &text){
    qDebug() << text;
}
void MainWindow::on_kehuZhuangtaiComboBox_5_currentIndexChanged(const QString &text){
    qDebug() << text;
}
