#include "ClientOrder.hpp"
#include "Warehouse.hpp"
#include <iostream>
using namespace std;

int ClientOrder::nextOrderId = 1;

ClientOrder::ClientOrder(const string& orderDate) : orderId(nextOrderId++), orderDate(orderDate), totalPrice(0.0), status("Неотгруженно") {}

bool ClientOrder::addProduct(Product* product, int quantity) {
    if (product && quantity > 0) {
        items.push_back(make_pair(product, quantity));
        totalPrice = calculateTotal();
        cout << product->getType() << " x" << quantity<< " " << orderId << endl;
        return true;
    }
    return false;
}

bool ClientOrder::removeProduct(int productId) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->first->getProductId() == productId) {
            cout << "Продукт: " << it->first->getType() << "удален" << endl;
            items.erase(it);
            totalPrice = calculateTotal();
            return true;
        }
    }
    return false;
}

double ClientOrder::calculateTotal() {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.first->getPrice() * item.second;
    }
    return total;
}

void ClientOrder::processOrder(Warehouse* warehouse) {
    cout << "\n=== Заказ:  #" << orderId << " ===" << endl;
    for (const auto& item : items) {
        if (!warehouse->isProductAvailable(item.first->getProductId(), item.second)) {
            cout << "Товар" << item.first->getType()<< "Не найден" << endl;
            status = "Неотгруженно";
            return;
        }
    }

    for (const auto& item : items) {
        Product* product = warehouse->findProduct(item.first->getProductId());
        if (product) {
            product->decQuantity(item.second);
        }
    }

    status = "Отгруженно";
    cout << "Заказ №" << orderId << " Стоимость: " << totalPrice << endl;
}

string ClientOrder::getOrderInfo() const {
    string info = "Заказ#" + to_string(orderId) + " Дата: " + orderDate + " Статус:" + status +"Стоимость" + to_string(totalPrice) + " ";
    for (const auto& item : items) {
        info += "\n- " + item.first->getType() + " x" + to_string(item.second) +
            " (" + to_string(item.first->getPrice()) + " ���./��.)";
    }

    return info;
}

void ClientOrder::displayOrder() const {
    cout << getOrderInfo() << endl;
}

int ClientOrder::getOrderId() const {
    return orderId; 
}
std::string ClientOrder::getOrderDate() const { 
    return orderDate; 
}
std::string ClientOrder::getStatus() const { 
    return status; 
}
double ClientOrder::getTotalPrice() const {
    return totalPrice; 
}
