#include "tabledelegate.h"
#include <iostream>

TableDelegate::TableDelegate(QWidget *parent) :
    QStyledItemDelegate(parent)
{  
}

QWidget *TableDelegate::createEditor(QWidget *parent,
                                    const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const

{    
    if (index.column() == 2) {
        QComboBox *lWidget = new QComboBox(parent);        
        lWidget->addItem("lololol");
        lWidget->addItem("jkj");
        lWidget->addItem("lodslolol");
        lWidget->addItem("dflol");

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

void TableDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    QComboBox *box = qobject_cast<QComboBox *>(editor);
    if (box == NULL)
        return;
}
void TableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const {

}

void TableDelegate::commitAndCloseEditor() { }
