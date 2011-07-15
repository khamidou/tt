#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{    
    //tab = new TabView(this);
    tabWidget = new QTabWidget(this);
    setWindowTitle(tr("Task Tracker"));
    setMinimumSize(640, 480);

    initDb();
    model = new QSqlRelationalTableModel(this);
    initializeModel(model);

    tableView = new QTableView;
    QPushButton *button = new QPushButton("yop");

    tabWidget->addTab(tableView, tr("Tasks"));
    tabWidget->addTab(button, tr("Stats"));

    tableView->setItemDelegate(new QSqlRelationalDelegate());
    tableView->setModel(model);

    tableView->hideColumn(0);

    tableView->resizeColumnsToContents();
    tableView->adjustSize();
    tableView->horizontalHeader()->moveSection(2, 0);
    tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setStretchLastSection(true);

   // tableView->setIndexWidget();
    setCentralWidget(tabWidget);
}

MainWindow::~MainWindow()
{
    closeDb();
}
