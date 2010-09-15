#include "quanxianzuguanlidialog.h"
#include "dbconnect.h"
#include "quanxianzushezhidialog.h"
#include <QtGui/QIcon>
#include <QtGui/QListWidgetItem>
#include <QtCore/QStringList>
#include <QtCore/QStringListIterator>
#include <QtCore/QDebug>
QuanxianzuGuanliDialog::QuanxianzuGuanliDialog(QWidget *parent, DBConnect *dbcon)
    :QDialog(parent)
{
    setupUi(this);
    this->dbcon = dbcon;
    this->quanxianzuIcon = new QIcon(":/images/fencheng.png");
    this->refreshList();
}
QuanxianzuGuanliDialog::~QuanxianzuGuanliDialog()
{
    free(this->quanxianzuIcon);
}

void QuanxianzuGuanliDialog::refreshList()
{
    this->listWidget->clear();
    QString tmp;
    QStringList list = *(dbcon->quanxianzuList());
    QStringList::const_iterator i;
    for(i = list.begin(); i != list.end(); i++){
        //qDebug() << *i;
        new QListWidgetItem(*(this->quanxianzuIcon),*i, this->listWidget);
    }
    this->listWidget->setCurrentRow(0);
}
void QuanxianzuGuanliDialog::on_addPushButton_clicked()
{
    //qDebug() << "quanxianzuguanli clicked add";
    QuanxianzuShezhiDialog dialog;
    connect(&dialog,SIGNAL(accepted()), this, SLOT(refreshList()));

    dialog.exec();

    disconnect(&dialog,SIGNAL(accepted()), this, SLOT(refreshList()));

}

void QuanxianzuGuanliDialog::on_modifyPushButton_clicked()
{
    //qDebug() << "clicked modify";
    bool a, b, c, d, e, f, g, h, i, j, k, l;
    dbcon->getQuanxian(&(this->listWidget->currentItem()->text()), &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l);
    QuanxianzuShezhiDialog dialog(0, this->dbcon,a, b, c, d, e, f, g, h, i, j, k, l,&(this->listWidget->currentItem()->text()));
    connect(&dialog,SIGNAL(accepted()), this, SLOT(refreshList()));

    dialog.exec();

    disconnect(&dialog,SIGNAL(accepted()), this, SLOT(refreshList()));

}

void QuanxianzuGuanliDialog::on_deletePushButton_clicked(){
    //qDebug() << "clicked delete";
    //qDebug() << this->listWidget->currentItem()->text();
    dbcon->deleteQuanxianZu(&(this->listWidget->currentItem()->text()));
    refreshList();
}
