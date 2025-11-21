#pragma once
#include <string>
#include <vector>
#include <utility>
#include "Product.hpp"
using namespace std;

class Warehouse;

class Shipment {
private:
    int shipmentId;
    vector<pair<Product*, int>> items;
    string shipmentDate;
    static int nextShipmentId;

public:
    Shipment(const string& date);
    bool addProduct(Product* product, int quantity);
    void processShipment(Warehouse* warehouse);
    string getShipmentInfo() const;
    void displayShipment() const;
    int getShipmentId() const;
    string getShipmentDate() const;
};
