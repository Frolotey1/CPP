#include <iostream>
#include <cmath>

using string = std::string;

void first_task(int first_date[], int second_date[]) {
    std::cout << "Первое задание\n";
    int leap_or_not[2]{365,366};
    int is_leap_year_or_not = 0;
    if(first_date[2] % 400 == 0  first_date[2] % 4 == 0) {
        is_leap_year_or_not = leap_or_not[1];
    } else if(second_date[2] % 400 == 0  second_date[2] % 4 == 0) {
        is_leap_year_or_not = leap_or_not[1];
    } else {
        is_leap_year_or_not = leap_or_not[0];
    }
    int days_difference = ((std::abs(first_date[0] - second_date[0])) + 
    (std::abs(first_date[1] - second_date[1]) * 30) + 
    (std::abs(first_date[2] - second_date[2]) * is_leap_year_or_not));
    std::cout << "Разница двух дат в днях: " << days_difference << std::endl;
}

void second_task(int massive[], int size) {
    std::cout << "Второе задание\n";    
    int sum = 0;
    for(auto i = 0; i < size; ++i) {
        sum += massive[i];
        std::cout << massive[i] << " ";
    }
    std::cout << "\nСреднее арифметическое элементов массива: " << 
    (double)sum / (double)size << "\n";
};

void third_task(int massive[], int size) {
    std::cout << "Третье задание\n";
    int count_positive_elements = 0, count_negative_elements = 0,
    count_null_elements = 0, check_all_elements = 0;
    while(check_all_elements < size) {
        if(massive[check_all_elements] < 0) {
            count_negative_elements += 1;
        } else if(massive[check_all_elements] > 0) {
            count_positive_elements += 1;
        } else if(massive[check_all_elements] == 0) {
            count_null_elements += 1;
        }
        check_all_elements++;
    }
    for(auto i = 0; i < size; ++i) {
        std::cout << massive[i] << " ";
    }
    std::cout << 
    "\nКоличество положительных элементов: " << count_positive_elements <<
    "\nКоличество отрицательных элементов: " << count_negative_elements <<  
    "\nКоличество нулевых элементов: " << count_null_elements << "\n";
}

int main() {
    setlocale(LC_ALL,"Rus");
    srand(time(NULL));
    int first_date[3]{1,11,2015},second_date[3]{1,11,2025};
    first_task(first_date,second_date);
    int massive_for_second_task[10];
    for(auto i = 0; i < 10; ++i) {
        massive_for_second_task[i] = rand() % 10;
    }
    int size_for_second_task = sizeof(massive_for_second_task) / 
    sizeof(massive_for_second_task[0]);
    second_task(massive_for_second_task,size_for_second_task);
    int massive_for_third_task[20];
    for(auto i = 0; i < 20; ++i) {
        massive_for_third_task[i] = rand() % 20 - 10;
    }
    int size_for_third_task = sizeof(massive_for_third_task) / sizeof(massive_for_third_task[0]);
    third_task(massive_for_third_task,size_for_third_task);
    return 0;
};
