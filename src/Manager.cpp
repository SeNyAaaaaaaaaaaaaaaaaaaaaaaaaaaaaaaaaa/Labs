#include "Manager.hpp"
#include "StoreKeeper.hpp"
#include "Warehouse.hpp"
#include "Supply.hpp"
#include <iostream>
using namespace std;

Manager::Manager() : Employee() {}

Manager::Manager(const std::string& name, const std::string& password, const std::string& role,int age, const std::string& post, int salary) : Employee(name, password, role, age, post, salary) {}

bool Manager::acceptSupply(Supply* supply, Warehouse* warehouse) {
    cout << "Менеджер " << getName() << " принимает поставку #" << supply->getSupplyId() << endl;
    if (supply && warehouse) {
        return warehouse->processSupply(supply);
    }
    return false;
}
vector<string> Manager::createSchedule() {
    vector<string> schedule = { "Mon: 9-18", "Tue: 9-18", "Wed: 9-18" };
    return schedule;
}

bool Manager::addEmployee(Employee* employee) {
    cout << "Manager added employee: " << employee->getName() << endl;
    return true;
}

bool Manager::removeEmployee(int employeeId) {
    cout << "Manager removed employee with ID: " << employeeId << endl;
    return true;
}

void Manager::createSchedule(StoreKeeper* storeKeeper, const vector<string>& schedule) {
    cout << "Manager created schedule for storekeeper" << endl;
}