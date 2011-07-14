#include "taskmodel.h"

TaskModel::TaskModel(QObject *parent) : QAbstractTableModel(parent)
{

}

QVariant TaskModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= 4 || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        if (index.column() == 0)
            return tr("gerard");
        else if (index.column() == 1)
            return tr("ho");
        else if (index.column() == 2)
            return tr("paf");
        else if (index.column() == 3)
            return tr("paf");
    }
    return QVariant();
}

QVariant TaskModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Task");

            case 1:
                return tr("Total time spent on this task");

            case 2:
                return tr("Start counting");

            case 3:
                return tr("Category");


            default:
                return QVariant();
        }
    }
    return QVariant();
}
