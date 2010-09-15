#ifndef FANGYUANDIALOG_H
#define FANGYUANDIALOG_H

#include <QtGui/QDialog>
#include "ui_fangyuandialog.h"

class DBConnect;
class FangyuanDialog
    :public QDialog, public Ui::FangyuanDialog
{
    Q_OBJECT
public:
    FangyuanDialog(QWidget * parent = 0, DBConnect * dbcon = 0);
    ~FangyuanDialog();
private slots:
    void on_fangwuLeixingComboBox_currentIndexChanged ( const QString & text );
private:
    DBConnect * dbcon;
    void asChushouChuzu();
    void asHezu();
};

#endif // FANGYUANDIALOG_H
