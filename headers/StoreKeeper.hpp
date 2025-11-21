#pragma once
#include "Employee.hpp"
#include <vector>
#include <string>
using namespace std;
class Shipment;
class Supply;
class Warehouse;

class StoreKeeper : public Employee {
public:
    StoreKeeper();
    StoreKeeper(const string& name, const string& password, const string& role,int age, const string& post, int salary);

    bool acceptShipment(Shipment* shipment, Warehouse* warehouse);
};