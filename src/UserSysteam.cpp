#include "UserSystem.hpp"
#include <iostream>
using namespace std;
UserSystem::UserSystem() : name(""), password(""), role("") {}

UserSystem::UserSystem(const string& name, const string& password, const string& role) : name(name), password(password), role(role) {}

UserSystem::~UserSystem() {}

bool UserSystem::login(const string& name, const string& password, const string& role) {
    if (this->name == name && this->password == password && this->role == role) {
        cout << "Пользователь: " << name << "Вошел в систему: " << role << endl;
        return true;
    }
    return false;
}

bool UserSystem::logout() {
    cout << "Пользователь: " << name << "Вошел из системы" << endl;
    return true;
}

string UserSystem::getName() const {
    return name;
}

string UserSystem::getRole() const {
    return role;
}