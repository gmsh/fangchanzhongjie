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

    void asChushouChuzu();
    void asHezu();
private slots:
    void on_fangwuLeixingComboBox_currentIndexChanged ( const QString & text );
private:
    DBConnect * dbcon;
};

#endif // FANGYUANDIALOG_H
