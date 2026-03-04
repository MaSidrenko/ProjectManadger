#ifndef DBCONTEXT_H
#define DBCONTEXT_H

#include <variant>
#include <QSqlDatabase>
#include <QString>


enum DbName
{
    SQLite
};

inline QString EnumToStr(DbName Db)
{
    switch(Db)
    {
        case SQLite: return "SQLite"; break;
        default: "unknown"; break;
    }
}


class DBContext
{
private:
    QSqlDatabase m_db;
public:
    DBContext();
    void setDBInfo(DbName db, const QString& db_name);
    QSqlDatabase getmDB()const;
};

#endif // DBCONTEXT_H
