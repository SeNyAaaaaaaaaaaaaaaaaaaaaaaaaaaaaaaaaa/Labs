package com.warehouse;

public class Product {
    private int productId;
    private String type;
    private int quantity;
    private String description;
    private double price;

    public Product() {
        this.productId = 0;
        this.type = "";
        this.quantity = 0;
        this.description = "";
        this.price = 0.0;
    }
    
    public Product(int id, String type, int quantity, String description, double price) {
        this.productId = id;
        this.type = type;
        this.quantity = quantity;
        this.description = description;
        this.price = price;
    }
    
    public void addQuantity(int amount) {
        if (amount > 0) {
            quantity += amount;
            System.out.println("Увеличено количество товара '" + type + "' на " + amount);
        }
    }
    
    public boolean lowQuantity(int amount) {
        if (amount > 0 && quantity >= amount) {
            quantity -= amount;
            System.out.println("Уменьшено количество товара '" + type + "' на " + amount);
            return true;
        }
        System.out.println("Ошибка: недостаточно товара '" + type + "' на складе");
        return false;
    }
    
    public String getInfo() {
        return "ID: " + productId + ", Тип: " + type + ", Количество: " + quantity + ", Цена: " + price + " руб., Описание: " + description;
    }
    
    public int getProductId() {

         return productId; 
    }
    public String getType() {

         return type; 
    }
    public int getQuantity() {

         return quantity;
    }
    public String getDescription() { 

        return description; 
    }
    public double getPrice() {
        
        return price; 
    }
}