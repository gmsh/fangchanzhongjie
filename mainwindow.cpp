#include "mainwindow.h"
#include "quanxianzuguanlidialog.h"
#include "yuangongguanlidialog.h"
#include "canshuguanlidialog.h"
#include "dbconnect.h"
#include <QtGui/QMenu>
#include <QtGui/QAction>
#include <QtGui/QMessageBox>
MainWindow::MainWindow(DBConnect *dbcon)
{
    this->dbcon = dbcon;
    setupUi(this);
    this->xitongShezhiMenu = new QMenu;

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
    //yuangongGuanliDialog.setTableModel(this->dbcon->yuangongModel);
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
