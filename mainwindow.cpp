#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{    
    //tab = new TabView(this);
    tabWidget = new QTabWidget(this);
    setWindowTitle(tr("Task Tracker"));
    setMinimumSize(640, 480);

    table = new TaskModel();
    tableView = new QTableView();
    QPushButton *button = new QPushButton("yop");

    tabWidget->addTab(tableView, tr("Tasks"));
    tabWidget->addTab(button, tr("Stats"));


    tableView->setModel(table);
    tableView->setItemDelegate(new TableDelegate());

    tableView->resizeColumnsToContents();
    tableView->adjustSize();
    tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setStretchLastSection(true);

    //tableView->setIndexWidget();
    setCentralWidget(tabWidget);


}

MainWindow::~MainWindow()
{

}
