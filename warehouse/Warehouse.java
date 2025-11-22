package com.warehouse;

import java.util.HashMap;
import java.util.Map;

public class Warehouse {
    private Map<Integer, Product> products;
    private Map<Integer, Addressing> addressing;
    private String warehouseName;
    private int capacity;

    public Warehouse(String name, int capacity) {
        this.warehouseName = name;
        this.capacity = capacity;
        this.products = new HashMap<>();
        this.addressing = new HashMap<>();
    }
    
    public boolean addProduct(Product product, Addressing address) {
        if (getCurrentStock() + product.getQuantity() > capacity) {
            System.out.println("Ошибка: превышена вместимость склада!");
            return false;
        }
        
        products.put(product.getProductId(), product);
        addressing.put(product.getProductId(), address);
        System.out.println("Товар '" + product.getType() + "' добавлен на склад. Адрес: " + address.getFullAddress());
        return true;
    }
    
    public boolean addProduct(Product product) {
        Addressing autoAddress = new Addressing(products.size() / 10 + 1, products.size() % 10 + 1, "Авто-зона");
        return addProduct(product, autoAddress);
    }
    
    public boolean removeProduct(int productId) {
        if (products.containsKey(productId)) {
            Product product = products.get(productId);
            Addressing address = addressing.get(productId);
            System.out.println("Товар '" + product.getType() + "' удален со склада. Адрес: " + address.getFullAddress());
            products.remove(productId);
            addressing.remove(productId);
            return true;
        }
        return false;
    }
    
    public Product findProduct(int productId) {
        return products.get(productId);
    }
    
    public Addressing findProductAddress(int productId) {
        return addressing.get(productId);
    }
    
    public Product findProductByType(String type) {
        for (Product product : products.values()) {
            if (product.getType().equals(type)) {
                return product;
            }
        }
        return null;
    }
    
    public boolean isProductAvailable(int productId, int quantity) {
        Product product = products.get(productId);
        return product != null && product.getQuantity() >= quantity;
    }
    
    public void processSupply(Supply supply) {
        System.out.println("Обработка поставки на складе '" + warehouseName + "'");
        if (supply != null) {
            supply.processSupply(this);
        }
    }
    
    public void displayAllProducts() {
        System.out.println("\n=== Содержимое склада '" + warehouseName + "' ===");
        if (products.isEmpty()) {
            System.out.println("Склад пуст");
        } else {
            for (Product product : products.values()) {
                Addressing address = addressing.get(product.getProductId());
                System.out.println(product.getInfo() + " | Адрес: " + address.getFullAddress());
            }
        }
        System.out.println("Всего товаров: " + getCurrentStock() + "/" + capacity);
    }
    
    public void displayProductLocations() {
        System.out.println("\n=== Схема размещения товаров на складе '" + warehouseName + "' ===");
        for (Map.Entry<Integer, Addressing> entry : addressing.entrySet()) {
            int productId = entry.getKey();
            Addressing address = entry.getValue();
            Product product = products.get(productId);
            System.out.println("Товар: '" + product.getType() + "' -> " + address.getFullAddress());
        }
    }
    
    private int getCurrentStock() {
        int total = 0;
        for (Product product : products.values()) {
            total += product.getQuantity();
        }
        return total;
    }
    
    public String getWarehouseName() {
         return warehouseName; 
    }

    public int getCapacity() { 
        return capacity;
    }

    public int getTotalProductsCount() {
         return products.size();
   }
}