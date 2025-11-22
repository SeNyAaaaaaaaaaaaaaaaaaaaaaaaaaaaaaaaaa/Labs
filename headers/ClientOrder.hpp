#pragma once
#include <string>
#include <vector>
#include <map>
#include "Product.hpp"
using namespace std;


class Warehouse;

class ClientOrder {
private:
    int orderId;
    string orderDate;
    vector<pair<Product*, int>> items; 
    double totalPrice;
    string status;
    static int nextOrderId;

public:
    ClientOrder(const string& orderDate);

    bool addProduct(Product* product, int quantity);
    bool removeProduct(int productId);
    double calculateTotal();
    void processOrder(Warehouse* warehouse);
    string getOrderInfo() const;
    void displayOrder() const;
    int getOrderId() const;
    string getOrderDate() const;
    string getStatus() const;
    double getTotalPrice() const;
};
