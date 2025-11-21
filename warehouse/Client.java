package com.warehouse;
import java.util.ArrayList;
import java.util.List;

public class Client extends UserSystem {
    private String contactInfo;
    private List<ClientOrder> orders;

    public Client() {
        super("", "", "");
        this.contactInfo = "";
        this.orders = new ArrayList<>();
    }
    
    public Client(String name, String role, String password, String contactInfo) {
        super(name, role, password);
        this.contactInfo = contactInfo;
        this.orders = new ArrayList<>();
    }
    
    public String showInfoOfProduct(int productId) {
        return "Информация о товаре с ID: " + productId;
    }
    
    public String getOrderInfo(int orderId) {
        for (ClientOrder order : orders) {
            if (order.getOrderId() == orderId) {
                return order.getOrderInfo();
            }
        }
        return "Заказ с ID " + orderId + " не найден";
    }
    
    public boolean createOrder(ClientOrder order) {
        if (order != null) {
            orders.add(order);
            System.out.println("Клиент " + getName() + " создал новый заказ #" + order.getOrderId());
            return true;
        }
        return false;
    }
    
    public void displayClientInfo() {
        System.out.println("=== Информация о клиенте ===");
        System.out.println("Имя: " + getName());
        System.out.println("Контакт: " + contactInfo);
        System.out.println("Количество заказов: " + orders.size());
    }
    
    public void displayAllOrders() {
        System.out.println("=== Все заказы клиента " + getName() + " ===");
        if (orders.isEmpty()) {
            System.out.println("Заказов нет");
        } else {
            for (ClientOrder order : orders) {
                order.displayOrder();
                System.out.println("---");
            }
        }
    }
    

    public String getContactInfo() {
        return contactInfo;
    }
    
    public List<ClientOrder> getOrders() {
        return new ArrayList<>(orders);
    }
    

    public void setContactInfo(String contactInfo) {
        this.contactInfo = contactInfo;
    }
}