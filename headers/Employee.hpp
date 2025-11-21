#pragma once
#include<UserSystem.hpp>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Employee : public UserSystem {
protected:
	int employeeId;
	int age;
	string post;
	map<string, string> schedule;
	int salary;
	static int nextEmployeeId;

public:
	Employee();
	Employee(const string& name, const string& password, const string& role, int age, const string& post, int salary);
	void setSchedule(const map<string, string>& newShedule);
	void addWorkDay(const string& day, const string& time);
	void displaySchedule() const;
	string getScheduleForDay(const string& day) const;
	bool addEmployee(const string& name, int age, const string& post, int salary);
	int getEmployeeId() const;
	int getAge() const;
	string getPost() const;
	map<string, string> getSchedule() const;
	int getSalary() const;
};
