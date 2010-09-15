#ifndef KEYUANDIALOG_H
#define KEYUANDIALOG_H

#include <QtGui/QDialog>
#include "ui_keyuandialog.h"

class DBConnect;
class KeyuanDialog
    : public QDialog, public Ui::KeyuanDialog
{
    Q_OBJECT
public:
    KeyuanDialog(QWidget * parent, DBConnect * dbcon);
    ~KeyuanDialog();
private slots:
    void on_kehuXuqiuComboBox_currentIndexChanged ( const QString & text );
private:
    DBConnect * dbcon;
    void asQiugouQiuzu();
    void asHezu();
};

#endif // KEYUANDIALOG_H
