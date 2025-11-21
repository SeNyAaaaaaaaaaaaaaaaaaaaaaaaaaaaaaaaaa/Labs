package com.warehouse;

import java.util.ArrayList;
import java.util.List;

public class ClientOrder {
    private static int nextOrderId = 1;
    
    private int orderId;
    private String orderDate;
    private List<Product> products;
    private List<Integer> quantities;
    private double totalPrice;
    private String status;
    
    public ClientOrder(String orderDate) {
        this.orderId = nextOrderId++;
        this.orderDate = orderDate;
        this.products = new ArrayList<>();
        this.quantities = new ArrayList<>();
        this.totalPrice = 0.0;
        this.status = "Создан";
    }
    
    public boolean addProduct(Product product, int quantity) {
        if (product != null && quantity > 0) {
            products.add(product);
            quantities.add(quantity);
            calculateTotal();
            System.out.println("Добавлен товар '" + product.getType() + "' x" + quantity + " в заказ #" + orderId);
            return true;
        }
        return false;
    }
    
    public boolean removeProduct(int productId) {
        for (int i = 0; i < products.size(); i++) {
            if (products.get(i).getProductId() == productId) {
                products.remove(i);
                quantities.remove(i);
                calculateTotal();
                return true;
            }
        }
        return false;
    }
    
    private void calculateTotal() {
        totalPrice = 0.0;
        for (int i = 0; i < products.size(); i++) {
            totalPrice += products.get(i).getPrice() * quantities.get(i);
        }
    }
    
    public void processOrder(Warehouse warehouse) {
        System.out.println("\n=== Обработка заказа #" + orderId + " ===");
        for (int i = 0; i < products.size(); i++) {
            Product product = products.get(i);
            int quantity = quantities.get(i);
            if (!warehouse.isProductAvailable(product.getProductId(), quantity)) {
                System.out.println("Ошибка: товар '" + product.getType() + "' недоступен в нужном количестве");
                status = "Отклонен";
                return;
            }
        }
        
        for (int i = 0; i < products.size(); i++) {
            Product product = products.get(i);
            int quantity = quantities.get(i);
            Product warehouseProduct = warehouse.findProduct(product.getProductId());
            if (warehouseProduct != null) {
                warehouseProduct.lowQuantity(quantity);
            }
        }
        
        status = "Выполнен";
        System.out.println("Заказ #" + orderId + " успешно обработан. Сумма: " + totalPrice + " руб.");
    }
    
    public void displayOrder() {
        System.out.println("Заказ #" + orderId + " от " + orderDate);
        System.out.println("Статус: " + status);
        System.out.println("Общая сумма: " + totalPrice + " руб.");
        System.out.println("Товары:");
        for (int i = 0; i < products.size(); i++) {
            System.out.println("- " + products.get(i).getType() + " x" + quantities.get(i) +  " (" + products.get(i).getPrice() + " руб./шт.)");
        }
    }
    
    public int getOrderId() { 

        return orderId;
     }

    public String getOrderDate() { 

        return orderDate; 
    }

    public String getStatus() { 

        return status; 
    }

    public double getTotalPrice() {

         return totalPrice;
    }

    public String getOrderInfo() {

        return "Заказ #" + orderId + " от " + orderDate + ", Сумма: " + totalPrice + " руб., Статус: " + status;
    }
}