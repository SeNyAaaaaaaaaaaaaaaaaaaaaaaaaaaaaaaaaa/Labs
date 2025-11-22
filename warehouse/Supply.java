package com.warehouse;

import java.util.ArrayList;
import java.util.List;

public class Supply {
    private static int nextSupplyId = 1;
    
    private int supplyId;
    private List<Product> products;
    private List<Integer> quantities;
    private String supplierName;
    private String supplyDate;
    private String status;
    
    public Supply(String supplierName, String supplyDate) {
        this.supplyId = nextSupplyId++;
        this.supplierName = supplierName;
        this.supplyDate = supplyDate;
        this.products = new ArrayList<>();
        this.quantities = new ArrayList<>();
        this.status = "Создана";
    }
    
    public boolean addProduct(Product product, int quantity) {
        if (product != null && quantity > 0) {
            products.add(product);
            quantities.add(quantity);
            System.out.println("Добавлен товар '" + product.getType() + "' x" + quantity + " в поставку #" + supplyId);
            return true;
        }
        return false;
    }
    
    public boolean removeProduct(int productId) {
        for (int i = 0; i < products.size(); i++) {
            if (products.get(i).getProductId() == productId) {
                products.remove(i);
                quantities.remove(i);
                return true;
            }
        }
        return false;
    }
    
    public void processSupply(Warehouse warehouse) {
        System.out.println("\n=== Обработка поставки #" + supplyId + " ===");
        System.out.println("Поставщик: " + supplierName);
        System.out.println("Дата: " + supplyDate);
        
        for (int i = 0; i < products.size(); i++) {
            Product product = products.get(i);
            int quantity = quantities.get(i);
            
            Product warehouseProduct = warehouse.findProduct(product.getProductId());
            if (warehouseProduct != null) {
                warehouseProduct.addQuantity(quantity);
                System.out.println("Товар '" + product.getType() + "' добавлен в количестве " + quantity + " на склад");
            } else {
                Product newProduct = new Product(product.getProductId(), product.getType(),  quantity, product.getDescription(), product.getPrice());warehouse.addProduct(newProduct);
            }
        }
        
        status = "Обработана";
        System.out.println("Поставка #" + supplyId + " успешно обработана");
    }
    
    public void displaySupply() {
        System.out.println("Поставка #" + supplyId + " от " + supplyDate);
        System.out.println("Поставщик: " + supplierName);
        System.out.println("Статус: " + status);
        System.out.println("Товары:");
        for (int i = 0; i < products.size(); i++) {
            System.out.println("- " + products.get(i).getType() + " x" + quantities.get(i));
        }
    }
    
    public int getSupplyId() { 
        return supplyId;
     }
    public String getSupplierName() {
         return supplierName; 
        }
    public String getSupplyDate() { 
        return supplyDate; 
    }
    public String getStatus() { 
        return status; 
    }
    public String getSupplyInfo() {
        return "Поставка #" + supplyId + " от " + supplyDate + ", Поставщик: " + supplierName + ", Статус: " + status;
    }
}