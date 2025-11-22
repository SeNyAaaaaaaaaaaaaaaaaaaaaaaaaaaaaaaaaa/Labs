#include "Warehouse.hpp"
#include "Supply.hpp"
#include "Product.hpp"
#include <iostream>
#include <vector>
#include "Shipment.hpp"
using namespace std;
Warehouse::Warehouse(const std::string& name, int capacity) : warehouseName(name), capacity(capacity) {}
class Product;

bool Warehouse::addProduct(const Product& product, const Addressing& addressing) {
    if (getCurrentStock() + product.getQuantity() > capacity) {
        cout << "Превышена вместимость склада!" << endl;
        return false;
    }

    products[product.getProductId()] = make_pair(product, addressing);
    cout << "Product '" << product.getType() << "' add on warehouse. Address: "<< addressing.getFullAddress() << endl;
    return true;
}

bool Warehouse::removeProduct(int productId) {
    auto it = products.find(productId);
    if (it != products.end()) {
        cout << "Товар '" << it->second.first.getType() << "' удален со склада" << endl;
        products.erase(it);
        return true;
    }
    return false;
}

Product* Warehouse::findProduct(int productId) {
    auto it = products.find(productId);
    if (it != products.end()) {
        return &it->second.first;
    }
    return nullptr;
}

Product* Warehouse::findProductByType(const string& type) {
    for (auto& pair : products) {
        if (pair.second.first.getType() == type) {
            return &pair.second.first;
        }
    }
    return nullptr;
}

bool Warehouse::processSupply(Supply* supply) {
    cout << "proccess supply on warehouse: '" << warehouseName << "'" << endl;
    if (supply) {
        supply->processSupply(this);
        return true;
    }
    return false;
}

bool Warehouse::processShipment(Shipment* shipment) {
    cout << "Обработка отгрузки на складе '" << warehouseName << "'" << endl;
    if (shipment) {
        shipment->processShipment(this);
        return true;
    }
    return false;
}
void Warehouse::displayAllProducts() const {
    cout << "\n=== Sodergimoe sklada:'" << warehouseName << "' ===" << endl;
    if (products.empty()) {
        cout << "Склад пуст" << endl;
        return;
    }

    for (const auto& pair : products) {
        cout << pair.second.first.getInfo() << " | Address: " << pair.second.second.getFullAddress() << endl;
    }
    cout << "All products: " << getCurrentStock() << "/" << capacity << endl;
}

vector<string> Warehouse::getProductList() const {
    vector<string> list;
    for (const auto& pair : products) {
        list.push_back(pair.second.first.getInfo());
    }
    return list;
}

int Warehouse::getTotalProductsCount() const {
    return products.size();
}

bool Warehouse::isProductAvailable(int productId, int quantity) const {
    auto it = products.find(productId);
    if (it != products.end() && it->second.first.getQuantity() >= quantity) {
        return true;
    }
    return false;
}

string Warehouse::getWarehouseName() const { 
    return warehouseName; 
}
int Warehouse::getCapacity() const { 
    return capacity;
}

int Warehouse::getCurrentStock() const {
    int total = 0;
    for (const auto& pair : products) {
        total += pair.second.first.getQuantity();
    }
    return total;
}