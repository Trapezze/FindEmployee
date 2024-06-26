//Здесь я показываю работту с базой C++, структурами ии алгоритмами
#include <iostream>
#include <vector>
#include <algorithm>


// Создаем структуру для хранения информации о сотруднике
struct Employee {
    std::string name; // храним имя сотрудника
    int id; // храним идентификатор
    double salary; // храним зарплату
};

// Функция для добавления нового сотрудника в список
void addEmployee(std::vector<Employee>& employees)
{
    setlocale(LC_ALL, "russian");
    Employee newEmployee;
    std::cout << "Введдите имя: ";
    std::cin >> newEmployee.name;
    std::cout << "Введите ID: ";
    std::cin >> newEmployee.id;
    std::cout << "Введите зарплату: ";
    std::cin >> newEmployee.salary;
    employees.push_back(newEmployee); // добавляем нового сотрудника в список
}

// Функция для удаления сотрудника из списка по его ID
void removeEmployee(std::vector<Employee>& employees, int id) {
    employees.erase(std::remove_if(employees.begin(), employees.end(), [id](const Employee& e) {
        return e.id == id; // ищем сотрудника с нужным ID
        }), employees.end()); // удаляем сотрудника из списка
}

// Функция для вывода информации о всех сотрудниках
void printEmployees(const std::vector<Employee>& employees) {
    for (const auto& employee : employees) {
        std::cout << "Имя: " << employee.name << ", ID: " << employee.id << ", Зарплата: " << employee.salary << std::endl;
    }
}

int main() {
    std::vector<Employee> employees; // создаем список сотрудников

    addEmployee(employees); // добавляем первого сотрудника
    addEmployee(employees); // добавляем второго сотрудника

    std::cout << "Сотрудники:" << std::endl;
    printEmployees(employees); // выводим информацию о сотрудниках

    int idToRemove = 1; // задаем ID сотрудника для удаления
    removeEmployee(employees, idToRemove); // удаляем сотрудника

    std::cout << "Сотрудники после увольнения:" << std::endl;
    printEmployees(employees); // выводим информацию о сотрудниках после удаления

    return 0;
}
