#ifndef CHENGJIAOQIANYUEDIALOG_H
#define CHENGJIAOQIANYUEDIALOG_H

#include <QDialog>
#include "ui_qianyuechengjiaodialog.h"

class DBConnect;
class ChengjiaoQianyueDialog
    :public QDialog, public Ui::qianyueDialog
{
    Q_OBJECT
public:
    ChengjiaoQianyueDialog(QWidget * parent = 0, DBConnect * dbcon =0);
private:
    DBConnect * dbcon;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_tableViewqianyue_clicked();
};

#endif // CHENGJIAOQIANYUEDIALOG_H
