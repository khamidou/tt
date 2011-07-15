#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QtGui>
#include <QtSql/QSqlRelationalTableModel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlField>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QString>
#include <QDebug>
#include <iostream>


void initDb();
bool createDb();
void initializeModel(QSqlRelationalTableModel *model);
void closeDb();

#endif // TASKMODEL_H
