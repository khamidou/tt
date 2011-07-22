#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{    
    //tab = new TabView(this);
    tabWidget = new QTabWidget(this);
    setWindowTitle(tr("Task Tracker"));
    setMinimumSize(640, 480);

    setUpTableView();
    QPushButton *button = new QPushButton("yop");
    tabWidget->addTab(tableView, tr("Tasks"));
    tabWidget->addTab(button, tr("Stats"));

    createActions();
    createToolbar();

    setCentralWidget(tabWidget);
}

void MainWindow::setUpTableView()
{
    initDb();
    model = new QSqlRelationalTableModel(this);
    initializeModel(model);

    tableView = new QTableView;
    tableView->setItemDelegate(new QSqlRelationalDelegate(tableView));
    tableView->setModel(model);

    tableView->hideColumn(0);

    tableView->resizeColumnsToContents();
    tableView->adjustSize();
    tableView->horizontalHeader()->moveSection(2, 0);
    tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::createActions()
{
    newEntry = new QAction(QIcon("./icons/new.png"), tr("&New"), this);
    newEntry->setShortcuts(QKeySequence::New);

    connect(newEntry, SIGNAL(triggered()), this, SLOT(insertRow()));
}

void MainWindow::createToolbar()
{
    toolBar = addToolBar(tr("New"));
    toolBar->addAction(newEntry);
}

void MainWindow::insertRow()
{
    QSqlQuery query;

    /* FIXME : don't hardcode field numbers */
    query.exec("insert into tasks(time_spent, description, category_id) values(1, 'Double-click to edit', 1);");
    model->select();
}

MainWindow::~MainWindow()
{
    closeDb();
}
