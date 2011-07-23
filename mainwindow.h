#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QtGui>
#include <QtSql>
//#include <QSqlRelationalDelegate>
#include "taskmodel.h"
#include "tabledelegate.h"


class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void insertRow();
    void deleteRows();

private:
    void setUpTableView();
    void createActions();
    void createToolbar();

    QTabWidget *tabWidget;
    QTableView *tableView;
    QSqlRelationalTableModel *model;
    QAction *newEntry;
    QAction *deleteEntry;
    QToolBar *toolBar;
};

#endif // MAINWINDOW_H
