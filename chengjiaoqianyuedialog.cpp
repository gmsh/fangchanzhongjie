#include <QtGui>
#include "chengjiaoqianyuedialog.h"
#include "dbconnect.h"
#include <QtSql/QSqlTableModel>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <QtSql/QSqlRecord>
ChengjiaoQianyueDialog::ChengjiaoQianyueDialog(QWidget *parent, DBConnect *dbcon)
    :QDialog(parent)
{
    setupUi(this);
    this->dbcon = dbcon;
    this->comboBoxFang->addItems(*(this->dbcon->fangyuanList()));
    this->comboBoxKe->addItems(*(this->dbcon->keyuanList()));
    this->comboBoxRen->addItems(*(this->dbcon->loginNames()));
    this->comboBoxFen->addItems(*(this->dbcon->fenchenFangshiList()));
    this->tableViewqianyue->setModel(this->dbcon->qianyue);
    this->dbcon->qianyue->select();

    this->tableViewqianyue->setSelectionMode(QTableView::SingleSelection);
    this->tableViewqianyue->setSelectionBehavior(QTableView::SelectRows);
    this->tableViewqianyue->setEditTriggers(QTableView::NoEditTriggers);
}

void ChengjiaoQianyueDialog::on_pushButton_clicked()
{
    qDebug() << "add";
    QSqlTableModel * model = this->dbcon->qianyue;
    int row = model->rowCount();
    model->insertRows(row, 1);
    model->setData(model->index(row, 0), this->comboBoxFang->currentText());
    model->setData(model->index(row, 1), this->comboBoxKe->currentText());
    model->setData(model->index(row, 2), this->comboBoxRen->currentText());
    model->setData(model->index(row, 3), this->spinBoxYongjin->text().toInt());
    model->setData(model->index(row, 4), this->comboBoxFen->currentText());
    model->setData(model->index(row, 5), this->spinBoxBianhao->text().toInt());
    model->submitAll();
}

void ChengjiaoQianyueDialog::on_pushButton_2_clicked()
{
    qDebug() << "delete";
    this->dbcon->qianyue->removeRow(tableViewqianyue->currentIndex().row());
}

void ChengjiaoQianyueDialog::on_pushButton_3_clicked(){
    qDebug() << "add";
    QSqlTableModel * model = this->dbcon->qianyue;
    int row = this->tableViewqianyue->currentIndex().row();
    model->setData(model->index(row, 0), this->comboBoxFang->currentText());
    model->setData(model->index(row, 1), this->comboBoxKe->currentText());
    model->setData(model->index(row, 2), this->comboBoxRen->currentText());
    model->setData(model->index(row, 3), this->spinBoxYongjin->text().toInt());
    model->setData(model->index(row, 4), this->comboBoxFen->currentText());
    model->setData(model->index(row, 5), this->spinBoxBianhao->text().toInt());
    model->submitAll();
}

void ChengjiaoQianyueDialog::on_tableViewqianyue_clicked()
{
    qDebug() << "clicked";
    QSqlRecord record = this->dbcon->qianyue->record(this->tableViewqianyue->currentIndex().row());
    QComboBox * combo;
    QString * value;
    int a;
    combo = this->comboBoxFang;
    value = &(record.value(0).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);


    combo = this->comboBoxKe;
    value = &(record.value(1).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);
    combo = this->comboBoxRen;
    value = &(record.value(2).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);

    combo = this->comboBoxFen;
    value = &(record.value(4).toString());
    if(-1 != (a = combo->findText(*value)))
        combo->setCurrentIndex(a);
    else
        combo->insertItem(0,*value);
    this->spinBoxYongjin->setValue(record.value(3).toInt());
    this->spinBoxBianhao->setValue(record.value(5).toInt());
}
