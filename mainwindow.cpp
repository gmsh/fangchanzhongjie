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
    this->xitongShezhiMenu = new QMenu;

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
    this->chengquComboBox_0->addItems(*(list));
    this->chengquComboBox_1->addItems(*(list));
    this->chengquComboBox_2->addItems(*(list));
    this->chengquComboBox_3->addItems(*(list));
    this->chengquComboBox_4->addItems(*(list));
    this->chengquComboBox_5->addItems(*(list));

    list = this->dbcon->fangwuZhuangtaiList();
    this->fangwuZhuangtaiComboBox_0->addItems(*list);
    this->fangwuZhuangtaiComboBox_1->addItems(*list);
    this->fangwuZhuangtaiComboBox_2->addItems(*list);

    list = this->dbcon->kekuZhuangtaiList();
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

    connect(this->actionYuangongGuanli, SIGNAL(triggered()), this, SLOT(on_actionYuangongGuanli_triggerd()));
    connect(this->actionQuanxianzuGuanli, SIGNAL(triggered()), this, SLOT(on_actionQuanxianzuGuanli_triggered()));
    connect(this->actionCanshuShezhi, SIGNAL(triggered()), this, SLOT(on_actionCanshuShezhi_triggerd()));
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
    qDebug() << item->text(0);
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
}

void MainWindow::on_actionTianjiaFangyuan_triggered()
{
    FangyuanDialog fangyuanDialog(this, this->dbcon);
    fangyuanDialog.exec();
}

void MainWindow::on_actionTianjiaKehu_triggered()
{
    KeyuanDialog keyuanDialog(this, this->dbcon);
    keyuanDialog.exec();
}
