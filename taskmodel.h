#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QAbstractTableModel>

class TaskModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TaskModel(QObject *parent=0);

    int rowCount(const QModelIndex &parent) const { return 2; };
    int columnCount(const QModelIndex &parent) const { return 4; };
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const {
            if (!index.isValid())
                return Qt::ItemIsEnabled;

            return QAbstractTableModel::flags(index) | Qt::ItemIsEditable; };

    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole) { return false; };
    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex()) { return false; };
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex()) {return false; };    

private:
    QList< QPair<QString, QString> > listOfPairs;
};

#endif // TASKMODEL_H
