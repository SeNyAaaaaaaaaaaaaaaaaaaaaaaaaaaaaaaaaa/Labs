#pragma once
#include <string>
#include <vector>
#include "UserSystem.hpp"
using namespace std;

class ClientOrder;

class Client : public UserSystem {
private:
    string contact_info;
    vector<ClientOrder*> orders;

public:
    Client();
    Client(const string& name, const string& password, const string& role, const string& contact_info);
    ~Client();

    string showInfoOfProduct(int productId);
    string getOrderInfo(int orderId);
    bool createOrder(ClientOrder* order);
    string getContactInfo() const;
};