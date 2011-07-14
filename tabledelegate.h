#ifndef TABLEDELEGATE_H
#define TABLEDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QComboBox>
#include <QSignalMapper>


class TableDelegate : public QStyledItemDelegate
{
    Q_OBJECT

    public:
        TableDelegate(QWidget *parent = 0);

 /*       void paint(QPainter *painter, const QStyleOptionViewItem &option,
                   const QModelIndex &index) const; */
        QSize sizeHint(const QStyleOptionViewItem &option,
                       const QModelIndex &index) const;
        QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;
        void setEditorData(QWidget *editor, const QModelIndex &index) const;
        void setModelData(QWidget *editor, QAbstractItemModel *model,
                          const QModelIndex &index) const;

    private slots:
        void commitAndCloseEditor();

    private:
        QSignalMapper *signalMapper; /* Needed for the comboboxes and buttons */
    };

#endif // TABLEDELEGATE_H
