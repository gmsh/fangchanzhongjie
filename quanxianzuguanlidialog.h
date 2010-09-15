#ifndef QUANXIANZUGUANLIDIALOG_H
#define QUANXIANZUGUANLIDIALOG_H

#include "ui_quanxianzuguanlidialog.h"
#include <QtGui/QDialog>

class DBConnect;
class QIcon;
class QuanxianzuGuanliDialog
    :public QDialog, public Ui::quanxianzuGuanliDialog
{
    Q_OBJECT
public:
    QuanxianzuGuanliDialog(QWidget * parent, DBConnect * dbcon);
    ~QuanxianzuGuanliDialog();
private slots:    
    void refreshList();
    void on_addPushButton_clicked();
    void on_modifyPushButton_clicked();
    void on_deletePushButton_clicked();
private:
    DBConnect * dbcon;
    QIcon * quanxianzuIcon;
};

#endif // QUANXIANZUGUANLIDIALOG_H
