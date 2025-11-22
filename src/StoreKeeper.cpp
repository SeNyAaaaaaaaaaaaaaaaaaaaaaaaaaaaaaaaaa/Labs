#include "StoreKeeper.hpp"
#include "Supply.hpp"
#include "Warehouse.hpp"
#include <iostream>
using namespace std;
StoreKeeper::StoreKeeper() : Employee() {}

StoreKeeper::StoreKeeper(const string& name, const string& password, const string& role, int age, const string& post, int salary) : Employee(name, password, role, age, post, salary) {}

bool StoreKeeper::acceptShipment(Shipment* shipment, Warehouse* warehouse) {
    cout << "Кладовщик " << getName() << " принимает отгрузку" << endl;
    if (shipment && warehouse) {
        bool ok = warehouse->processShipment(shipment);
        cout << (ok ? "Отгрузка успешно обработана" : "Ошибка при обработке отгрузки") << endl;
        return ok;
    }
    return false;
}

