#include <iostream>
#include <cmath>

using string = std::string;

bool is_leap(int year) { 
	if(year % 400 == 0 && year % 4 == 0) {
        return 1;
    } else {
		return 0;
	}
}

void first_task(int day1, int month1, int year1, int day2, int month2,int year2) {
    std::cout << "Первое задание\n";
    int is_leap_year_or_not = 0;
    if(is_leap(year1)) {
        is_leap_year_or_not = 366;
    } else if(is_leap(year2)) {
        is_leap_year_or_not = 366;
    } else {
        is_leap_year_or_not = 365;
    }
    int days_difference = ((std::abs(day1 - day2) + 
    (std::abs(month1 - month2) * 30) + 
    (std::abs(year1 - year2) * is_leap_year_or_not)));
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
    first_task(1,11,2024,1,11,2025);
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
