package com.warehouse;

public class StoreKeeper extends UserSystem {
    private int employeeId;
    private static int nextEmployeeId = 1;
    
    public StoreKeeper(String name, String role, String password) {
        super(name, role, password);
        this.employeeId = nextEmployeeId++;
    }
    
    public boolean acceptSupply(Supply supply, Warehouse warehouse) {
        System.out.println("Кладовщик " + getName() + " принимает поставку #" + supply.getSupplyId());
        if (supply != null && warehouse != null) {
            supply.processSupply(warehouse);
            return true;
        }
        return false;
    }
    
    public void displayInfo() {
        System.out.println("Кладовщик: " + getName() + ", ID: " + employeeId);
    }
    
    public int getEmployeeId() { return employeeId; }
}