#include "task.h"


Priority Task::getPriorit()const
{
    return priority;
}
QDate Task::getDeadline()const
{
    return deadline;
}
QJsonObject Task::getTask_info()const
{
    return task_info;
}
bool Task::_is_complete()const
{
    return is_complete;
}

void Task::setPriority(Priority priority)
{
    this->priority=priority;
}
void Task::setDeadline(QDate deadline)
{
    this->deadline = deadline;
}
void Task::setTask_info(QJsonObject task_info)
{
    this->task_info = task_info;
}
void Task::setComplete(bool is_complete)
{
    this->is_complete = is_complete;
}


Task::Task(Priority priority, QDate deadline, QJsonObject task_info, bool is_complete) {
    Task::setPriority(priority);
    Task::setDeadline(deadline);
    Task::setTask_info(task_info);
    Task::setComplete(is_complete);
}
