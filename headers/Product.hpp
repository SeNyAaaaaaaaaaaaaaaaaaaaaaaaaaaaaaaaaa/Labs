#pragma once
#include <string>
using namespace std;


class Product {
private:
	int productId;
	string type;
	int quantity;
	string description;
	double price;

public:
	Product(); 
	Product(int id, const string& type, int quantity, const string& description, double price); 
	void incQuantity(int amount); // Увеличить количество
	bool decQuantity(int amount); // Уменьшить количество (возвращает false если не хватает)
	string getInfo() const;
	int getProductId() const;
	string getType() const;
	int getQuantity() const;
	string getDescription() const;
	double getPrice() const;

};