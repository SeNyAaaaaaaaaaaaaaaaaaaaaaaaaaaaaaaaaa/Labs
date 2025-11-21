#include <iostream>
#include <vector>
#include "UserSystem.hpp"
#include "employee.hpp"
#include "storekeeper.hpp"
#include "manager.hpp"
#include "client.hpp"
#include "product.hpp"
#include "addressing.hpp"
#include "warehouse.hpp"
#include "clientorder.hpp"
#include "supply.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "=== Демонстрация работы магазина и складской системы ===" << endl;

    cout << "\n1. Инициализация склада:" << endl;
    Warehouse mainWarehouse("Главный склад", 10000);
    cout << "Название склада: " << mainWarehouse.getWarehouseName()
        << ", вместимость: " << mainWarehouse.getCapacity() << endl;


    cout << "\n2. Создание продуктов:" << endl;
    Product brick(1, "Кирпич", 1000, "Строительный кирпич", 25.0);
    Product cement(2, "Цемент", 50, "Портландцемент 50кг", 350.0);
    Product sand(3, "Песок", 2000, "Речной песок", 15.0);

    Addressing addr1(1, 1, "Зона A");
    Addressing addr2(1, 2, "Зона A");
    Addressing addr3(2, 1, "Зона B");

    mainWarehouse.addProduct(brick, addr1);
    mainWarehouse.addProduct(cement, addr2);
    mainWarehouse.addProduct(sand, addr3);


    cout << "\n3. Текущий список продуктов:" << endl;
    mainWarehouse.displayAllProducts();


    cout << "\n4. Создание персонала:" << endl;
    StoreKeeper storeKeeper("Иван Иванов", "store123", "storekeeper", 35, "Кладовщик", 40000);
    Manager manager("Пётр Петров", "manager123", "manager", 42, "Менеджер", 80000);

    cout << "Имя кладовщика: " << storeKeeper.getName() << endl;
    cout << "Имя менеджера: " << manager.getName() << endl;


    cout << "\n5. Клиент и заказ:" << endl;


    Client client("ООО 'СтройМир'", "client123", "client", "stroy-mir@example.com");
    cout << "Клиент: " << client.getName() << endl;

 
    ClientOrder order1("2024-01-15");
    Product* brickPtr = mainWarehouse.findProduct(1);
    Product* cementPtr = mainWarehouse.findProduct(2);

    if (brickPtr && cementPtr) {
        order1.addProduct(brickPtr, 100);
        order1.addProduct(cementPtr, 5);
    }

    cout << "\nСодержимое заказа:" << endl;
    order1.displayOrder();


    order1.processOrder(&mainWarehouse);

    cout << "\nОстатки на складе после заказа:" << endl;
    mainWarehouse.displayAllProducts();


    cout << "\n--- Демонстрация UserSystem (логин/логаут) ---" << endl;
    vector<UserSystem*> users;
    users.push_back(&client);
    users.push_back(&storeKeeper);
    users.push_back(&manager);


    for (UserSystem* u : users) {
        cout << "\nПробуем войти как: " << u->getName() << " (роль: " << u->getRole() << ")" << endl;
        string password = "";
        if (u->getRole() == "client") password = "client123";
        else if (u->getRole() == "storekeeper") password = "store123";
        else if (u->getRole() == "manager") password = "manager123";

        bool ok = u->login(u->getName(), password, u->getRole());
        cout << (ok ? "Успешный вход" : "Не удалось войти") << endl;
        u->logout();
    }


   
    cout << "\n6. Поставка и пополнение склада:" << endl;

    Supply supply1("ООО 'Поставщик+'", "2024-01-16");
    cout << "Новая поставка #" << supply1.getSupplyId() << " от " << supply1.getSupplierName() << endl;

    
    if (brickPtr && cementPtr) {
        supply1.addProduct(brickPtr, 500);
        supply1.addProduct(cementPtr, 20);
    }

    cout << "\nСодержимое поставки:" << endl;
    supply1.displaySupply();


    cout << "\n Мэнэджер принимает поставку:" << endl;
    manager.acceptSupply(&supply1, &mainWarehouse);

    cout << "\nОстатки на складе после поставки:" << endl;
    mainWarehouse.displayAllProducts();

    
    cout << "\n7. Демонстрация сотрудников и динамической памяти:" << endl;


    Employee staticEmp("Алексей Смирнов", "pass1", "employee", 25, "Рабочий", 30000);
    cout << "Статический сотрудник: " << staticEmp.getName() << endl;

    Employee* dynamicEmp = new Employee("Ольга Сергеева", "pass2", "employee", 30, "Старший сотрудник", 50000);
    cout << "Динамический сотрудник: " << dynamicEmp->getName() << endl;


    cout << "\nСписок дополнительных продуктов:" << endl;
    Product* productArray = new Product[2]{
        Product(10, "Гвоздь", 1000, "Оцинкованный гвоздь", 2.5),
        Product(11, "Шуруп", 800, "Кровельный шуруп", 3.0)
    };

    for (int i = 0; i < 2; i++) {
    cout << "Товар " << i + 1 << ": " << productArray[i].getInfo() << endl;
    }

    cout << "\nСоздание массива сотрудников:" << endl;
    Employee** employees = new Employee * [2];
    employees[0] = new Employee("Сотрудник 1", "pass3", "employee", 28, "Кладовщик", 45000);
    employees[1] = new Employee("Сотрудник 2", "pass4", "employee", 32, "Оператор", 55000);

    for (int i = 0; i < 2; i++) {
        cout << "Сотрудник " << i + 1 << ": " << employees[i]->getName()
            << ", должность: " << employees[i]->getPost() << endl;
    }


    cout << "\n8. Завершение работы программы:" << endl;
    delete dynamicEmp;
    delete[] productArray;
    for (int i = 0; i < 2; i++) {
        delete employees[i];
    }
    delete[] employees;

    cout << "\n=== Завершение демонстрации ===" << endl;

    return 0;
}