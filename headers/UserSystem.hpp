#pragma once
#include <string>
using namespace std;
class UserSystem {
protected:
	string name;
	string role;
	string password;

public:
    UserSystem(); // Конструктор по умолчанию
    UserSystem(const string& name, const string& password, const string& role); // Конструктор с параметрами
    virtual ~UserSystem(); // Виртуальный деструктор

    virtual bool login(const string& name, const string& password, const string& role); // Проверка логина
    virtual bool logout(); // Выход из системы
    string getName() const; // Получить имя
    string getRole() const; // Получить роль
};