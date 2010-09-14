#ifndef CANSHUGUANLIDIALOG_H
#define CANSHUGUANLIDIALOG_H

#include <QtGui/QDialog>
#include <QtGui/QTreeWidgetItem>
#include <QtSql/QSqlTableModel>
#include "ui_canshuguanlidialog.h"
#include "dbconnect.h"
//class QSqlTableModel;
class CanshuGuanliDialog
    :public QDialog, public Ui::canshuGuanliiDialog
{
    Q_OBJECT
public:
    CanshuGuanliDialog(QWidget * parent, DBConnect * dbcon);
    ~CanshuGuanliDialog();
private slots:
    void on_canshuFenleiTreeWidget_itemActivated(QTreeWidgetItem * item, int cl);
    void on_addPushButton_clicked();
    void on_modifyPushButton_clicked();
    void on_deletePushButton_clicked();
private:
    DBConnect * dbcon;
};

#endif // CANSHUGUANLIDIALOG_H
