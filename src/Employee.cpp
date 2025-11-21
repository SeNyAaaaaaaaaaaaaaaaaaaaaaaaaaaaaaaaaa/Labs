#include "Employee.hpp"
#include <iostream>
using namespace std;

int Employee::nextEmployeeId = 1; 

Employee::Employee() : UserSystem(), employeeId(0), age(0), post(""), salary(0) {}

Employee::Employee(const string& name, const string& password, const string& role,int age, const string& post, int salary) : UserSystem(name, password, role), employeeId(nextEmployeeId++), age(age), post(post), salary(salary) {
        schedule = {
        {"Понедельник", "9:00-18:00"},
        {"Вторник", "9:00-18:00"},
        {"Среда", "9:00-18:00"},
        {"Четверг", "9:00-18:00"},
        {"Пятница", "9:00-18:00"}
    };
}

void Employee::setSchedule(const map<std::string, string>& newSchedule) {
    schedule = newSchedule;
    cout << "Установлено новое расписание " << getName() << endl;
}

void Employee::addWorkDay(const string& day, const string& time) {
    schedule[day] = time;
    cout << "День: " << day << " " << time << " Время " << getName() << endl;
}

void Employee::displaySchedule() const {
    cout << "\n=== Расписаниме -  " << getName() << " ===" << endl;
    for (const auto& day : schedule) {
       cout << day.first << ": " << day.second << endl;
    }
}

string Employee::getScheduleForDay(const string& day) const {
    auto it = schedule.find(day);
    if (it != schedule.end()) {
        return it->second;
    }
    return "Не найдено";
}

bool Employee::addEmployee(const string& name, int age, const string& post, int salary) {
    cout << "Сотрудник добавлен: " << name << ", " << post << endl;
    return true;
}

int Employee::getEmployeeId() const { 
    return employeeId;
}
int Employee::getAge() const { 
    return age; 
}
string Employee::getPost() const { 
    return post; 
}
map<string,string> Employee::getSchedule() const {
    return schedule;
}
int Employee::getSalary() const { 
    return salary; 
}