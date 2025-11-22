#include "Addressing.hpp"
#include <iostream>
#include <string>
using namespace std;
Addressing::Addressing() : row(0), cell(0), storage_area("") {}

Addressing::Addressing(int row, int cell, const string& storage_area) : row(row), cell(cell), storage_area(storage_area) {}

string Addressing::getAddress() const {
    return "Стилаж " + to_string(row) + ",Полка " + to_string(cell);
}
string Addressing::getFullAddress() const {
    string s = "Зона: " + storage_area + ", " + getAddress();
    return s;
}
int Addressing::getRow() const {
    return row; 
}
int Addressing::getCell() const { 
    return cell;
}
string Addressing::getStorageArea() const {
    return storage_area;
}