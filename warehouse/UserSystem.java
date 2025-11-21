package com.warehouse;

public class UserSystem {  
    private String name;
    private String role;
    private String password;

    public UserSystem() {}; 
    
    public UserSystem(String name, String role, String password) {
        this.name = name;
        this.role = role;
        this.password = password;
    }
    

    public boolean login(String role, String password) {
        return this.role.equals(role) &&  this.password.equals(password);
    }
    
    public boolean logout() {
        System.out.println("User " + name + " logged out");
        return true;
    }
    
    public String getName(){
        return this.name;
    }
    
    public String getRole(){
        return this.role;
    }
}