#include "Shipment.hpp"
#include "Warehouse.hpp"
#include <iostream>
using namespace std;

int Shipment::nextShipmentId = 1;

Shipment::Shipment(const string& date) : shipmentId(nextShipmentId++), shipmentDate(date) {}

bool Shipment::addProduct(Product* product, int quantity) {
    if (product && quantity > 0) {
        items.push_back(make_pair(product, quantity));
        cout << "Добавлен товар '" << product->getType() << "' x" << quantity << " в отгрузку #" << shipmentId << endl;
        return true;
    }
    return false;
}

void Shipment::processShipment(Warehouse* warehouse) {
    cout << "\n=== Обработка отгрузки #" << shipmentId << " ===" << endl;
    cout << "Дата: " << shipmentDate << endl;
    for (const auto& item : items) {
        Product* p = warehouse->findProduct(item.first->getProductId());
        if (p) {
            if (p->decQuantity(item.second)) {
                cout << "Товар '" << p->getType() << "' отгружен в количестве " << item.second << endl;
            }
            else {
                cout << "Не удалось отгрузить товар '" << p->getType() << "' в количестве " << item.second << endl;
            }
        }
    }
}

string Shipment::getShipmentInfo() const {
    string s = "Отгрузка #" + to_string(shipmentId) + " от " + shipmentDate + "\nТовары:";
    for (const auto& item : items) {
        s += "\n- " + item.first->getType() + " x" + to_string(item.second);
    }
    return s;
}

void Shipment::displayShipment() const {
    cout << getShipmentInfo() << endl;
}

int Shipment::getShipmentId() const { return shipmentId; }
string Shipment::getShipmentDate() const { return shipmentDate; }
