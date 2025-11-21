package com.warehouse;

import java.util.ArrayList;
import java.util.List;

public class Manager extends UserSystem {
    private int employeeId;
    private static int nextEmployeeId = 1;
    private List<Employee> managedEmployees;
    
    public Manager(String name, String role, String password) {
        super(name, role, password);
        this.employeeId = nextEmployeeId++;
        this.managedEmployees = new ArrayList<>();
    }
    
    public boolean hireEmployee(Employee employee) {
        if (employee != null) {
            managedEmployees.add(employee);
            System.out.println("Менеджер " + getName() + " нанял сотрудника: " + employee.getName());
            return true;
        }
        return false;
    }
    
    public boolean fireEmployee(int employeeId) {
        for (int i = 0; i < managedEmployees.size(); i++) {
            if (managedEmployees.get(i).getEmployeeId() == employeeId) {
                Employee employee = managedEmployees.remove(i);
                System.out.println("Менеджер " + getName() + " уволил сотрудника: " + employee.getName());
                return true;
            }
        }
        System.out.println("Сотрудник с ID " + employeeId + " не найден");
        return false;
    }
    
    public void displayManagedEmployees() {
        System.out.println("=== Сотрудники под управлением " + getName() + " ===");
        if (managedEmployees.isEmpty()) {
            System.out.println("Нет сотрудников в подчинении");
        } else {
            for (Employee employee : managedEmployees) {
                System.out.println("- " + employee.getName() + " (ID: " + employee.getEmployeeId() + ")");
            }
        }
    }
    
    public Supply createSupply(String supplierName, String supplyDate) {
        Supply supply = new Supply(supplierName, supplyDate);
        System.out.println("Менеджер " + getName() + " создал поставку #" + supply.getSupplyId());
        return supply;
    }
    
    public boolean approveSupply(Supply supply) {
        if (supply != null) {
            System.out.println("Менеджер " + getName() + " одобрил поставку #" + supply.getSupplyId());
            return true;
        }
        return false;
    }
    
   
    public void displayInfo() {
        System.out.println("Менеджер: " + getName() + ", ID: " + employeeId + ", Подчиненных: " + managedEmployees.size());
    }
    
    public int getEmployeeId() {
         return employeeId; 
    }

    public List<Employee> getManagedEmployees() { 

        return new ArrayList<>(managedEmployees);
     }
}