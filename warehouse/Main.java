package com.warehouse;
public class Main {
    public static void main(String[] args) {
        System.out.println("=== СИСТЕМА СКЛАДА СТРОИТЕЛЬНЫХ МАТЕРИАЛОВ ===\n");
        
        // 1. Создаем склад
        Warehouse warehouse = new Warehouse("Основной склад", 10000);
        
        // 2. Создаем товары
        Product brick = new Product(1, "Кирпич", 1000, "Красный строительный кирпич", 25.0);
        Product cement = new Product(2, "Цемент", 50, "Портландцемент 50кг", 350.0);
        Product sand = new Product(3, "Песок", 2000, "Строительный песок", 15.0);
        
        // 3. Создаем адреса для товаров
        Addressing brickAddress = new Addressing(1, 1, "Основная зона");
        Addressing cementAddress = new Addressing(1, 2, "Основная зона");
        Addressing sandAddress = new Addressing(2, 1, "Сыпучие материалы");
        
        // 4. Добавляем товары на склад с адресами
        warehouse.addProduct(brick, brickAddress);
        warehouse.addProduct(cement, cementAddress);
        warehouse.addProduct(sand, sandAddress);
        
        // 5. СОЗДАЕМ ПЕРСОНАЛ
        System.out.println("\n--- УПРАВЛЕНИЕ ПЕРСОНАЛОМ ---");
        
        // Создаем менеджера
        Manager manager = new Manager("Анна Сидорова", "manager", "manager123");
        manager.displayInfo();
        
        // Создаем сотрудников
        Employee worker1 = new Employee("Иван Петров", "employee", "worker123", 30, 40000, "Грузчик");
        Employee worker2 = new Employee("Мария Иванова", "employee", "worker456", 25, 45000, "Оператор");
        
        // Менеджер нанимает сотрудников
        manager.hireEmployee(worker1);
        manager.hireEmployee(worker2);
        
        // Показываем сотрудников
        manager.displayManagedEmployees();
        
        // Сотрудники работают
        worker1.work();
        worker2.work();
        worker1.displaySchedule();
        
        // 6. Создаем кладовщика
        StoreKeeper storeKeeper = new StoreKeeper("Петр Семенов", "storekeeper", "store123");
        storeKeeper.displayInfo();
        
        // 7. Показываем начальное состояние склада
        System.out.println("\n--- НАЧАЛЬНОЕ СОСТОЯНИЕ СКЛАДА ---");
        warehouse.displayAllProducts();
        
        // 8. Создаем клиента и заказ
        Client client = new Client("ООО СтройМир", "client", "client123", "stroy-mir@example.com");
        ClientOrder order = new ClientOrder("2024-01-15");
        order.addProduct(brick, 100);
        order.addProduct(cement, 5);
        client.createOrder(order);
        
        // 9. Обрабатываем заказ
        System.out.println("\n--- ОБРАБОТКА ЗАКАЗА ---");
        order.processOrder(warehouse);
        
        // 10. МЕНЕДЖЕР СОЗДАЕТ ПОСТАВКУ
        System.out.println("\n--- РАБОТА МЕНЕДЖЕРА С ПОСТАВКАМИ ---");
        
        // Менеджер создает и одобряет поставку
        Supply supply = manager.createSupply("ООО Поставщик+", "2024-01-16");
        supply.addProduct(brick, 500);
        supply.addProduct(cement, 20);
        supply.addProduct(sand, 1000);
        
        manager.approveSupply(supply);
        
        System.out.println("\n--- ПОСТАВКА ДО ОБРАБОТКИ ---");
        supply.displaySupply();
        
        // Кладовщик принимает поставку
        System.out.println("\n--- ПРИНЯТИЕ ПОСТАВКИ ---");
        storeKeeper.acceptSupply(supply, warehouse);
        
        // 11. Показываем склад после поставки
        System.out.println("\n--- СКЛАД ПОСЛЕ ПОСТАВКИ ---");
        warehouse.displayAllProducts();
        
        // 13. Менеджер меняет зарплату сотруднику
        System.out.println("\n--- УПРАВЛЕНИЕ ЗАРПЛАТАМИ ---");
        worker1.setSalary(45000);
        
        // 14. Показываем заказы клиента
        System.out.println("\n--- ИНФОРМАЦИЯ О КЛИЕНТЕ ---");
        client.displayClientInfo();
        client.displayAllOrders();
        
        // 15. Менеджер увольняет сотрудника (демонстрация)
        System.out.println("\n--- УВОЛЬНЕНИЕ ---");
        manager.fireEmployee(worker2.getEmployeeId());
        manager.displayManagedEmployees();
    }
}