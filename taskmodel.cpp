#include "taskmodel.h"

void initDb() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./tasks.db");
    if (!db.open()) {
            QMessageBox::critical(0, qApp->tr("Cannot open database"),
                qApp->tr("Unable to establish a database connection.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
    }    
}

bool createDb() {
    QSqlQuery query;

    query.exec("create table tasks_types (id integer primary key,"
                       "type varchar(255));");
    query.exec("create table tasks (id integer primary key,"
               "time_spent integer, description varchar(255),"
               "category_id integer);");

   query.exec("insert into tasks_types values(1, 'Travail');");
    query.exec("insert into tasks values(1, 1, 'Finir tt', 1)");
    query.exec("insert into tasks values(2, 2, 'Ecrire la doc', 1)");
    query.exec("insert into tasks values(3, 2, 'Acheter du pain', 1)");
    query.clear();
    return true;
}

void initializeModel(QSqlRelationalTableModel *model)
 {
 
     model->setTable("tasks");
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);
     //model->setSort(0, Qt::AscendingOrder);
     model->setRelation(3, QSqlRelation("tasks_types", "id", "type"));

     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Task"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Time spent today"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Category"));

     model->select();

     QString t2 = model->record(1).field(0).value().toString();
     qDebug() << t2;
 }

void closeDb() {
    QSqlDatabase db = QSqlDatabase::database();
    db.close();
}
