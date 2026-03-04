#ifndef SQLITETASKCONNTROLLER_H
#define SQLITETASKCONNTROLLER_H
#include "IDBController.h"
#include "DBContext.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "task.h"


class SQLiteTaskConntroller : IDBController
{
private:
    // QSqlDatabase db;
    DBContext context;
public:
    SQLiteTaskConntroller();
    ReturnType add(std::any item)override;
    ReturnType refresh()override;
    ReturnType select(QDate deadline)override;
    ReturnType del(int id)override;
    ReturnType update(std::any item)override;
};

#endif // SQLITETASKCONNTROLLER_H
