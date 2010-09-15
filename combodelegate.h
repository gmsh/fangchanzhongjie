#ifndef COMBODELEGATE_H
#define COMBODELEGATE_H

#include <QtGui/QItemDelegate>
class QStringList;
class ComboDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    ComboDelegate(QObject *parent = 0, QStringList * list = 0);
    ~ComboDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                       const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
         const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:
    QStringList * list;
};

#endif
