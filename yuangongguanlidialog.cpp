#include <QtCore/QDebug>
#include "yuangongguanlidialog.h"

YuangongGuanliDialog::YuangongGuanliDialog(QWidget *parent)
    :QDialog(parent)
{
    setupUi(this);
}
YuangongGuanliDialog::~YuangongGuanliDialog()
{

}
void YuangongGuanliDialog::setTableModel(QSqlTableModel *tableModel)
{
    this->tableModel = tableModel;
    this->tableView->setModel(this->tableModel);
    this->tableView->resizeColumnsToContents();
}
void YuangongGuanliDialog::on_addPushButton_clicked()
{
    qDebug() << "addPushButton clicked";
}
void YuangongGuanliDialog::on_deletePushButton_clicked()
{
    qDebug() << "deletePushButton clicked";
}
