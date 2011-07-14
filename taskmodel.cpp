#include "taskmodel.h"

void initDb() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
            QMessageBox::critical(0, qApp->tr("Cannot open database"),
                qApp->tr("Unable to establish a database connection.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
    }

    createDb();
}

bool createDb() {
    QSqlQuery query;
    query.exec("create table tasks (id integer primary key,"
               "time_spent integer, description varchar(255),"
               "category_id integer);");

    query.exec("create table tasks_types (id integer primary key,"
                       "type varchar(255));");
    query.exec("insert into tasks_types values(1, 'Travail');");
    query.exec("insert into tasks values(1, 1, 'Finir tt', 1)");
    return true;
}

void initializeModel(QSqlRelationalTableModel *model)
 {
     model->setTable("tasks");
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);    
     model->setRelation(3, QSqlRelation("tasks_types", "type", "Type"));
     model->removeColumn(0);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Task"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Time spent today"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Category"));
     bool t = model->insertColumn(2);
     std::cout << t << std::endl;

     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Start counting"));

     model->select();
 }

void closeDb() {
    QSqlDatabase db = QSqlDatabase::database();
    db.close();
}
