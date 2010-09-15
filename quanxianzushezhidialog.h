#ifndef QUANXIANZUSHEZHIDIALOG_H
#define QUANXIANZUSHEZHIDIALOG_H

#include "ui_quanxianzushezhidialog.h"
#include <QtGui/QDialog>

class QStandardItem;
class QIcon;
class DBConnect;
class QuanxianzuShezhiDialog
    :public QDialog, public Ui::quanxianzuShezhiDialog
{
    Q_OBJECT
public:
    QuanxianzuShezhiDialog(QWidget * parent = 0, DBConnect * dbcon = 0,
                           bool a = false,
                           bool b = false,
                           bool c = false,
                           bool d = false,
                           bool e = false,
                           bool f = false,
                           bool g = false,
                           bool h = false,
                           bool i = false,
                           bool j = false,
                           bool k = false,
                           bool l = false, QString * mingcheng = 0);
    ~QuanxianzuShezhiDialog();
public slots:
    void accept();
protected:
    
    QStandardItem * fangyuanGuanli;
    QStandardItem * chushouFangyuan;
    QStandardItem * chuzuFangyuan;
    QStandardItem * hezuFangyuan;
    QStandardItem * keyuanGuanli;
    QStandardItem * qiuzuKehu;
    QStandardItem * qiugouKehu;
    QStandardItem * hezuKehu;
    QStandardItem * genjinGuanli;
    QStandardItem * fangyuanGenjin;
    QStandardItem * keyuanGenjin;
    QStandardItem * qianyueGuanli;
    QStandardItem * xitongshezhi;
    QStandardItem * yuangongGuanli;
    QStandardItem * quanxianzuguanli;
    QStandardItem * canshuShezhi;
    QIcon * fangyuan;
    QIcon * keyuan;
    QIcon * genjin;
    QIcon * qianyue;
    QIcon * xitong;
    QIcon * yuangong;
    QIcon * quanxianzu;
    
    DBConnect * dbcon;
};

#endif // QUANXIANZUSHEZHIDIALOG_H
