#include "tabledelegate.h"
#include <iostream>

TableDelegate::TableDelegate(QWidget *parent) :
     QSqlRelationalDelegate(parent)
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
        return QSqlRelationalDelegate::createEditor(parent, option, index);
    }
}

void TableDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{
    if (index.column() == 2) { /*
          StarRating starRating = qVariantValue<StarRating>(index.data());

          if (option.state & QStyle::State_Selected)
              painter->fillRect(option.rect, option.palette.highlight());

          starRating.paint(painter, option.rect, option.palette,
                           StarRating::ReadOnly);
                           */
      } else {
          QSqlRelationalDelegate::paint(painter, option, index);
      }
}

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
