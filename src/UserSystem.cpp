// Implementation of UserSystem
#include "UserSystem.hpp"
#include <iostream>
using namespace std;

UserSystem::UserSystem() : name(""), password(""), role("") {}

UserSystem::UserSystem(const string& name, const string& password, const string& role) : name(name), password(password), role(role) {}

UserSystem::~UserSystem() {}

bool UserSystem::login(const string& name, const string& password, const string& role) {
    if (this->name == name && this->password == password && this->role == role) {
        cout << "Авторизация успешна: " << name << ", роль: " << role << endl;
        return true;
    }
    return false;
}

bool UserSystem::logout() {
    cout << "Пользователь вышел: " << name << endl;
    return true;
}

string UserSystem::getName() const {
    return name;
}

string UserSystem::getRole() const {
    return role;
}
