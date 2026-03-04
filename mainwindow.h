#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QTableWidget>
#include <QHeaderView>
#include "addtask.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openAddTaskWindowButton_clicked();
private:
    Ui::MainWindow *ui;
    bool loadTable(QTableWidget* table);
    AddTask *add_task;
};
#endif // MAINWINDOW_H
