#include <QtGui>
#include "logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}
void LoginDialog::on_passwdLineEdit_textChanged()
{
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(passwdLineEdit->isModified());
}
