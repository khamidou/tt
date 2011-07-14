#include "tabledelegate.h"
#include <iostream>

TableDelegate::TableDelegate(QWidget *parent) :
    QStyledItemDelegate(parent)
{
    map = new QSignalMapper(this);
}

QWidget *TableDelegate::createEditor(QWidget *parent,
                                    const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const

{
    std::cout << index.column();
    if (index.column() == 2) {
        QComboBox *lWidget = new QComboBox(parent);        
        lWidget->addItem("lololol");
        lWidget->addItem("jkj");
        lWidget->addItem("lodslolol");
        lWidget->addItem("dflol");


        connect(lWidget, SIGNAL(editingFinished()),
                this, SLOT(commitAndCloseEditor()));

        return lWidget;
    } else {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
}

/* FIXME: rendre propre
void TableDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{

}
*/

QSize TableDelegate::sizeHint(const QStyleOptionViewItem &option,
               const QModelIndex &index) const { }

void TableDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {}
void TableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const { }

void TableDelegate::commitAndCloseEditor() { }
