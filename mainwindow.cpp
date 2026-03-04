#include "mainwindow.h"
#include "./ui_mainwindow.h"

static bool createAndSeedUsers(QSqlDatabase db)
{
    QSqlQuery q(db);

    if(!q.exec("DELETE FROM users")) {
        qCritical() << "Delete error: " << q.lastError().text();
        return false;
    }

    q.prepare("INSERT INTO users(name, age) VALUES(?, ?)");

    const struct {const char* name; int age; } data[] = {
                {"Alice", 25},
                {"Bob", 31},
                {"Charlie", 19},
                {"Daria", 28},
                };
    for(const auto& row : data) {
        q.addBindValue(QString::fromUtf8(row.name));
        q.addBindValue(row.age);
        if(!q.exec()) {
            qCritical() << "Insert error: " << q.lastError().text();
            return false;
        }
    }

    return true;
}

static bool loadUsersToTable(QSqlDatabase db, QTableWidget* table)
{
    if(!table) return false;

    table->clear();
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"ID", "Name", "Age"});
    table->setRowCount(0);

    QSqlQuery q(db);
    if(!q.exec("SELECT id, name, age FROM users ORDER BY id")) {
        qCritical() << "Select error: " << q.lastError().text();
    }

    int r = 0;
    while(q.next()) {
        table->insertRow(r);

        table->setItem(r, 0, new QTableWidgetItem(QString::number(q.value(0).toInt())));
        table->setItem(r, 1, new QTableWidgetItem(q.value(1).toString()));
        table->setItem(r, 2, new QTableWidgetItem(QString::number(q.value(2).toInt())));

        ++r;
    }
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->horizontalHeader()->setStretchLastSection(true);

    return true;
}

static bool execOrLog(QSqlQuery& q, const QString& sql)
{
    if (!q.exec(sql)) {
        qCritical() << "SQL error:" << q.lastError().text() << "SQL:" << sql;
        return false;
    }
    return true;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("test.db");

    if(!m_db.open()) {
        qCritical() << "DB open error: " << m_db.lastError().text();
        return;
    }

    QSqlQuery q(m_db);
    execOrLog(q, R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            age INTEGER NOT NULL
        )
    )");

    // if (!m_db.open()) {
    //     qCritical() << "DB open error:" << m_db.lastError().text();
    //     return;
    // }

    if (!createAndSeedUsers(m_db)) return;
    if (!loadUsersToTable(m_db, ui->testDB)) return;
}

MainWindow::~MainWindow()
{
    delete ui;
}
