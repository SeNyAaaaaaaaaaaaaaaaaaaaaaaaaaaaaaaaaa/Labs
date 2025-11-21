#pragma once
#include "Employee.hpp"
#include <string>

using namespace std;

#include <vector>
#include <string>

class Supply;
class StoreKeeper;

class Manager : public Employee {
public:
    Manager();
    Manager(const string& name, const string& password, const string& role, int age, const string& post, int salary);

    bool acceptSupply(Supply* supply, Warehouse* warehouse) ;
    vector<string> createSchedule();
    bool addEmployee(Employee* employee);
    bool removeEmployee(int employeeId);
    void createSchedule(StoreKeeper* storeKeeper, const vector<string>& schedule);
};
