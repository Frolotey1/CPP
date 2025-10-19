#include <iostream>
#include <cmath>

int main() {
	setlocale(LC_ALL,"Rus");
	srand(time(NULL));
	std::cout << "1 задание\n";
	int first_array[]{4,7,2,1,8,43,65,25,3521,23,45};
	int array_size = sizeof(first_array) / sizeof(first_array[0]);
	int min_element = first_array[0], max_element = first_array[array_size - 1];
	for(auto i = 0; i < array_size; ++i) {
		if(first_array[i] < min_element) {
			min_element = first_array[i];
		}
	}
	for(auto i = 0; i < array_size; ++i) {
		if(first_array[i] > max_element) {
			max_element = first_array[i];
		}
	}
	std::cout << "Минимальное число: " << min_element << "\n" << "Максимальное число: " << max_element << "\n";
	
	std::cout << "2 задание\n";
	int second_array[10];
	int number = 0, from = 0, to = 0, sum_elements = 0;
	std::cout << "Введите диапазон от одного числа: \n";
	std::cin >> from;
	std::cout << "Введите диапазон до другого числа: \n";
	std::cin >> to;
	std::cout << "Введите пороговое значение для целого диапазона: \n";
	std::cin >> number;
	if(number > from && number < to) {
		for(int i = 0; i < 10; ++i) {
			second_array[i] = rand() % to - from;
		}
		for(int i = 0; i < 10; ++i) {
			if(second_array[i] < number) {
				sum_elements += second_array[i];
			}
		}
		for(int i = 0; i < 10; ++i) {
			std::cout << second_array[i] << " ";
		}
		std::cout << "\nСумма элементов, значения которых меньше указанного числа " << number << ": " << sum_elements << "\n";
	} else {
		std::cout << "Число находится за пределами диапазона\n";
		exit(0);
	}
	std::cout << "3 задание\n";
	double salary_firma = 0.0;
	int first_month = 0, second_month = 0;
	std::cout << "Введите прибыль фирмы за год:\n";
	std::cin >> salary_firma;
	std::cout << "Введите первый месяц:\n";
	std::cin >> first_month;
	std::cout << "Введите второй месяц:\n";
	std::cin >> second_month;
	if(first_month < 1 || second_month > 12) {
		std::cerr << "Не бывает такого месяца в году\n";
		exit(0);
	}
	int salary_for_months[(second_month - first_month)];
	for(int i = 1; i < (second_month - first_month); ++i) {
		salary_for_months[i] = salary_firma / ((second_month - first_month) - i);
	}
	int min_month_salary = salary_for_months[1], 
	max_month_salary = salary_for_months[(second_month - first_month) - 1];
	for(int i = 1; i < (second_month - first_month); ++i) {
		if(salary_for_months[i] < min_month_salary) {
			min_month_salary = salary_for_months[i];
		}
	}
	for(int i = 1; i < (second_month - first_month); ++i) {
		if(salary_for_months[i] > max_month_salary) {
			max_month_salary = salary_for_months[i];
		}
	}
	std::cout << "Минимальная зарплата в " << first_month << " месяце: " << min_month_salary << " рублей\nМаксимальная зарплата во " << second_month << " месяце: " << max_month_salary << " рублей";
	return 0;
}
