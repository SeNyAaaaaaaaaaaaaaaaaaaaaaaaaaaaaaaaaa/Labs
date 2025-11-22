#include "Product.hpp"
#include <iostream>
using namespace std;
Product::Product() : productId(0), type(""), quantity(0), description(""), price(0.0) {}

Product::Product(int id, const string& type, int quantity, const string& description, double price) : productId(id), type(type), quantity(quantity), description(description), price(price) {}

void Product::incQuantity(int amount) {
    if (amount > 0) {
        quantity += amount;
        cout << "Увеличено количество товара '" << type << "' на " << amount<< ". Количество: " << quantity << endl;
    }
}
bool Product::decQuantity(int amount) {
    if (amount > 0 && quantity >= amount) {
        quantity -= amount;
        cout << "Уменьшено количество товара '" << type << "' на " << amount << ". Количество: " << quantity << endl;
        return true;
    }
    cout << "Ошибка: недостаточно товара '" << type << "' на складе" << endl;
    return false;
}
string Product::getInfo() const {
    string s = "ID: " + to_string(productId) + ", наименование: " + type + ", количество: " + std::to_string(quantity) + ", цена: " + std::to_string(price) +" руб., описание: " + description;
    return s;
}

int Product::getProductId() const { 
    return productId; 
}
string Product::getType() const { 
    return type; 
}
int Product::getQuantity() const {
    return quantity; 
}
string Product::getDescription() const {
    return description; 
}
double Product::getPrice() const {
    return price; 
}