#ifndef TASK_H
#define TASK_H
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDateTime>


enum Priority
{
    MAX,
    MEDIUM,
    LOWER
};

class Task
{
private:
    Priority priority;
    QDate deadline;
    QJsonObject task_info;
    bool is_complete;
public:
    Priority getPriorit()const;
    QDate getDeadline()const;
    QJsonObject getTask_info()const;
    bool _is_complete()const;

    void setPriority(Priority priority);
    void setDeadline(QDate deadline);
    void setTask_info(QJsonObject task_info);
    void setComplete(bool is_complete);

    Task(Priority priority, QDate deadline, QJsonObject task_info, bool is_complete);


};

#endif // TASK_H
