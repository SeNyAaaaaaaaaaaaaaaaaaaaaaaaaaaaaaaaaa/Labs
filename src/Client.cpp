#include "Client.hpp"
#include "ClientOrder.hpp"
#include <iostream>
#include <string>
using namespace std;
Client::Client() : UserSystem(), contact_info("") {}

Client::Client(const std::string& name, const std::string& password, const std::string& role, const std::string& contact_info) : UserSystem(name, password, role), contact_info(contact_info) {}

Client::~Client() {
    for (auto order : orders) {
        delete order;
    }
}

string Client::showInfoOfProduct(int productId) {
    return "Product info for ID: " + to_string(productId);
}

string Client::getOrderInfo(int orderId) {
    return "Order info for ID: " + to_string(orderId);
}

bool Client::createOrder(ClientOrder* order) {
    orders.push_back(order);
    cout << "Client " << getName() << " created new order" << endl;
    return true;
}

string Client::getContactInfo() const {
    return contact_info;
}