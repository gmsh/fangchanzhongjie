#ifndef YUANGONGGUANLIDIALOG_H
#define YUANGONGGUANLIDIALOG_H

#include <QtGui/QDialog>
#include "ui_yuangongguanlidialog.h"
#include <QtSql/QSqlTableModel>

class DateDelegate;
class ComboDelegate;
class DBConnect;
class YuangongGuanliDialog : public QDialog , public Ui::yuangongGuanliDialog
{
    Q_OBJECT
public:
    YuangongGuanliDialog(QWidget * parent = 0, DBConnect * dbcon = 0);
    ~YuangongGuanliDialog();
protected:
    QSqlTableModel *tableModel;

private slots:
    void on_addPushButton_clicked();
    void on_deletePushButton_clicked();
    void on_modifyPushButton_clicked();
private:
    void setTableModel(QSqlTableModel * tableModel);
    DateDelegate * dateDelegate;
    ComboDelegate * xingbieDelegate;
    ComboDelegate * xueliDelegate;
    ComboDelegate * hunyinZhuangkuangDelegate;
    ComboDelegate * suozaiQuanxianzuDelegate;
    DBConnect * dbcon;
};

#endif // YUANGONGGUANLIDIALOG_H
