#pragma once
#include<string>
using namespace std;
class Addressing {
private:
	int row;
	int cell;
	string storage_area;
public:
	Addressing();
	Addressing(int row, int cell, const string& storage_area);

	string getAddress() const;
	string getFullAddress() const;
	string getStorageArea() const;
	int getRow() const;
	int getCell() const;
};