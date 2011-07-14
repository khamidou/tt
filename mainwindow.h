#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include <QTabWidget>
#include <QPushButton>
#include "taskmodel.h"
#include "tabledelegate.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;    
    QTabWidget *tabWidget;
    //TaskModel *table;
    QTableView *tableView;
    QSqlRelationalTableModel *model;
};

#endif // MAINWINDOW_H
