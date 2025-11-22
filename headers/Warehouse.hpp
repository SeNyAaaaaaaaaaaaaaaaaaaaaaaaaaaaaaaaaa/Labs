#pragma once
#include "Product.hpp"
#include "Addressing.hpp"
#include <string>
#include <map>
#include <vector>

class Supply;
class Shipment;

class Warehouse {

private:
	map<int, pair<Product, Addressing>> products;
	string warehouseName;
	int capacity;

public:
	Warehouse(const string& name, int capacity);
	bool addProduct(const Product& product, const Addressing& addressing);
	bool removeProduct(int productId);
	Product* findProduct(int productId);
	Product* findProductByType(const string& type);
	bool processSupply(Supply* supply);
	bool processShipment(Shipment* shipment);
	void displayAllProducts() const;
	vector<string> getProductList() const;
	int getTotalProductsCount() const;
	bool isProductAvailable(int productId, int quantity) const;
	string getWarehouseName() const;
	int getCapacity() const;
	int getCurrentStock() const;
};