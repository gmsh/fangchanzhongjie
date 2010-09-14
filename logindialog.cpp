#include <QtGui>
#include <QtCore/QStringList>
#include <QtCore/QStringListIterator>
#include "logindialog.h"

LoginDialog::LoginDialog(QWidget *parent, QStringList * list)
    : QDialog(parent)
{
    setupUi(this);
    this->nameList = list;
    this->loginNameComboBox->clear();
    this->loginNameComboBox->addItems(*(this->nameList));
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}
void LoginDialog::on_passwdLineEdit_textChanged()
{
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(passwdLineEdit->isModified());
}


void LoginDialog::accept(){
    emit loggined(this->loginNameComboBox->currentText(), this->passwdLineEdit->text());
}

void LoginDialog::loginFailed()
{
    this->label_4->setText(tr("密码错误。"));
}

void LoginDialog::loginSuccessed(){
    emit QDialog::accept();
}
