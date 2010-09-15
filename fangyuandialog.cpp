#include "fangyuandialog.h"
#include <QtCore/QDebug>
FangyuanDialog::FangyuanDialog(QWidget *parent, DBConnect *dbcon)
    :QDialog(parent)
{
    setupUi(this);
    this->dbcon = dbcon;
    asChushouChuzu();
}
FangyuanDialog::~FangyuanDialog()
{

}

void FangyuanDialog::on_fangwuLeixingComboBox_currentIndexChanged(const QString &text)
{
    qDebug() << text;
    if(text==tr("合租"))
        asHezu();
    else
        asChushouChuzu();
}

void FangyuanDialog::asChushouChuzu()
{
    this->chanquanXingBieLabel->setText(tr("产权"));
    this->chanquanXingbieComboBox->clear();
    this->chanquanXingbieComboBox->addItem(tr("产权"));
    this->chanquanXingbieComboBox->addItem(tr("使用权"));
}

void FangyuanDialog::asHezu()
{
    this->chanquanXingBieLabel->setText(tr("性别倾向"));
    this->chanquanXingbieComboBox->clear();
    this->chanquanXingbieComboBox->addItem(tr("与男士合租"));
    this->chanquanXingbieComboBox->addItem(tr("与女士合租"));
    this->chanquanXingbieComboBox->addItem(tr("无要求"));
}
