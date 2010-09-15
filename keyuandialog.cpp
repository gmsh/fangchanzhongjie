#include "keyuandialog.h"
#include "dbconnect.h"
#include <QtCore/QDebug>

KeyuanDialog::KeyuanDialog(QWidget *parent, DBConnect *dbcon)
    :QDialog(parent)
{
    setupUi(this);
    this->dbcon = dbcon;
    this->kehuLaiyuanComboBox->addItems(*(this->dbcon->fangkeLaiyuanList()));
    this->suozaiChengquComboBox->addItems(*(this->dbcon->chengquList()));
    this->zhiyeGuwenComboBox->addItems(*(this->dbcon->loginNames()));
    this->dangqianZhuangtaiComboBox->addItems(*(this->dbcon->kekuZhuangtaiList()));
    asQiugouQiuzu();
}
KeyuanDialog::~KeyuanDialog()
{

}

void KeyuanDialog::on_kehuXuqiuComboBox_currentIndexChanged(const QString &text)
{
    qDebug() << text;
    if(text == tr("求合租"))
        asHezu();
    else
        asQiugouQiuzu();
}

void KeyuanDialog::asHezu()
{
    this->chanquanXingBie->setText(tr("性别倾向"));
    this->chanquanXingbieComboBox->clear();
    this->chanquanXingbieComboBox->addItem(tr("与男士合租"));
    this->chanquanXingbieComboBox->addItem(tr("与女士合租"));
    this->chanquanXingbieComboBox->addItem(tr("无要求"));

}

void KeyuanDialog::asQiugouQiuzu()
{
    this->chanquanXingBie->setText(tr("产权"));
    this->chanquanXingbieComboBox->clear();
    this->chanquanXingbieComboBox->addItem(tr("产权"));
    this->chanquanXingbieComboBox->addItem(tr("使用权"));
}
