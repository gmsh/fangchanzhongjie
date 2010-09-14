#ifndef QUANXIANZUSHEZHIDIALOG_H
#define QUANXIANZUSHEZHIDIALOG_H

#include "ui_quanxianzushezhidialog.h"
#include <QtGui/QDialog>

class QStandardItem;
class QIcon;
class QuanxianzuShezhiDialog
    :public QDialog, public Ui::quanxianzuShezhiDialog
{
    Q_OBJECT
public:
    QuanxianzuShezhiDialog(QWidget * parent = 0);
    ~QuanxianzuShezhiDialog();
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
    QIcon * fangyuan;
    QIcon * keyuan;
    QIcon * genjin;
    QIcon * qianyue;
    QIcon * xitong;
    QIcon * yuangong;
    QIcon * quanxianzu;
};

#endif // QUANXIANZUSHEZHIDIALOG_H
