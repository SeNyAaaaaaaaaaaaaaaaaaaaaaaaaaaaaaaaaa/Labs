package com.warehouse;

import java.util.HashMap;
import java.util.Map;

public class Employee extends UserSystem {
    private int employeeId;
    private static int nextEmployeeId = 1;
    private int age;
    private Map<String, String> schedule;
    private int salary;
    private String position;

    public Employee(String name, String role, String password, int age, int salary, String position) {
        super(name, role, password);
        this.employeeId = nextEmployeeId++;
        this.age = age;
        this.salary = salary;
        this.position = position;
        this.schedule = new HashMap<>();
        initializeDefaultSchedule();
    }
    
    private void initializeDefaultSchedule() {
        this.schedule.put("Понедельник", "9:00-18:00");
        this.schedule.put("Вторник", "9:00-18:00");
        this.schedule.put("Среда", "9:00-18:00");
        this.schedule.put("Четверг", "9:00-18:00");
        this.schedule.put("Пятница", "9:00-17:00");
    }
    
    public void setSchedule(Map<String, String> newSchedule) {
        this.schedule = new HashMap<>(newSchedule);
        System.out.println("Расписание обновлено для сотрудника " + getName());
    }
    
    public void displaySchedule() {
        System.out.println("\n=== Расписание сотрудника " + getName() + " ===");
        for (Map.Entry<String, String> entry : schedule.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
    
    public void work() {
        System.out.println("Сотрудник " + getName() + " работает на должности: " + position);
    }
    
    public void displayInfo() {
        System.out.println("Сотрудник: " + getName() + ", ID: " + employeeId + ", Должность: " + position + ", Зарплата: " + salary + " руб.");
    }
    

    public int getEmployeeId() { 
        return employeeId;
     }
    public int getAge() { 
        return age; 
    }
    public int getSalary() {
         return salary; 
    }
    public String getPosition() {
         return position; 
        }
    public Map<String, String> getSchedule() { 
        return new HashMap<>(schedule); 
    }
    
    public void setSalary(int salary) { 
        this.salary = salary;
        System.out.println("Зарплата сотрудника " + getName() + " изменена на: " + salary + " руб.");
    }
    public void setPosition(String position) { 
        this.position = position;
        System.out.println("Должность сотрудника " + getName() + " изменена на: " + position);
    }
}