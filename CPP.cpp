#include <iostream>

#include <iostream>
#include <algorithm>

using string = std::string;

// Задание 1 

static void first_task() {
    std::cout << "1 задание\n";
    int* massive = new int[10];
    for (auto i = 0; i < 10; ++i) {
        massive[i] = rand() % 20;
    }
    int min = 1, max = 0;
    for (auto i = 0; i < 10; ++i) {
        if (massive[i] < min) {
            min = massive[i];
        }
    }
    for (auto i = 0; i < 10; ++i) {
        if (massive[i] > max) {
            max = massive[i];
        }
    }
    for (auto i = 0; i < 10; ++i) {
        std::cout << massive[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Минимальное число: " << min << "\n" <<
        "Максимальное число: " << max << "\n";
    delete[] massive;
    massive = nullptr;
};

// Задание 2

static void second_task() {
    std::cout << "2 задание\n";
    int range = 0, sum = 0;
    std::cout << "Введите диапазон от 0 до: \n";
    std::cin >> range;
    int* massive = new int[10];
    for (auto i = 0; i < 10; ++i) {
        massive[i] = rand() % range - 0;
    }
    for (auto i = 0; i < 10; ++i) {
        if (massive[i] < range) {
            sum += massive[i];
        }
    }
    for (auto i = 0; i < 10; ++i) {
        std::cout << massive[i] << " ";
    }
    std::cout << std::endl;
    std::cout << sum << std::endl;
    delete[] massive;
    massive = nullptr;
};

static void third_task() {
    std::cout << "3 задание\n";
    double months[12];
    double salary = 0.0, max = 0.0;
    int first_month = 0, second_month = 0;
    std::cout << "Введите вашу зарплату за 12 месяцев: \n";
    std::cin >> salary;
    std::cout << "Введите первый месяц: \n";
    std::cin >> first_month;
    std::cout << "Введите второй месяц: \n";
    std::cin >> second_month;
    for (auto i = 0; i < 12; ++i) {
        months[i] = salary / (12 - i);
    }
    for (auto i = first_month; i < second_month; ++i) {
        if (months[i] > max) {
            max = months[i];
        }
    }
    for (auto i = first_month; i < second_month; ++i) {
        std::cout << months[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Зарплата от " << first_month << " до " << second_month << " месяцев\n";
    std::cout << first_month << " месяц = " << months[first_month] << " | "
        << "Минимальная зарплата" << "\n";
    std::cout << second_month << " месяц = " << max << " | Максимальная зарплата" << "\n";
};

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    first_task();
    second_task();
    third_task();
};
