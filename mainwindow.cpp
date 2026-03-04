#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "sqlitetaskconntroller.h"
#include <list>
#include "task.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->openAddTaskWindowButton->setObjectName("openAddTaskWindowButton");
    // loadTable(ui->testDB);

    add_task = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::loadTable(QTableWidget* table) {
    table->clear();
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({"priority","deadline", "task_info", "is_complete"});
    table->setRowCount(0);
    auto result = SQLiteTaskConntroller::getInstance().refresh();
    std::list<Task> tasks = std::get<std::list<Task>>(result);
    int r = 0;
    for(Task task : tasks) {
        table->insertRow(r);

        table->setItem(r, 0, new QTableWidgetItem(QString::number(task.getPriorit())));
        table->setItem(r, 1, new QTableWidgetItem(task.getDeadline().toString("dd.MM.yyyy")));
        // TODO: Обработать кнопку для открытия JSON
        table->setItem(r, 2, new QTableWidgetItem("Show Info"));
        table->setItem(r, 3, new QTableWidgetItem(task._is_complete() ? "Yes" : "No"));
        ++r;
    }

    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->horizontalHeader()->setStretchLastSection(true);
}
void MainWindow::on_openAddTaskWindowButton_clicked() {
    if(!add_task) {
        add_task = new AddTask(this);
    }

    add_task->show();
    add_task->raise();
    add_task->activateWindow();
}
