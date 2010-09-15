#ifndef YUANGONGGUANLIDIALOG_H
#define YUANGONGGUANLIDIALOG_H

#include <QtGui/QDialog>
#include "ui_yuangongguanlidialog.h"
#include <QtSql/QSqlTableModel>

class DateDelegate;
class ComboDelegate;
class YuangongGuanliDialog : public QDialog , public Ui::yuangongGuanliDialog
{
    Q_OBJECT
public:
    YuangongGuanliDialog(QWidget * parent);
    ~YuangongGuanliDialog();
    void setTableModel(QSqlTableModel * tableModel);
protected:
    QSqlTableModel *tableModel;

private slots:
    void on_addPushButton_clicked();
    void on_deletePushButton_clicked();
    void on_modifyPushButton_clicked();
private:
    DateDelegate * dateDelegate;
    ComboDelegate * xingbieDelegate;
    ComboDelegate * xueliDelegate;
    ComboDelegate * hunyinZhuangkuangDelegate;
};

#endif // YUANGONGGUANLIDIALOG_H
