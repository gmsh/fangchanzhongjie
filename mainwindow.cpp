#include "mainwindow.h"
#include "quanxianzuguanlidialog.h"
#include "yuangongguanlidialog.h"
#include "canshuguanlidialog.h"
#include "fangyuandialog.h"
#include "keyuandialog.h"
#include "dbconnect.h"
#include "chengjiaoqianyuedialog.h"
#include <QtGui/QMenu>
#include <QtGui/QAction>
#include <QtGui/QMessageBox>
#include <QtCore/QDebug>
#include <QtSql/QSqlRecord>

MainWindow::MainWindow(DBConnect *dbcon, QString *loginName)
{
    this->dbcon = dbcon;
    setupUi(this);
    bool a, b, c, d, e, f, g, h, i, j, k, l;
    //QString * suozaiquanxianzu = this->dbcon->getSuozaiQuanxianzu(loginName);
    /*this->dbcon->getQuanxian(suozaiquanxianzu, &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l);
    this->stackedWidget->widget(0)->setEnabled(a);
    this->stackedWidget->widget(1)->setEnabled(b);
    this->stackedWidget->widget(2)->setEnabled(c);
    this->stackedWidget->widget(3)->setEnabled(d);
    this->stackedWidget->widget(4)->setEnabled(e);
    this->stackedWidget->widget(5)->setEnabled(f);

    this->tabWidget_0->widget(3)->setEnabled(g);
    this->tabWidget_1->widget(3)->setEnabled(g);
    this->tabWidget_2->widget(3)->setEnabled(g);
    this->tabWidget_3->widget(3)->setEnabled(h);
    this->tabWidget_4->widget(3)->setEnabled(h);
    this->tabWidget_5->widget(3)->setEnabled(h);

    this->actionQianyueChengjiao->setEnabled(i);
    this->actionYuangongGuanli->setEnabled(j);
    this->actionQuanxianzuGuanli->setEnabled(k);
    this->actionCanshuShezhi->setEnabled(l);*/

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

    this->rcomboBox_0->addItems(*(this->dbcon->loginNames()));
    this->rcomboBox_1->addItems(*(this->dbcon->loginNames()));
    this->rcomboBox_2->addItems(*(this->dbcon->loginNames()));
    this->rcomboBox_3->addItems(*(this->dbcon->loginNames()));
    this->rcomboBox_4->addItems(*(this->dbcon->loginNames()));
    this->rcomboBox_5->addItems(*(this->dbcon->loginNames()));

    this->fcomboBox_0->addItems(*(this->dbcon->genjinFangshiList()));
    this->fcomboBox_1->addItems(*(this->dbcon->genjinFangshiList()));
    this->fcomboBox_2->addItems(*(this->dbcon->genjinFangshiList()));
    this->fcomboBox_3->addItems(*(this->dbcon->genjinFangshiList()));
    this->fcomboBox_4->addItems(*(this->dbcon->genjinFangshiList()));
    this->fcomboBox_5->addItems(*(this->dbcon->genjinFangshiList()));


    this->tableView_0->setModel(dbcon->chushoufangyuan);
    this->tableView_1->setModel(dbcon->chuzufangyuan);
    this->tableView_2->setModel(dbcon->hezufangyuan);
    this->tableView_3->setModel(dbcon->qiugoukehu);
    this->tableView_4->setModel(dbcon->qiuzukehu);
    this->tableView_5->setModel(dbcon->hezukehu);

    this->genjinTableView_0->setModel(this->dbcon->genjinchushou);
    this->genjinTableView_0->setColumnHidden(0, true);
    this->genjinTableView_1->setModel(this->dbcon->genjinchuzu);
    this->genjinTableView_1->setColumnHidden(0, true);
    this->genjinTableView_2->setModel(this->dbcon->genjinhezufang);
    this->genjinTableView_2->setColumnHidden(0, true);
    this->genjinTableView_3->setModel(this->dbcon->genjinqiugou);
    this->genjinTableView_3->setColumnHidden(0, true);
    this->genjinTableView_4->setModel(this->dbcon->genjinqiuzu);
    this->genjinTableView_4->setColumnHidden(0, true);
    this->genjinTableView_5->setModel(this->dbcon->genjinhezuke);
    this->genjinTableView_5->setColumnHidden(0, true);

    this->genjinTableView_0->setSelectionMode(QTableView::SingleSelection);
    this->genjinTableView_0->setSelectionBehavior(QTableView::SelectRows);
    this->genjinTableView_1->setSelectionMode(QTableView::SingleSelection);
    this->genjinTableView_1->setSelectionBehavior(QTableView::SelectRows);
    this->genjinTableView_2->setSelectionMode(QTableView::SingleSelection);
    this->genjinTableView_2->setSelectionBehavior(QTableView::SelectRows);
    this->genjinTableView_3->setSelectionMode(QTableView::SingleSelection);
    this->genjinTableView_3->setSelectionBehavior(QTableView::SelectRows);
    this->genjinTableView_4->setSelectionMode(QTableView::SingleSelection);
    this->genjinTableView_4->setSelectionBehavior(QTableView::SelectRows);
    this->genjinTableView_5->setSelectionMode(QTableView::SingleSelection);
    this->genjinTableView_5->setSelectionBehavior(QTableView::SelectRows);

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
    this->tableView_3->setColumnHidden(5,true);
    this->tableView_3->setColumnHidden(8,true);
    this->tableView_3->setColumnHidden(10,true);
    this->tableView_3->setColumnHidden(12,true);
    this->tableView_3->setColumnHidden(13,true);
    this->tableView_3->setColumnHidden(14,true);
    this->tableView_3->setColumnHidden(15,true);
    this->tableView_3->setColumnHidden(16,true);
    this->tableView_3->setColumnHidden(17,true);
    this->tableView_3->setColumnHidden(18,true);
    this->tableView_3->setColumnHidden(19,true);
    this->tableView_3->setColumnHidden(20,true);
    this->tableView_3->setColumnHidden(21,true);
    this->tableView_3->setColumnHidden(22,true);
    this->tableView_3->setColumnHidden(23,true);
    this->tableView_3->setColumnHidden(24,true);
    this->tableView_3->setColumnHidden(25,true);
    this->tableView_3->setColumnHidden(26,true);
    this->tableView_3->setColumnHidden(27,true);
    this->tableView_3->setColumnHidden(28,true);
    this->tableView_3->setColumnHidden(29,true);
    this->tableView_3->setColumnHidden(30,true);
    this->tableView_3->setColumnHidden(31,true);
    this->tableView_3->setColumnHidden(32,true);
    this->tableView_4->setColumnHidden(5,true);
    this->tableView_4->setColumnHidden(8,true);
    this->tableView_4->setColumnHidden(10,true);
    this->tableView_4->setColumnHidden(12,true);
    this->tableView_4->setColumnHidden(13,true);
    this->tableView_4->setColumnHidden(14,true);
    this->tableView_4->setColumnHidden(15,true);
    this->tableView_4->setColumnHidden(16,true);
    this->tableView_4->setColumnHidden(17,true);
    this->tableView_4->setColumnHidden(18,true);
    this->tableView_4->setColumnHidden(19,true);
    this->tableView_4->setColumnHidden(20,true);
    this->tableView_4->setColumnHidden(21,true);
    this->tableView_4->setColumnHidden(22,true);
    this->tableView_4->setColumnHidden(23,true);
    this->tableView_4->setColumnHidden(24,true);
    this->tableView_4->setColumnHidden(25,true);
    this->tableView_4->setColumnHidden(26,true);
    this->tableView_4->setColumnHidden(27,true);
    this->tableView_4->setColumnHidden(28,true);
    this->tableView_4->setColumnHidden(29,true);
    this->tableView_4->setColumnHidden(30,true);
    this->tableView_4->setColumnHidden(31,true);
    this->tableView_4->setColumnHidden(32,true);
    this->tableView_5->setColumnHidden(5,true);
    this->tableView_5->setColumnHidden(8,true);
    this->tableView_5->setColumnHidden(10,true);
    this->tableView_5->setColumnHidden(12,true);
    this->tableView_5->setColumnHidden(13,true);
    this->tableView_5->setColumnHidden(14,true);
    this->tableView_5->setColumnHidden(15,true);
    this->tableView_5->setColumnHidden(16,true);
    this->tableView_5->setColumnHidden(17,true);
    this->tableView_5->setColumnHidden(18,true);
    this->tableView_5->setColumnHidden(19,true);
    this->tableView_5->setColumnHidden(20,true);
    this->tableView_5->setColumnHidden(21,true);
    this->tableView_5->setColumnHidden(22,true);
    this->tableView_5->setColumnHidden(23,true);
    this->tableView_5->setColumnHidden(24,true);
    this->tableView_5->setColumnHidden(25,true);
    this->tableView_5->setColumnHidden(26,true);
    this->tableView_5->setColumnHidden(27,true);
    this->tableView_5->setColumnHidden(28,true);
    this->tableView_5->setColumnHidden(29,true);
    this->tableView_5->setColumnHidden(30,true);
    this->tableView_5->setColumnHidden(31,true);
    this->tableView_5->setColumnHidden(32,true);
    this->tableView_0->resizeColumnsToContents();
    this->tableView_1->resizeColumnsToContents();
    this->tableView_2->resizeColumnsToContents();
    this->tableView_3->resizeColumnsToContents();
    this->tableView_4->resizeColumnsToContents();
    this->tableView_5->resizeColumnsToContents();

    this->tableView_0->setSelectionMode(QTableView::SingleSelection);
    this->tableView_0->setSelectionBehavior(QTableView::SelectRows);
    this->tableView_0->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->tableView_1->setSelectionMode(QTableView::SingleSelection);
    this->tableView_1->setSelectionBehavior(QTableView::SelectRows);
    this->tableView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->tableView_2->setSelectionMode(QTableView::SingleSelection);
    this->tableView_2->setSelectionBehavior(QTableView::SelectRows);
    this->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->tableView_3->setSelectionMode(QTableView::SingleSelection);
    this->tableView_3->setSelectionBehavior(QTableView::SelectRows);
    this->tableView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->tableView_4->setSelectionMode(QTableView::SingleSelection);
    this->tableView_4->setSelectionBehavior(QTableView::SelectRows);
    this->tableView_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->tableView_5->setSelectionMode(QTableView::SingleSelection);
    this->tableView_5->setSelectionBehavior(QTableView::SelectRows);
    this->tableView_5->setEditTriggers(QAbstractItemView::NoEditTriggers);



    connect(this->addPushButton_0, SIGNAL(clicked()), this, SLOT(on_actionTianjiaFangyuan_triggered()));
    connect(this->addPushButton_1, SIGNAL(clicked()), this, SLOT(on_actionTianjiaFangyuan_triggered()));
    connect(this->addPushButton_2, SIGNAL(clicked()), this, SLOT(on_actionTianjiaFangyuan_triggered()));

    connect(this->modifyPushButton_1, SIGNAL(clicked()), this, SLOT(on_modifyPushButton_0_clicked()));
    connect(this->modifyPushButton_2, SIGNAL(clicked()), this, SLOT(on_modifyPushButton_0_clicked()));

    connect(this->modifyPushButton_4, SIGNAL(clicked()), this, SLOT(on_modifyPushButton_3_clicked()));
    connect(this->modifyPushButton_5, SIGNAL(clicked()), this, SLOT(on_modifyPushButton_3_clicked()));

    connect(this->deletePushButton_1, SIGNAL(clicked()), this,  SLOT(on_deletePushButton_0_clicked()));
    connect(this->deletePushButton_2, SIGNAL(clicked()), this,  SLOT(on_deletePushButton_0_clicked()));

    connect(this->deletePushButton_4, SIGNAL(clicked()), this,  SLOT(on_deletePushButton_3_clicked()));
    connect(this->deletePushButton_5, SIGNAL(clicked()), this,  SLOT(on_deletePushButton_3_clicked()));

    connect(this->addPushButton_3, SIGNAL(clicked()), this, SLOT(on_actionTianjiaKehu_triggered()));
    connect(this->addPushButton_4, SIGNAL(clicked()), this, SLOT(on_actionTianjiaKehu_triggered()));
    connect(this->addPushButton_5, SIGNAL(clicked()), this, SLOT(on_actionTianjiaKehu_triggered()));

    this->tableView_0->selectRow(0);
    this->tableView_1->selectRow(0);
    this->tableView_2->selectRow(0);
    this->on_tableView_0_clicked();
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_actionRuanjianBangzhu_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionTuichuXitong_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionYuangongGuanli_triggered()
{
    YuangongGuanliDialog yuangongGuanliDialog(this, this->dbcon);
    yuangongGuanliDialog.exec();
}

void MainWindow::on_actionQuanxianzuGuanli_triggered()
{
    QuanxianzuGuanliDialog quanxianzuGuanliDialog(0,this->dbcon);
    quanxianzuGuanliDialog.exec();
}

void MainWindow::on_actionCanshuShezhi_triggered()
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
    switches:
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
        default:
        this->stackedWidget->setCurrentIndex(0);
        goto switches;
        break;
    }

}

void MainWindow::on_modifyPushButton_0_clicked()
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

void MainWindow::on_modifyPushButton_3_clicked()
{
    int kehubianhao, fangwujiage, suozailouceng, loucengzongshu;
    QString xinjiuchengdu, dangqianzhuangtai, zhiyeguwen, kehulaiyuan, suozaichengqu, fangwuleixing, chanquanxingbie,zhuangxiubiaozhun, yixiangdizhi, fangyuanxiangxixinxi, yezhuxingming, lianxidianghua, lianxishouji, yezhushuoming;
    bool a, b, c, d, e, f, g, h, i, j, k, l, m, n;
    float fangwumianji;
    KeyuanDialog keyuanDialog(this, this->dbcon);
    QComboBox * combo;
    switch(this->stackedWidget->currentIndex()){
    case 3:
        keyuanDialog.kehuXuqiuComboBox->setCurrentIndex(0);
        keyuanDialog.asQiugouQiuzu();
        this->tableView_3->selectRow(this->tableView_3->currentIndex().row());
        kehubianhao = this->tableView_3->currentIndex().data().toInt();
        this->dbcon->getQiugouKehu(kehubianhao, &dangqianzhuangtai, &zhiyeguwen, &kehulaiyuan, &suozaichengqu,&fangwujiage, &fangwuleixing, &chanquanxingbie, &fangwumianji, & xinjiuchengdu, &suozailouceng, &zhuangxiubiaozhun, &loucengzongshu, &yixiangdizhi,
                                   &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &fangyuanxiangxixinxi,&yezhuxingming, &lianxidianghua, &lianxishouji, & yezhushuoming);
        keyuanDialog.kehuBianhaoSpinBox->setValue(kehubianhao);
        keyuanDialog.kehuBianhaoSpinBox->setEnabled(false);
        keyuanDialog.kehuXuqiuComboBox->setEnabled(false);
        combo = keyuanDialog.dangqianZhuangtaiComboBox;
        combo ->setCurrentIndex(combo->findText(dangqianzhuangtai));
        combo = keyuanDialog.zhiyeGuwenComboBox;
        combo ->setCurrentIndex(combo->findText(zhiyeguwen));
        combo = keyuanDialog.kehuLaiyuanComboBox;
        combo ->setCurrentIndex(combo->findText(kehulaiyuan));
        combo = keyuanDialog.suozaiChengquComboBox;
        combo ->setCurrentIndex(combo->findText(suozaichengqu));
        combo = keyuanDialog.fangwuLeixingComboBox;
        combo ->setCurrentIndex(combo->findText(fangwuleixing));
        combo = keyuanDialog.chanquanXingbieComboBox;
        combo ->setCurrentIndex(combo->findText(chanquanxingbie));
        combo = keyuanDialog.zhuangxiuBiaozhunComboBox;
        combo ->setCurrentIndex(combo->findText(zhuangxiubiaozhun));
        combo = keyuanDialog.xinjiuChengduComboBox;
        combo ->setCurrentIndex(combo->findText(xinjiuchengdu));

        keyuanDialog.fangwuJiageSpinBox->setValue(fangwujiage);
        keyuanDialog.fangwuMianjiDoubleSpinBox->setValue(fangwumianji);
        //keyuanDialog.jianchengNiandaiSpinBox->setValue(xinjiuchengdu);
        keyuanDialog.suozaiLoucengSpinBox->setValue(suozailouceng);
        keyuanDialog.loucengZongshuSpinBox->setValue(loucengzongshu);
        keyuanDialog.yixiangDizhiLineEdit->setText(yixiangdizhi);

        if(a)
            keyuanDialog.chufangCheckBox->setCheckState(Qt::Checked);
        if(b)
            keyuanDialog.chuangCheckBox->setCheckState(Qt::Checked);
        if(c)
            keyuanDialog.jiajuCheckBox->setCheckState(Qt::Checked);
        if(d)
            keyuanDialog.youxianDianshiCheckBox->setCheckState(Qt::Checked);
        if(e)
            keyuanDialog.kuaidaiwangCheckBox->setCheckState(Qt::Checked);
        if(f)
            keyuanDialog.dianhuaCheckBox->setCheckState(Qt::Checked);
        if(g)
            keyuanDialog.reshuiqiCheckBox->setCheckState(Qt::Checked);
        if(h)
            keyuanDialog.dianshijiCheckBox->setCheckState(Qt::Checked);
        if(i)
            keyuanDialog.kongtiaoCheckBox->setCheckState(Qt::Checked);
        if(j)
            keyuanDialog.xiyijiCheckBox->setCheckState(Qt::Checked);
        if(k)
            keyuanDialog.bingxiangCheckBox->setCheckState(Qt::Checked);
        if(l)
            keyuanDialog.meiqiCheckBox->setCheckState(Qt::Checked);
        if(m)
            keyuanDialog.nuanqiCheckBox->setCheckState(Qt::Checked);
        if(n)
            keyuanDialog.qichekuCheckBox->setCheckState(Qt::Checked);

        keyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->setPlainText(fangyuanxiangxixinxi);
        keyuanDialog.yezhuXingmingLineEdit->setText(yezhuxingming);
        keyuanDialog.lianxiDianhuaLineEdit->setText(lianxidianghua);
        keyuanDialog.lianxiShoujiLineEdit->setText(lianxishouji);
        keyuanDialog.yezhuShuomingLineEdit->setText(yezhushuoming);
        if(keyuanDialog.exec() == QDialog::Accepted){
            dbcon->insertQiugoukehu(keyuanDialog.kehuBianhaoSpinBox->text().toInt(),
                                    keyuanDialog.dangqianZhuangtaiComboBox->currentText(),
                                    keyuanDialog.zhiyeGuwenComboBox->currentText(),
                                    keyuanDialog.kehuLaiyuanComboBox->currentText(),
                                    keyuanDialog.suozaiChengquComboBox->currentText(),
                                    keyuanDialog.fangwuJiageSpinBox->text().toInt(),
                                    keyuanDialog.fangwuLeixingComboBox->currentText(),
                                    keyuanDialog.chanquanXingbieComboBox->currentText(),
                                    keyuanDialog.fangwuMianjiDoubleSpinBox->text().toFloat(),
                                    keyuanDialog.xinjiuChengduComboBox->currentText(),
                                    keyuanDialog.suozaiLoucengSpinBox->text().toInt(),
                                    keyuanDialog.zhuangxiuBiaozhunComboBox->currentText(),
                                    keyuanDialog.loucengZongshuSpinBox->text().toInt(),
                                    keyuanDialog.yixiangDizhiLineEdit->text(),
                                    keyuanDialog.chufangCheckBox->isChecked(),
                                    keyuanDialog.chuangCheckBox->isChecked(),
                                    keyuanDialog.jiajuCheckBox->isChecked(),
                                    keyuanDialog.youxianDianshiCheckBox->isChecked(),
                                    keyuanDialog.kuaidaiwangCheckBox->isChecked(),
                                    keyuanDialog.dianhuaCheckBox->isChecked(),
                                    keyuanDialog.reshuiqiCheckBox->isChecked(),
                                    keyuanDialog.dianshijiCheckBox->isChecked(),
                                    keyuanDialog.kongtiaoCheckBox->isChecked(),
                                    keyuanDialog.xiyijiCheckBox->isChecked(),
                                    keyuanDialog.bingxiangCheckBox->isChecked(),
                                    keyuanDialog.meiqiCheckBox->isChecked(),
                                    keyuanDialog.nuanqiCheckBox->isChecked(),
                                    keyuanDialog.qichekuCheckBox->isChecked(),
                                    keyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->toPlainText(),
                                    keyuanDialog.yezhuXingmingLineEdit->text(),
                                    keyuanDialog.lianxiDianhuaLineEdit->text(),
                                    keyuanDialog.lianxiShoujiLineEdit->text(),
                                    keyuanDialog.yezhuShuomingLineEdit->text());
        }
        this->dbcon->qiugoukehu->select();

        break;
    case 4:
        keyuanDialog.kehuXuqiuComboBox->setCurrentIndex(0);
        keyuanDialog.asQiugouQiuzu();
        this->tableView_3->selectRow(this->tableView_3->currentIndex().row());
        kehubianhao = this->tableView_3->currentIndex().data().toInt();
        this->dbcon->getQiuzuKehu(kehubianhao, &dangqianzhuangtai, &zhiyeguwen, &kehulaiyuan, &suozaichengqu,&fangwujiage, &fangwuleixing, &chanquanxingbie, &fangwumianji, & xinjiuchengdu, &suozailouceng, &zhuangxiubiaozhun, &loucengzongshu, &yixiangdizhi,
                                  &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &fangyuanxiangxixinxi,&yezhuxingming, &lianxidianghua, &lianxishouji, & yezhushuoming);
        keyuanDialog.kehuBianhaoSpinBox->setValue(kehubianhao);
        keyuanDialog.kehuBianhaoSpinBox->setEnabled(false);
        keyuanDialog.kehuXuqiuComboBox->setEnabled(false);
        combo = keyuanDialog.dangqianZhuangtaiComboBox;
        combo ->setCurrentIndex(combo->findText(dangqianzhuangtai));
        combo = keyuanDialog.zhiyeGuwenComboBox;
        combo ->setCurrentIndex(combo->findText(zhiyeguwen));
        combo = keyuanDialog.kehuLaiyuanComboBox;
        combo ->setCurrentIndex(combo->findText(kehulaiyuan));
        combo = keyuanDialog.suozaiChengquComboBox;
        combo ->setCurrentIndex(combo->findText(suozaichengqu));
        combo = keyuanDialog.fangwuLeixingComboBox;
        combo ->setCurrentIndex(combo->findText(fangwuleixing));
        combo = keyuanDialog.chanquanXingbieComboBox;
        combo ->setCurrentIndex(combo->findText(chanquanxingbie));
        combo = keyuanDialog.zhuangxiuBiaozhunComboBox;
        combo ->setCurrentIndex(combo->findText(zhuangxiubiaozhun));
        combo = keyuanDialog.xinjiuChengduComboBox;
        combo ->setCurrentIndex(combo->findText(xinjiuchengdu));

        keyuanDialog.fangwuJiageSpinBox->setValue(fangwujiage);
        keyuanDialog.fangwuMianjiDoubleSpinBox->setValue(fangwumianji);
        //keyuanDialog.jianchengNiandaiSpinBox->setValue(xinjiuchengdu);
        keyuanDialog.suozaiLoucengSpinBox->setValue(suozailouceng);
        keyuanDialog.loucengZongshuSpinBox->setValue(loucengzongshu);
        keyuanDialog.yixiangDizhiLineEdit->setText(yixiangdizhi);

        if(a)
            keyuanDialog.chufangCheckBox->setCheckState(Qt::Checked);
        if(b)
            keyuanDialog.chuangCheckBox->setCheckState(Qt::Checked);
        if(c)
            keyuanDialog.jiajuCheckBox->setCheckState(Qt::Checked);
        if(d)
            keyuanDialog.youxianDianshiCheckBox->setCheckState(Qt::Checked);
        if(e)
            keyuanDialog.kuaidaiwangCheckBox->setCheckState(Qt::Checked);
        if(f)
            keyuanDialog.dianhuaCheckBox->setCheckState(Qt::Checked);
        if(g)
            keyuanDialog.reshuiqiCheckBox->setCheckState(Qt::Checked);
        if(h)
            keyuanDialog.dianshijiCheckBox->setCheckState(Qt::Checked);
        if(i)
            keyuanDialog.kongtiaoCheckBox->setCheckState(Qt::Checked);
        if(j)
            keyuanDialog.xiyijiCheckBox->setCheckState(Qt::Checked);
        if(k)
            keyuanDialog.bingxiangCheckBox->setCheckState(Qt::Checked);
        if(l)
            keyuanDialog.meiqiCheckBox->setCheckState(Qt::Checked);
        if(m)
            keyuanDialog.nuanqiCheckBox->setCheckState(Qt::Checked);
        if(n)
            keyuanDialog.qichekuCheckBox->setCheckState(Qt::Checked);

        keyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->setPlainText(fangyuanxiangxixinxi);
        keyuanDialog.yezhuXingmingLineEdit->setText(yezhuxingming);
        keyuanDialog.lianxiDianhuaLineEdit->setText(lianxidianghua);
        keyuanDialog.lianxiShoujiLineEdit->setText(lianxishouji);
        keyuanDialog.yezhuShuomingLineEdit->setText(yezhushuoming);
        if(keyuanDialog.exec() == QDialog::Accepted){
            dbcon->insertQiuzukehu(keyuanDialog.kehuBianhaoSpinBox->text().toInt(),
                                   keyuanDialog.dangqianZhuangtaiComboBox->currentText(),
                                   keyuanDialog.zhiyeGuwenComboBox->currentText(),
                                   keyuanDialog.kehuLaiyuanComboBox->currentText(),
                                   keyuanDialog.suozaiChengquComboBox->currentText(),
                                   keyuanDialog.fangwuJiageSpinBox->text().toInt(),
                                   keyuanDialog.fangwuLeixingComboBox->currentText(),
                                   keyuanDialog.chanquanXingbieComboBox->currentText(),
                                   keyuanDialog.fangwuMianjiDoubleSpinBox->text().toFloat(),
                                   keyuanDialog.xinjiuChengduComboBox->currentText(),
                                   keyuanDialog.suozaiLoucengSpinBox->text().toInt(),
                                   keyuanDialog.zhuangxiuBiaozhunComboBox->currentText(),
                                   keyuanDialog.loucengZongshuSpinBox->text().toInt(),
                                   keyuanDialog.yixiangDizhiLineEdit->text(),
                                   keyuanDialog.chufangCheckBox->isChecked(),
                                   keyuanDialog.chuangCheckBox->isChecked(),
                                   keyuanDialog.jiajuCheckBox->isChecked(),
                                   keyuanDialog.youxianDianshiCheckBox->isChecked(),
                                   keyuanDialog.kuaidaiwangCheckBox->isChecked(),
                                   keyuanDialog.dianhuaCheckBox->isChecked(),
                                   keyuanDialog.reshuiqiCheckBox->isChecked(),
                                   keyuanDialog.dianshijiCheckBox->isChecked(),
                                   keyuanDialog.kongtiaoCheckBox->isChecked(),
                                   keyuanDialog.xiyijiCheckBox->isChecked(),
                                   keyuanDialog.bingxiangCheckBox->isChecked(),
                                   keyuanDialog.meiqiCheckBox->isChecked(),
                                   keyuanDialog.nuanqiCheckBox->isChecked(),
                                   keyuanDialog.qichekuCheckBox->isChecked(),
                                   keyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->toPlainText(),
                                   keyuanDialog.yezhuXingmingLineEdit->text(),
                                   keyuanDialog.lianxiDianhuaLineEdit->text(),
                                   keyuanDialog.lianxiShoujiLineEdit->text(),
                                   keyuanDialog.yezhuShuomingLineEdit->text());
        }
        this->dbcon->qiuzukehu->select();

        break;
    case 5:
        keyuanDialog.kehuXuqiuComboBox->setCurrentIndex(0);
        keyuanDialog.asHezu();
        this->tableView_3->selectRow(this->tableView_3->currentIndex().row());
        kehubianhao = this->tableView_3->currentIndex().data().toInt();
        this->dbcon->getHezuKehu(kehubianhao, &dangqianzhuangtai, &zhiyeguwen, &kehulaiyuan, &suozaichengqu,&fangwujiage, &fangwuleixing, &chanquanxingbie, &fangwumianji, & xinjiuchengdu, &suozailouceng, &zhuangxiubiaozhun, &loucengzongshu, &yixiangdizhi,
                                 &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &fangyuanxiangxixinxi,&yezhuxingming, &lianxidianghua, &lianxishouji, & yezhushuoming);
        keyuanDialog.kehuBianhaoSpinBox->setValue(kehubianhao);
        keyuanDialog.kehuBianhaoSpinBox->setEnabled(false);
        keyuanDialog.kehuXuqiuComboBox->setEnabled(false);
        combo = keyuanDialog.dangqianZhuangtaiComboBox;
        combo ->setCurrentIndex(combo->findText(dangqianzhuangtai));
        combo = keyuanDialog.zhiyeGuwenComboBox;
        combo ->setCurrentIndex(combo->findText(zhiyeguwen));
        combo = keyuanDialog.kehuLaiyuanComboBox;
        combo ->setCurrentIndex(combo->findText(kehulaiyuan));
        combo = keyuanDialog.suozaiChengquComboBox;
        combo ->setCurrentIndex(combo->findText(suozaichengqu));
        combo = keyuanDialog.fangwuLeixingComboBox;
        combo ->setCurrentIndex(combo->findText(fangwuleixing));
        combo = keyuanDialog.chanquanXingbieComboBox;
        combo ->setCurrentIndex(combo->findText(chanquanxingbie));
        combo = keyuanDialog.zhuangxiuBiaozhunComboBox;
        combo ->setCurrentIndex(combo->findText(zhuangxiubiaozhun));
        combo = keyuanDialog.xinjiuChengduComboBox;
        combo ->setCurrentIndex(combo->findText(xinjiuchengdu));

        keyuanDialog.fangwuJiageSpinBox->setValue(fangwujiage);
        keyuanDialog.fangwuMianjiDoubleSpinBox->setValue(fangwumianji);
        //keyuanDialog.jianchengNiandaiSpinBox->setValue(xinjiuchengdu);
        keyuanDialog.suozaiLoucengSpinBox->setValue(suozailouceng);
        keyuanDialog.loucengZongshuSpinBox->setValue(loucengzongshu);
        keyuanDialog.yixiangDizhiLineEdit->setText(yixiangdizhi);

        if(a)
            keyuanDialog.chufangCheckBox->setCheckState(Qt::Checked);
        if(b)
            keyuanDialog.chuangCheckBox->setCheckState(Qt::Checked);
        if(c)
            keyuanDialog.jiajuCheckBox->setCheckState(Qt::Checked);
        if(d)
            keyuanDialog.youxianDianshiCheckBox->setCheckState(Qt::Checked);
        if(e)
            keyuanDialog.kuaidaiwangCheckBox->setCheckState(Qt::Checked);
        if(f)
            keyuanDialog.dianhuaCheckBox->setCheckState(Qt::Checked);
        if(g)
            keyuanDialog.reshuiqiCheckBox->setCheckState(Qt::Checked);
        if(h)
            keyuanDialog.dianshijiCheckBox->setCheckState(Qt::Checked);
        if(i)
            keyuanDialog.kongtiaoCheckBox->setCheckState(Qt::Checked);
        if(j)
            keyuanDialog.xiyijiCheckBox->setCheckState(Qt::Checked);
        if(k)
            keyuanDialog.bingxiangCheckBox->setCheckState(Qt::Checked);
        if(l)
            keyuanDialog.meiqiCheckBox->setCheckState(Qt::Checked);
        if(m)
            keyuanDialog.nuanqiCheckBox->setCheckState(Qt::Checked);
        if(n)
            keyuanDialog.qichekuCheckBox->setCheckState(Qt::Checked);

        keyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->setPlainText(fangyuanxiangxixinxi);
        keyuanDialog.yezhuXingmingLineEdit->setText(yezhuxingming);
        keyuanDialog.lianxiDianhuaLineEdit->setText(lianxidianghua);
        keyuanDialog.lianxiShoujiLineEdit->setText(lianxishouji);
        keyuanDialog.yezhuShuomingLineEdit->setText(yezhushuoming);
        if(keyuanDialog.exec() == QDialog::Accepted){
            dbcon->insertHezukehu(keyuanDialog.kehuBianhaoSpinBox->text().toInt(),
                                  keyuanDialog.dangqianZhuangtaiComboBox->currentText(),
                                  keyuanDialog.zhiyeGuwenComboBox->currentText(),
                                  keyuanDialog.kehuLaiyuanComboBox->currentText(),
                                  keyuanDialog.suozaiChengquComboBox->currentText(),
                                  keyuanDialog.fangwuJiageSpinBox->text().toInt(),
                                  keyuanDialog.fangwuLeixingComboBox->currentText(),
                                  keyuanDialog.chanquanXingbieComboBox->currentText(),
                                  keyuanDialog.fangwuMianjiDoubleSpinBox->text().toFloat(),
                                  keyuanDialog.xinjiuChengduComboBox->currentText(),
                                  keyuanDialog.suozaiLoucengSpinBox->text().toInt(),
                                  keyuanDialog.zhuangxiuBiaozhunComboBox->currentText(),
                                  keyuanDialog.loucengZongshuSpinBox->text().toInt(),
                                  keyuanDialog.yixiangDizhiLineEdit->text(),
                                  keyuanDialog.chufangCheckBox->isChecked(),
                                  keyuanDialog.chuangCheckBox->isChecked(),
                                  keyuanDialog.jiajuCheckBox->isChecked(),
                                  keyuanDialog.youxianDianshiCheckBox->isChecked(),
                                  keyuanDialog.kuaidaiwangCheckBox->isChecked(),
                                  keyuanDialog.dianhuaCheckBox->isChecked(),
                                  keyuanDialog.reshuiqiCheckBox->isChecked(),
                                  keyuanDialog.dianshijiCheckBox->isChecked(),
                                  keyuanDialog.kongtiaoCheckBox->isChecked(),
                                  keyuanDialog.xiyijiCheckBox->isChecked(),
                                  keyuanDialog.bingxiangCheckBox->isChecked(),
                                  keyuanDialog.meiqiCheckBox->isChecked(),
                                  keyuanDialog.nuanqiCheckBox->isChecked(),
                                  keyuanDialog.qichekuCheckBox->isChecked(),
                                  keyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->toPlainText(),
                                  keyuanDialog.yezhuXingmingLineEdit->text(),
                                  keyuanDialog.lianxiDianhuaLineEdit->text(),
                                  keyuanDialog.lianxiShoujiLineEdit->text(),
                                  keyuanDialog.yezhuShuomingLineEdit->text());
        }
        this->dbcon->hezukehu->select();

        break;
    }
}

void MainWindow::on_deletePushButton_0_clicked()
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
void MainWindow::on_deletePushButton_3_clicked()
{
    int kehubianhao;
    switch(this->stackedWidget->currentIndex())
    {
    case 3:
        this->tableView_3->selectRow(this->tableView_3->currentIndex().row());
        kehubianhao = this->tableView_3->currentIndex().data().toInt();
        this->dbcon->deleteFromQiugouKehu(kehubianhao);
        this->dbcon->qiugoukehu->select();
        break;
    case 4:
        this->tableView_4->selectRow(this->tableView_4->currentIndex().row());
        kehubianhao = this->tableView_4->currentIndex().data().toInt();
        this->dbcon->deleteFromQiuzuKehu(kehubianhao);
        this->dbcon->qiuzukehu->select();
        break;
    case 5:
        this->tableView_5->selectRow(this->tableView_5->currentIndex().row());
        kehubianhao = this->tableView_5->currentIndex().data().toInt();
        this->dbcon->deleteFromHezuKehu(kehubianhao);
        this->dbcon->hezukehu->select();
        break;

    }
}

void MainWindow::on_actionTianjiaKehu_triggered()
{
    KeyuanDialog keyuanDialog(this, this->dbcon);
    switches1:
    switch(this->stackedWidget->currentIndex()){
    case 3:
        keyuanDialog.kehuXuqiuComboBox->setCurrentIndex(0);
        keyuanDialog.kehuXuqiuComboBox->setEnabled(false);
        if(keyuanDialog.exec() == QDialog::Accepted){
            dbcon->insertQiugoukehu(keyuanDialog.kehuBianhaoSpinBox->text().toInt(),
                                    keyuanDialog.dangqianZhuangtaiComboBox->currentText(),
                                    keyuanDialog.zhiyeGuwenComboBox->currentText(),
                                    keyuanDialog.kehuLaiyuanComboBox->currentText(),
                                    keyuanDialog.suozaiChengquComboBox->currentText(),
                                    keyuanDialog.fangwuJiageSpinBox->text().toInt(),
                                    keyuanDialog.fangwuLeixingComboBox->currentText(),
                                    keyuanDialog.chanquanXingbieComboBox->currentText(),
                                    keyuanDialog.fangwuMianjiDoubleSpinBox->text().toFloat(),
                                    keyuanDialog.xinjiuChengduComboBox->currentText(),
                                    keyuanDialog.suozaiLoucengSpinBox->text().toInt(),
                                    keyuanDialog.zhuangxiuBiaozhunComboBox->currentText(),
                                    keyuanDialog.loucengZongshuSpinBox->text().toInt(),
                                    keyuanDialog.yixiangDizhiLineEdit->text(),
                                    keyuanDialog.chufangCheckBox->isChecked(),
                                    keyuanDialog.chuangCheckBox->isChecked(),
                                    keyuanDialog.jiajuCheckBox->isChecked(),
                                    keyuanDialog.youxianDianshiCheckBox->isChecked(),
                                    keyuanDialog.kuaidaiwangCheckBox->isChecked(),
                                    keyuanDialog.dianhuaCheckBox->isChecked(),
                                    keyuanDialog.reshuiqiCheckBox->isChecked(),
                                    keyuanDialog.dianshijiCheckBox->isChecked(),
                                    keyuanDialog.kongtiaoCheckBox->isChecked(),
                                    keyuanDialog.xiyijiCheckBox->isChecked(),
                                    keyuanDialog.bingxiangCheckBox->isChecked(),
                                    keyuanDialog.meiqiCheckBox->isChecked(),
                                    keyuanDialog.nuanqiCheckBox->isChecked(),
                                    keyuanDialog.qichekuCheckBox->isChecked(),
                                    keyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->toPlainText(),
                                    keyuanDialog.yezhuXingmingLineEdit->text(),
                                    keyuanDialog.lianxiDianhuaLineEdit->text(),
                                    keyuanDialog.lianxiShoujiLineEdit->text(),
                                    keyuanDialog.yezhuShuomingLineEdit->text());
        }
        this->dbcon->qiugoukehu->select();

        break;
    case 4:

        keyuanDialog.kehuXuqiuComboBox->setCurrentIndex(1);
        keyuanDialog.kehuXuqiuComboBox->setEnabled(false);
        if(keyuanDialog.exec() == QDialog::Accepted){
            dbcon->insertQiuzukehu(keyuanDialog.kehuBianhaoSpinBox->text().toInt(),
                                   keyuanDialog.dangqianZhuangtaiComboBox->currentText(),
                                   keyuanDialog.zhiyeGuwenComboBox->currentText(),
                                   keyuanDialog.kehuLaiyuanComboBox->currentText(),
                                   keyuanDialog.suozaiChengquComboBox->currentText(),
                                   keyuanDialog.fangwuJiageSpinBox->text().toInt(),
                                   keyuanDialog.fangwuLeixingComboBox->currentText(),
                                   keyuanDialog.chanquanXingbieComboBox->currentText(),
                                   keyuanDialog.fangwuMianjiDoubleSpinBox->text().toFloat(),
                                   keyuanDialog.xinjiuChengduComboBox->currentText(),
                                   keyuanDialog.suozaiLoucengSpinBox->text().toInt(),
                                   keyuanDialog.zhuangxiuBiaozhunComboBox->currentText(),
                                   keyuanDialog.loucengZongshuSpinBox->text().toInt(),
                                   keyuanDialog.yixiangDizhiLineEdit->text(),
                                   keyuanDialog.chufangCheckBox->isChecked(),
                                   keyuanDialog.chuangCheckBox->isChecked(),
                                   keyuanDialog.jiajuCheckBox->isChecked(),
                                   keyuanDialog.youxianDianshiCheckBox->isChecked(),
                                   keyuanDialog.kuaidaiwangCheckBox->isChecked(),
                                   keyuanDialog.dianhuaCheckBox->isChecked(),
                                   keyuanDialog.reshuiqiCheckBox->isChecked(),
                                   keyuanDialog.dianshijiCheckBox->isChecked(),
                                   keyuanDialog.kongtiaoCheckBox->isChecked(),
                                   keyuanDialog.xiyijiCheckBox->isChecked(),
                                   keyuanDialog.bingxiangCheckBox->isChecked(),
                                   keyuanDialog.meiqiCheckBox->isChecked(),
                                   keyuanDialog.nuanqiCheckBox->isChecked(),
                                   keyuanDialog.qichekuCheckBox->isChecked(),
                                   keyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->toPlainText(),
                                   keyuanDialog.yezhuXingmingLineEdit->text(),
                                   keyuanDialog.lianxiDianhuaLineEdit->text(),
                                   keyuanDialog.lianxiShoujiLineEdit->text(),
                                   keyuanDialog.yezhuShuomingLineEdit->text());
        }
        this->dbcon->qiuzukehu->select();


        break;
    case 5:

        keyuanDialog.kehuXuqiuComboBox->setCurrentIndex(2);
        keyuanDialog.kehuXuqiuComboBox->setEnabled(false);
        keyuanDialog.asHezu();
        if(keyuanDialog.exec() == QDialog::Accepted){
            dbcon->insertHezukehu(keyuanDialog.kehuBianhaoSpinBox->text().toInt(),
                                  keyuanDialog.dangqianZhuangtaiComboBox->currentText(),
                                  keyuanDialog.zhiyeGuwenComboBox->currentText(),
                                  keyuanDialog.kehuLaiyuanComboBox->currentText(),
                                  keyuanDialog.suozaiChengquComboBox->currentText(),
                                  keyuanDialog.fangwuJiageSpinBox->text().toInt(),
                                  keyuanDialog.fangwuLeixingComboBox->currentText(),
                                  keyuanDialog.chanquanXingbieComboBox->currentText(),
                                  keyuanDialog.fangwuMianjiDoubleSpinBox->text().toFloat(),
                                  keyuanDialog.xinjiuChengduComboBox->currentText(),
                                  keyuanDialog.suozaiLoucengSpinBox->text().toInt(),
                                  keyuanDialog.zhuangxiuBiaozhunComboBox->currentText(),
                                  keyuanDialog.loucengZongshuSpinBox->text().toInt(),
                                  keyuanDialog.yixiangDizhiLineEdit->text(),
                                  keyuanDialog.chufangCheckBox->isChecked(),
                                  keyuanDialog.chuangCheckBox->isChecked(),
                                  keyuanDialog.jiajuCheckBox->isChecked(),
                                  keyuanDialog.youxianDianshiCheckBox->isChecked(),
                                  keyuanDialog.kuaidaiwangCheckBox->isChecked(),
                                  keyuanDialog.dianhuaCheckBox->isChecked(),
                                  keyuanDialog.reshuiqiCheckBox->isChecked(),
                                  keyuanDialog.dianshijiCheckBox->isChecked(),
                                  keyuanDialog.kongtiaoCheckBox->isChecked(),
                                  keyuanDialog.xiyijiCheckBox->isChecked(),
                                  keyuanDialog.bingxiangCheckBox->isChecked(),
                                  keyuanDialog.meiqiCheckBox->isChecked(),
                                  keyuanDialog.nuanqiCheckBox->isChecked(),
                                  keyuanDialog.qichekuCheckBox->isChecked(),
                                  keyuanDialog.fangyuanXiangxiXinxiPlainTextEdit->toPlainText(),
                                  keyuanDialog.yezhuXingmingLineEdit->text(),
                                  keyuanDialog.lianxiDianhuaLineEdit->text(),
                                  keyuanDialog.lianxiShoujiLineEdit->text(),
                                  keyuanDialog.yezhuShuomingLineEdit->text());
        }
        this->dbcon->hezukehu->select();


        break;
        default:
        this->stackedWidget->setCurrentIndex(3);
        goto switches1;
        break;

    }
}

void MainWindow::on_tableView_0_clicked(){//set tabWidget data;
    qDebug() << "clicked";
    int fangwubianhao, kehubianhao, fangwujiage, jianzhuniandai, suozailouceng, loucengzongshu;
    QString kehulaiyuan, yixiangdizhi, xinjiuchengdu, dangqianzhuangtai, zhiyeguwen, fangwulaiyuan, suozaichengqu, fangwuleixing, chanquanxingbie,zhuangxiubiaozhun, jutidizhi, fangyuanxiangxixinxi, yezhuxingming, lianxidianghua, lianxishouji, yezhushuoming;
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
        this->dbcon->genjinchushou->setFilter(" bianhao = " + str.setNum(fangwubianhao));
        this->genjinTableView_0->resizeColumnsToContents();
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
        this->dbcon->genjinchuzu->setFilter(" bianhao = " + str.setNum(fangwubianhao));
        this->genjinTableView_1->resizeColumnsToContents();

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
        this->dbcon->genjinhezufang->setFilter(" bianhao = " + str.setNum(fangwubianhao));
        this->genjinTableView_2->resizeColumnsToContents();

        break;
    case 3:
        kehubianhao = this->dbcon->qiugoukehu->record(this->tableView_3->currentIndex().row()).value(0).toInt();
        this->dbcon->getQiugouKehu(kehubianhao, &dangqianzhuangtai, &zhiyeguwen, &kehulaiyuan, &suozaichengqu,&fangwujiage, &fangwuleixing, &chanquanxingbie, &fangwumianji, & xinjiuchengdu, &suozailouceng, &zhuangxiubiaozhun, &loucengzongshu, &yixiangdizhi,
                                   &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &fangyuanxiangxixinxi,&yezhuxingming, &lianxidianghua, &lianxishouji, & yezhushuoming);
        this->jiageLabel_3->setText(str.setNum(fangwujiage));
        this->mianjiLabel_3->setText(str.setNum(fangwumianji));
        this->chufangLabel_3->setVisible(a);
        this->chuangLabel_3->setVisible(b);
        this->jiajuLabel_3->setVisible(c);
        this->youxianLabel_3->setVisible(d);
        this->kuandaiLabel_3->setVisible(e);
        this->dianhuaLabel_3->setVisible(f);
        this->reshuiqiLabel_3->setVisible(g);
        this->dianshiLabel_3->setVisible(h);
        this->kongtiaoLabel_3->setVisible(i);
        this->xiyijiLabel_3->setVisible(j);
        this->bingxiangLabel_3->setVisible(k);
        this->meiqiLabel_3->setVisible(l);
        this->nuanqiLabel_3->setVisible(m);
        this->chekuLabel_3->setVisible(n);
        this->dizhiLabel_3->setText(yixiangdizhi);

        this->xingmingLabel_3->setText(yezhuxingming);
        this->lianxiDianhuaLabel_3->setText(lianxidianghua);
        this->shoujiLabel_3->setText(lianxishouji);
        this->beizhuLabel_3->setText(yezhushuoming);
        this->dbcon->genjinqiugou->setFilter(" bianhao = " + str.setNum(kehubianhao));
        this->genjinTableView_3->resizeColumnsToContents();

        break;
    case 4:
        kehubianhao = this->dbcon->qiuzukehu->record(this->tableView_4->currentIndex().row()).value(0).toInt();
        this->dbcon->getQiuzuKehu(kehubianhao, &dangqianzhuangtai, &zhiyeguwen, &kehulaiyuan, &suozaichengqu,&fangwujiage, &fangwuleixing, &chanquanxingbie, &fangwumianji, & xinjiuchengdu, &suozailouceng, &zhuangxiubiaozhun, &loucengzongshu, &yixiangdizhi,
                                  &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &fangyuanxiangxixinxi,&yezhuxingming, &lianxidianghua, &lianxishouji, & yezhushuoming);
        this->jiageLabel_4->setText(str.setNum(fangwujiage));
        this->mianjiLabel_4->setText(str.setNum(fangwumianji));
        this->chufangLabel_4->setVisible(a);
        this->chuangLabel_4->setVisible(b);
        this->jiajuLabel_4->setVisible(c);
        this->youxianLabel_4->setVisible(d);
        this->kuandaiLabel_4->setVisible(e);
        this->dianhuaLabel_4->setVisible(f);
        this->reshuiqiLabel_4->setVisible(g);
        this->dianshiLabel_4->setVisible(h);
        this->kongtiaoLabel_4->setVisible(i);
        this->xiyijiLabel_4->setVisible(j);
        this->bingxiangLabel_4->setVisible(k);
        this->meiqiLabel_4->setVisible(l);
        this->nuanqiLabel_4->setVisible(m);
        this->chekuLabel_4->setVisible(n);
        this->dizhiLabel_4->setText(yixiangdizhi);

        this->xingmingLabel_4->setText(yezhuxingming);
        this->lianxiDianhuaLabel_4->setText(lianxidianghua);
        this->shoujiLabel_4->setText(lianxishouji);
        this->beizhuLabel_4->setText(yezhushuoming);
        this->dbcon->genjinqiuzu->setFilter(" bianhao = " + str.setNum(kehubianhao));
        this->genjinTableView_4->resizeColumnsToContents();

        break;
    case 5:        
        kehubianhao = this->dbcon->hezukehu->record(this->tableView_5->currentIndex().row()).value(0).toInt();
        this->dbcon->getHezuKehu(kehubianhao, &dangqianzhuangtai, &zhiyeguwen, &kehulaiyuan, &suozaichengqu,&fangwujiage, &fangwuleixing, &chanquanxingbie, &fangwumianji, & xinjiuchengdu, &suozailouceng, &zhuangxiubiaozhun, &loucengzongshu, &yixiangdizhi,
                                 &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &fangyuanxiangxixinxi,&yezhuxingming, &lianxidianghua, &lianxishouji, & yezhushuoming);
        this->jiageLabel_5->setText(str.setNum(fangwujiage));
        this->mianjiLabel_5->setText(str.setNum(fangwumianji));
        this->chufangLabel_5->setVisible(a);
        this->chuangLabel_5->setVisible(b);
        this->jiajuLabel_5->setVisible(c);
        this->youxianLabel_5->setVisible(d);
        this->kuandaiLabel_5->setVisible(e);
        this->dianhuaLabel_5->setVisible(f);
        this->reshuiqiLabel_5->setVisible(g);
        this->dianshiLabel_5->setVisible(h);
        this->kongtiaoLabel_5->setVisible(i);
        this->xiyijiLabel_5->setVisible(j);
        this->bingxiangLabel_5->setVisible(k);
        this->meiqiLabel_5->setVisible(l);
        this->nuanqiLabel_5->setVisible(m);
        this->chekuLabel_5->setVisible(n);
        this->dizhiLabel_5->setText(yixiangdizhi);

        this->xingmingLabel_5->setText(yezhuxingming);
        this->lianxiDianhuaLabel_5->setText(lianxidianghua);
        this->shoujiLabel_5->setText(lianxishouji);
        this->beizhuLabel_5->setText(yezhushuoming);
        this->dbcon->genjinhezuke->setFilter(" bianhao = " + str.setNum(kehubianhao));
        this->genjinTableView_5->resizeColumnsToContents();

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
void MainWindow::on_tableView_3_clicked()
{
    on_tableView_0_clicked();
}
void MainWindow::on_tableView_4_clicked()
{
    on_tableView_0_clicked();
}
void MainWindow::on_tableView_5_clicked()
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
    if(text == tr("不限")){
        this->filterChengqu_3->clear();
        this->filterChengqu_3->append(tr(" 1 "));
    }else
    {
        this->filterChengqu_3->clear();
        this->filterChengqu_3->append(tr(" suozaichengqu = '")).append(text).append(" ' ");
    }
    this->dbcon->qiugoukehu->setFilter (*(this->filterChengqu_3) + tr("and") + *(this->filterLeixing_3) +tr("and") +*(this->filterZhuangtai_3));
    this->dbcon->qiugoukehu->select();
}
void MainWindow::on_chengquComboBox_4_currentIndexChanged(const QString &text)
{
    qDebug() << text;
    if(text == tr("不限")){
        this->filterChengqu_4->clear();
        this->filterChengqu_4->append(tr(" 1 "));
    }else
    {
        this->filterChengqu_4->clear();
        this->filterChengqu_4->append(tr(" suozaichengqu = '")).append(text).append(" ' ");
    }
    this->dbcon->qiuzukehu->setFilter (*(this->filterChengqu_4) + tr("and") + *(this->filterLeixing_4) +tr("and") +*(this->filterZhuangtai_4));
    this->dbcon->qiuzukehu->select();
}
void MainWindow::on_chengquComboBox_5_currentIndexChanged(const QString &text)
{
    qDebug() << text;
    if(text == tr("不限")){
        this->filterChengqu_5->clear();
        this->filterChengqu_5->append(tr(" 1 "));
    }else
    {
        this->filterChengqu_5->clear();
        this->filterChengqu_5->append(tr(" suozaichengqu = '")).append(text).append(" ' ");
    }
    this->dbcon->hezukehu->setFilter (*(this->filterChengqu_5) + tr("and") + *(this->filterLeixing_5) +tr("and") +*(this->filterZhuangtai_5));
    this->dbcon->hezukehu->select();
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
    if(text == tr("不限")){
        this->filterLeixing_3->clear();
        this->filterLeixing_3->append(tr(" 1 "));
    }else
    {
        this->filterLeixing_3->clear();
        this->filterLeixing_3->append(tr(" fangwuleixing = '")).append(text).append(" ' ");
    }

    this->dbcon->qiugoukehu->setFilter (*(this->filterChengqu_3) + tr("and") + *(this->filterLeixing_3) +tr("and") +*(this->filterZhuangtai_3));
    this->dbcon->qiugoukehu->select();
}
void MainWindow::on_fangwuLeixingComboBox_4_currentIndexChanged(const QString &text)
{
    qDebug() << text;
    if(text == tr("不限")){
        this->filterLeixing_4->clear();
        this->filterLeixing_4->append(tr(" 1 "));
    }else
    {
        this->filterLeixing_4->clear();
        this->filterLeixing_4->append(tr(" fangwuleixing = '")).append(text).append(" ' ");
    }

    this->dbcon->qiuzukehu->setFilter (*(this->filterChengqu_4) + tr("and") + *(this->filterLeixing_4) +tr("and") +*(this->filterZhuangtai_4));
    this->dbcon->qiuzukehu->select();
}
void MainWindow::on_fangwuLeixingComboBox_5_currentIndexChanged(const QString &text)
{
    qDebug() << text;
    if(text == tr("不限")){
        this->filterLeixing_5->clear();
        this->filterLeixing_5->append(tr(" 1 "));
    }else
    {
        this->filterLeixing_5->clear();
        this->filterLeixing_5->append(tr(" fangwuleixing = '")).append(text).append(" ' ");
    }

    this->dbcon->hezukehu->setFilter (*(this->filterChengqu_5) + tr("and") + *(this->filterLeixing_5) +tr("and") +*(this->filterZhuangtai_5));
    this->dbcon->hezukehu->select();
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
    if(text == tr("不限")){
        this->filterZhuangtai_3->clear();
        this->filterZhuangtai_3->append(tr(" 1 "));
    }else
    {
        this->filterZhuangtai_3->clear();
        this->filterZhuangtai_3->append(tr(" dangqianzhuangtai = '")).append(text).append(" ' ");
    }

    this->dbcon->qiugoukehu->setFilter (*(this->filterChengqu_3) + tr("and") + *(this->filterLeixing_3) +tr("and") +*(this->filterZhuangtai_3));
    this->dbcon->qiugoukehu->select();
}
void MainWindow::on_kehuZhuangtaiComboBox_4_currentIndexChanged(const QString &text){
    qDebug() << text;
    if(text == tr("不限")){
        this->filterZhuangtai_4->clear();
        this->filterZhuangtai_4->append(tr(" 1 "));
    }else
    {
        this->filterZhuangtai_4->clear();
        this->filterZhuangtai_4->append(tr(" dangqianzhuangtai = '")).append(text).append(" ' ");
    }

    this->dbcon->qiuzukehu->setFilter (*(this->filterChengqu_4) + tr("and") + *(this->filterLeixing_4) +tr("and") +*(this->filterZhuangtai_4));
    this->dbcon->qiuzukehu->select();
}
void MainWindow::on_kehuZhuangtaiComboBox_5_currentIndexChanged(const QString &text){
    qDebug() << text;
    if(text == tr("不限")){
        this->filterZhuangtai_5->clear();
        this->filterZhuangtai_5->append(tr(" 1 "));
    }else
    {
        this->filterZhuangtai_5->clear();
        this->filterZhuangtai_5->append(tr(" dangqianzhuangtai = '")).append(text).append(" ' ");
    }

    this->dbcon->hezukehu->setFilter (*(this->filterChengqu_5) + tr("and") + *(this->filterLeixing_5) +tr("and") +*(this->filterZhuangtai_5));
    this->dbcon->hezukehu->select();
}

void MainWindow::on_actionQianyueChengjiao_triggered()
{
    ChengjiaoQianyueDialog chengjiaodialog(this, this->dbcon);
    chengjiaodialog.exec();
}

void MainWindow::on_genjin_addPushButton_0_clicked()
{
    QSqlTableModel * model = this->dbcon->genjinchushou;
    int row = model->rowCount();
    model->insertRows(row, 1);
    model->setData(model->index(row, 0), this->dbcon->chushoufangyuan->record(this->tableView_0->currentIndex().row()).value(0).toInt());
    model->setData(model->index(row, 1), this->rcomboBox_0->currentText());
    model->setData(model->index(row, 2), this->fcomboBox_0->currentText());
    model->setData(model->index(row, 3), this->nlineEdit_0->text());
    model->submitAll();
}

void MainWindow::on_genjin_modifyPushButton_0_clicked()
{
    QSqlTableModel * model = this->dbcon->genjinchushou;
    int row = this->genjinTableView_0->currentIndex().row();
    model->setData(model->index(row, 1), this->rcomboBox_0->currentText());
    model->setData(model->index(row, 2), this->fcomboBox_0->currentText());
    model->setData(model->index(row, 3), this->nlineEdit_0->text());
    model->submitAll();
}

void MainWindow::on_genjin_deletePushButton_0_clicked()
{
    qDebug() << this->genjinTableView_0->currentIndex().row() << this->dbcon->genjinchushou->removeRow(this->genjinTableView_0->currentIndex().row());
}


void MainWindow::on_genjin_addPushButton_1_clicked()
{
    QSqlTableModel * model = this->dbcon->genjinchuzu;
    int row = model->rowCount();
    model->insertRows(row, 1);
    model->setData(model->index(row, 0), this->dbcon->chuzufangyuan->record(this->tableView_0->currentIndex().row()).value(0).toInt());
    model->setData(model->index(row, 1), this->rcomboBox_0->currentText());
    model->setData(model->index(row, 2), this->fcomboBox_0->currentText());
    model->setData(model->index(row, 3), this->nlineEdit_0->text());
    model->submitAll();
}

void MainWindow::on_genjin_modifyPushButton_1_clicked()
{
    
}

void MainWindow::on_genjin_deletePushButton_1_clicked()
{
    this->dbcon->genjinchuzu->removeRow(this->genjinTableView_1->currentIndex().row());
}


void MainWindow::on_genjin_addPushButton_2_clicked()
{
    QSqlTableModel * model = this->dbcon->genjinhezufang;
    int row = model->rowCount();
    model->insertRows(row, 1);
    model->setData(model->index(row, 0), this->dbcon->hezufangyuan->record(this->tableView_0->currentIndex().row()).value(0).toInt());
    model->setData(model->index(row, 1), this->rcomboBox_0->currentText());
    model->setData(model->index(row, 2), this->fcomboBox_0->currentText());
    model->setData(model->index(row, 3), this->nlineEdit_0->text());
    model->submitAll();

}

void MainWindow::on_genjin_modifyPushButton_2_clicked()
{

    qDebug()<<"cli";
}

void MainWindow::on_genjin_deletePushButton_2_clicked()
{
    this->dbcon->genjinhezufang->removeRow(this->genjinTableView_2->currentIndex().row());
}


void MainWindow::on_genjin_addPushButton_3_clicked()
{
    QSqlTableModel * model = this->dbcon->genjinqiugou;
    int row = model->rowCount();
    model->insertRows(row, 1);
    model->setData(model->index(row, 0), this->dbcon->qiugoukehu->record(this->tableView_0->currentIndex().row()).value(0).toInt());
    model->setData(model->index(row, 1), this->rcomboBox_0->currentText());
    model->setData(model->index(row, 2), this->fcomboBox_0->currentText());
    model->setData(model->index(row, 3), this->nlineEdit_0->text());
    model->submitAll();

}

void MainWindow::on_genjin_modifyPushButton_3_clicked()
{

    qDebug()<<"cli";
}

void MainWindow::on_genjin_deletePushButton_3_clicked()
{
    this->dbcon->genjinqiugou->removeRow(this->genjinTableView_3->currentIndex().row());
}

void MainWindow::on_genjin_addPushButton_4_clicked()
{
    QSqlTableModel * model = this->dbcon->genjinqiuzu;
    int row = model->rowCount();
    model->insertRows(row, 1);
    model->setData(model->index(row, 0), this->dbcon->qiuzukehu->record(this->tableView_0->currentIndex().row()).value(0).toInt());
    model->setData(model->index(row, 1), this->rcomboBox_0->currentText());
    model->setData(model->index(row, 2), this->fcomboBox_0->currentText());
    model->setData(model->index(row, 3), this->nlineEdit_0->text());
    model->submitAll();

}

void MainWindow::on_genjin_modifyPushButton_4_clicked()
{

    qDebug()<<"cli";
}

void MainWindow::on_genjin_deletePushButton_4_clicked()
{
    this->dbcon->genjinqiuzu->removeRow(this->genjinTableView_4->currentIndex().row());
}


void MainWindow::on_genjin_addPushButton_5_clicked()
{
    QSqlTableModel * model = this->dbcon->genjinhezuke;
    int row = model->rowCount();
    model->insertRows(row, 1);
    model->setData(model->index(row, 0), this->dbcon->hezukehu->record(this->tableView_0->currentIndex().row()).value(0).toInt());
    model->setData(model->index(row, 1), this->rcomboBox_0->currentText());
    model->setData(model->index(row, 2), this->fcomboBox_0->currentText());
    model->setData(model->index(row, 3), this->nlineEdit_0->text());
    model->submitAll();

}

void MainWindow::on_genjin_modifyPushButton_5_clicked()
{

    qDebug()<<"cli";
}

void MainWindow::on_genjin_deletePushButton_5_clicked()
{
    this->dbcon->genjinhezuke->removeRow(this->genjinTableView_5->currentIndex().row());
}

void MainWindow::on_genjinTableView_0_clicked(){
    QSqlRecord record = this->dbcon->genjinchushou->record(this->genjinTableView_0->currentIndex().row());
    QComboBox * combo;
    QString * value;
    int a;
    combo = this->rcomboBox_0;
    value = &(record.value(1).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);

    combo = this->fcomboBox_0;
    value = &(record.value(2).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);
    this->nlineEdit_0->setText(record.value(3).toString());

}
void MainWindow::on_genjinTableView_1_clicked(){
    QSqlRecord record = this->dbcon->genjinchuzu->record(this->genjinTableView_1->currentIndex().row());
    QComboBox * combo;
    QString * value;
    int a;
    combo = this->rcomboBox_1;
    value = &(record.value(1).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);

    combo = this->fcomboBox_1;
    value = &(record.value(2).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);
    this->nlineEdit_1->setText(record.value(3).toString());
}
void MainWindow::on_genjinTableView_2_clicked(){
    QSqlRecord record = this->dbcon->genjinhezufang->record(this->genjinTableView_2->currentIndex().row());
    QComboBox * combo;
    QString * value;
    int a;
    combo = this->rcomboBox_2;
    value = &(record.value(1).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);

    combo = this->fcomboBox_2;
    value = &(record.value(2).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);
    this->nlineEdit_2->setText(record.value(3).toString());
}
void MainWindow::on_genjinTableView_3_clicked(){
    QSqlRecord record = this->dbcon->genjinqiugou->record(this->genjinTableView_3->currentIndex().row());
    QComboBox * combo;
    QString * value;
    int a;
    combo = this->rcomboBox_3;
    value = &(record.value(1).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);

    combo = this->fcomboBox_3;
    value = &(record.value(2).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);
    this->nlineEdit_3->setText(record.value(3).toString());
}
void MainWindow::on_genjinTableView_4_clicked(){
    QSqlRecord record = this->dbcon->genjinqiuzu->record(this->genjinTableView_4->currentIndex().row());
    QComboBox * combo;
    QString * value;
    int a;
    combo = this->rcomboBox_4;
    value = &(record.value(1).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);

    combo = this->fcomboBox_4;
    value = &(record.value(2).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);
    this->nlineEdit_4->setText(record.value(3).toString());
}
void MainWindow::on_genjinTableView_5_clicked(){
    QSqlRecord record = this->dbcon->genjinhezuke->record(this->genjinTableView_5->currentIndex().row());
    QComboBox * combo;
    QString * value;
    int a;
    combo = this->rcomboBox_5;
    value = &(record.value(1).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);

    combo = this->fcomboBox_5;
    value = &(record.value(2).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);
    this->nlineEdit_5->setText(record.value(3).toString());
}
