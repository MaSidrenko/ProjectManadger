#include "mainwindow.h"

#include <QApplication>
#include <QTableWidget>
#include <QHeaderView>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // if(!db.open()) {
    //     qCritical() << "DB open error: " << db.lastError().text();
    //     return 1;
    // }

    // QSqlQuery q(db);
    // execOrLog(q, R"(
    //     CREATE TABLE IF NOT EXISTS users (
    //         id INTEGER PRIMARY KEY AUTOINCREMENT,
    //         name TEXT NOT NULL,
    //         age INTEGER NOT NULL
    //     )
    // )");
    // if (!createAdnSeedUsers(db))
    // {
    //     return 1;
    // }
    // if (!loadUsersToTable(db, ui->tableWidget)) return 1;
    MainWindow w;
    w.show();
    return a.exec();
}
