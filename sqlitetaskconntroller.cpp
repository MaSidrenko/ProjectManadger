#include "sqlitetaskconntroller.h"
//pattern Singleton
SQLiteTaskConntroller& SQLiteTaskConntroller::getInstance() {
    static SQLiteTaskConntroller instance;
    return instance;
}

bool SQLiteTaskConntroller::createTable() {
    context.setDBInfo(SQLite, "ProjectMan.db");

    QSqlQuery query_create_table(context.getmDB());



    if(!query_create_table.exec("CREATE TABLE IF NOT EXISTS task ("
                                 "id INTEGER PRIMARY KEY AUTOINCREMENT"
                                 "priority TEXT NOT NULL,"
                                 "deadline TEXT NOT NULL,"
                                 "task_info JSON,"
                                 "is_complete BOOLEAN NOT NULL")) {

        qCritical() << "SQL error: " << query_create_table.lastError().text();
    }
}
ReturnType SQLiteTaskConntroller::add(std::any item)
{
    if(item.type() == typeid(Task))
    {
        const Task& task = std::any_cast<const Task&>(item);

        QSqlQuery query_add(context.getmDB());

        query_add.prepare("INSERT INTO task(priority, deadline, task_info,is_complete)"
                          "VALUES(:priority, :deadline, :task_info, :is_complete)");

        query_add.bindValue(":priority",task.getPriorit());
        query_add.bindValue(":deadline",task.getDeadline());
        query_add.bindValue(":task_info",task.getTask_info());
        query_add.bindValue(":is_complete",task._is_complete());
        if(!query_add.exec()) {
            qCritical() << "Insert error: " << query_add.lastError().text();
            return SQLiteTaskConntroller::refresh();
        }
    }
    return SQLiteTaskConntroller::refresh();
}
ReturnType SQLiteTaskConntroller::refresh()
{
    std::list<Task> tasks;
    QSqlQuery query_refresh(context.getmDB());
    if(!query_refresh.exec("SELECT * FROM task ORDER BY id")) {
        qCritical() << "Refresh error: " << query_refresh.lastError().text();
    }
    while(query_refresh.next()) {
        tasks.push_back(Task(
            static_cast<Priority>(query_refresh.value(0).toInt()),
                             query_refresh.value(1).toDate(),
                             query_refresh.value(2).toJsonObject(),
                             query_refresh.value(3).toBool()));
    }
    return tasks;
}
ReturnType SQLiteTaskConntroller::select(QDate deadline)
{
    std::list<Task> tasks;
    QSqlQuery query_selecet(context.getmDB());
    if(!query_selecet.exec("SELECT * FROM task WHERE deadline = :deadline ORDER BY id")) {
        qCritical() << "Select error: " << query_selecet.lastError().text();
        return SQLiteTaskConntroller::refresh();
    }
    query_selecet.bindValue(":deadline",deadline);
    while(query_selecet.next()) {
        tasks.push_back(Task(
            static_cast<Priority>(query_selecet.value(0).toInt()),
            query_selecet.value(1).toDate(),
            query_selecet.value(2).toJsonObject(),
            query_selecet.value(3).toBool()));
    }
    return tasks;
}
ReturnType SQLiteTaskConntroller::del(int id)
{
    QSqlQuery query_del(context.getmDB());
    query_del.prepare("DELETE FROM task WHERE id = :id");
    query_del.bindValue(":id",id);
    if(!query_del.exec()) {
        qCritical() << "Select error: " << query_del.lastError().text();
        return SQLiteTaskConntroller::refresh();
    }

    return SQLiteTaskConntroller::refresh();
}
ReturnType SQLiteTaskConntroller::update(std::any item)
{
    if(item.type() == typeid(Task)) {
        const Task& task = std::any_cast<const Task&>(item);
        QSqlQuery query_update;
        query_update.prepare("UPDATE task SET priority = :priority, deadline = :deadline, task_info = :task_info, is_complete = :is_complete");
        query_update.bindValue(":priority", task.getPriorit());
        query_update.bindValue(":deadline", task.getDeadline());
        query_update.bindValue(":task_info", task.getTask_info());
        query_update.bindValue(":is_complete", task._is_complete());

        if(!query_update.exec()) {
            qCritical() << "Update error: " << query_update.lastError().text();
            return SQLiteTaskConntroller::refresh();
         }

        return SQLiteTaskConntroller::refresh();
    }
}
