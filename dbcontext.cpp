#include "dbcontext.h"

DBContext::DBContext() {}

void DBContext::setDBInfo(DbName db, const QString& db_name)
{
    switch(db)
    {
    case SQLite:
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName(db_name);
        break;

    }

}


QSqlDatabase DBContext::getmDB()const
{
    return m_db;
}
