#include "Supply.hpp"
#include "Warehouse.hpp"
#include <iostream>
using namespace std;

int Supply::nextSupplyId = 1;

Supply::Supply(const string& supplierName, const string& supplyDate): supplyId(nextSupplyId++), supplierName(supplierName), supplyDate(supplyDate), status("Новая") {}

bool Supply::addProduct(Product* product, int quantity) {
    if (product && quantity > 0) {
        products.push_back(make_pair(product, quantity));
    cout << "Добавлен товар '" << product->getType() << "' x" << quantity<< " в поставку #" << supplyId << endl;
        return true;
    }
    return false;
}

bool Supply::removeProduct(int productId) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->first->getProductId() == productId) {
            cout << "Удалён товар '" << it->first->getType() << "' из поставки" << endl;
            products.erase(it);
            return true;
        }
    }
    return false;
}

void Supply::processSupply(Warehouse* warehouse) {
    cout << "\n=== Обработка поставки #" << supplyId << " ===" << endl;
    cout << "Поставщик: " << supplierName << endl;
    cout << "Дата: " << supplyDate << endl;

    for (const auto& item : products) {
        Product* product = warehouse->findProduct(item.first->getProductId());
        if (product) {
            product->incQuantity(item.second);
            cout << "Товар '" << product->getType() << "' пополнен на "<< item.second << " на складе" << endl;
        }
    }

    status = "Обработана";
    cout << "Поставка #" << supplyId << " успешно обработана" << endl;
}

string Supply::getSupplyInfo() const {
    string s_inf = "Поставка #" + to_string(supplyId) + " от " + supplyDate +"\nПоставщик: " + supplierName +"\nСтатус: " + status + "\nТовары:";
    for (const auto& item : products) {
        s_inf += "\n- " + item.first->getType() + " x" + to_string(item.second);
    }
    return s_inf;
}

void Supply::displaySupply() const {
    cout << getSupplyInfo() << endl;
}

int Supply::getSupplyId() const { 
    return supplyId;
}
string Supply::getSupplierName() const {
    return supplierName;
}
string Supply::getSupplyDate() const { 
    return supplyDate;
}
string Supply::getStatus() const {
    return status; 
}