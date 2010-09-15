#include "combodelegate.h"
#include <QtGui/QComboBox>
#include <QtCore/QStringList>
ComboDelegate::ComboDelegate(QObject *parent, QStringList *list)
    : QItemDelegate(parent)
{
    this->list = list;
}

QWidget *ComboDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QComboBox *editor = new QComboBox(parent);

    editor->addItems(*(this->list));
    
    editor->installEventFilter(const_cast<ComboDelegate*>(this));

    return editor;
}

ComboDelegate::~ComboDelegate()
{
    free(this->list);
}

void ComboDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
    QString str = index.model()->data(index).toString();
    
    QComboBox *box = static_cast<QComboBox*>(editor);
    int i = box->findText(str);
    box->setCurrentIndex(i);
}

void ComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QComboBox *box = static_cast<QComboBox*>(editor);
    QString str = box->currentText();

    model->setData(index, str);
}

void ComboDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

