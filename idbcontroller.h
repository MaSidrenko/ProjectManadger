#ifndef IDBCONTROLLER_H
#define IDBCONTROLLER_H
#include "task.h"
#include <any>
#include <list>
using ReturnType = std::variant<std::list<Task>>;

class IDBController
{
private:

public:
    // IDBTaskController();
    virtual ~IDBController() = default;
    virtual ReturnType add(std::any item) = 0;
    virtual ReturnType select(QDate deadline) = 0;
    virtual ReturnType refresh() = 0;
    virtual ReturnType del(int id) = 0;
    virtual ReturnType update(std::any item) = 0;
};

#endif // IDBCONTROLLER_H
