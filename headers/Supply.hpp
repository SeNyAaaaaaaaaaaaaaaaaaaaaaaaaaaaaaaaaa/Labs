#pragma once
#include <string>
#include <vector>
#include <map>
#include "Product.hpp"
using namespace std;

class Warehouse;

class Supply {
private:
    int supplyId;
    vector<pair<Product*, int>> products; 
    string supplierName;
    string supplyDate;
    string status;
    static int nextSupplyId;

public:
    Supply(const string& supplierName, const string& supplyDate);

    bool addProduct(Product* product, int quantity);
    bool removeProduct(int productId);
    void processSupply(Warehouse* warehouse);
    string getSupplyInfo() const;
    void displaySupply() const;
    int getSupplyId() const;
    string getSupplierName() const;
    string getSupplyDate() const;
    string getStatus() const;
};
