#include <iostream>

using string = std::string;


int** train() {
	int** carriages_and_places = new int*[18]; 
	for(auto i = 0; i < 18; ++i) {
		carriages_and_places[i] = new int[36];
	}
	for(auto i = 0; i < 18; ++i) {
		for(auto j = 0; j < 36; ++j) {
			carriages_and_places[i][j] = 0;
		}
	}
	return carriages_and_places;
}

void empty_places(int** get_train) {
	int carriage_for_empty = 0, empty_place = 0, continue_session = 0,count_ones = 0, count_zeros = 0;
	std::cout << "Выберите вагон, в котором хотите забронировать то или иное место:\n";
	std::cin >> carriage_for_empty;
	if(carriage_for_empty < 1 || carriage_for_empty > 18) {
		std::cerr << "Такого вагона не существует. Попробуйте ещё раз\n";
		empty_places(get_train);
	}
	std::cout << "Выберите место в этой вагоне для забронирования:\n";
	std::cin >> empty_place;
	if(empty_place < 1 || empty_place > 36) {
		std::cerr << "Такого места в вагоне нет. Попробуйте ещё раз\n";
		empty_places(get_train);
	}
	if(get_train[carriage_for_empty][empty_place] == 1) {
		std::cerr << "Это место забронировано. Выберите другое\n";
		empty_places(get_train);
	} else {
		get_train[carriage_for_empty][empty_place] = 0;
		std::cout << "Хотите продолжить опустошать забронированные места в вагонах поезда. Если да - напишите 1. Если нет, то 0: \n";
		std::cin >> continue_session;
		if(continue_session == 1) {
			empty_places(get_train);
		} else {	
			for(auto all_carriages = 0; all_carriages < 18; ++all_carriages) {
				std::cout << '\n' << all_carriages + 1 << " вагон: ";
				for(auto all_places = 0; all_places < 36; ++all_places) {
					std::cout << get_train[all_carriages][all_places] << " ";
				}
			}
			for(auto all_carriages = 0; all_carriages < 18; ++all_carriages) {
				for(auto all_places = 0; all_places < 36; ++all_places) {
					if(get_train[all_carriages][all_places] == 1) {
						count_ones++;
					} else if(get_train[all_carriages][all_places] == 0) {
						count_zeros++;
					}
				}
			}	
			std::cout << "\nВсего освобожденных мест: " << count_zeros << " \nКоличество забронированных мест: " << count_ones << "\n";
			std::cout << "Всего мест: " << 648 << "\n";
		}
	}
	for(auto i = 0; i < 18; ++i) {
		delete[]get_train[i];
		get_train[i] = nullptr;
	}
	delete[]get_train;
	get_train = nullptr;
	exit(0);
}

void count_selected_and_empty_places(int** get_train) {
	int count_ones = 0, count_zeros = 0;
	for(auto all_carriages = 0; all_carriages < 18; ++all_carriages) {
		for(auto all_places = 0; all_places < 36; ++all_places) {
			if(get_train[all_carriages][all_places] == 1) {
				count_ones++;
			} else if(get_train[all_carriages][all_places] == 0) {
				count_zeros++;
			}
		}
	}
	std::cout << "\nВсего освобожденных мест: " << count_zeros << " \nКоличество забронированных мест: " << count_ones << "\n";
	std::cout << "Всего мест: " << 648 << "\n";
	for(auto i = 0; i < 18; ++i) {
		delete[]get_train[i];
		get_train[i] = nullptr;
	}
	delete[]get_train;
	get_train = nullptr;
	exit(0);
}

void select_place_in_carriage_of_train(int** train) {
	int carriage = 0, place = 0, empty_booked_places = 0, continue_session = 0;
	std::cout << "\n";
	int** get_train = train;
	for(auto all_carriages = 0; all_carriages < 18; ++all_carriages) {
		std::cout << '\n' << all_carriages + 1 << " вагон: ";
		for(auto all_places = 0; all_places < 36; ++all_places) {
			std::cout << get_train[all_carriages][all_places] << " ";
		}
	}
	std::cout << "\n";
	while(true) {
		std::cout << "Выберите вагон, в котором хотите забронировать то или иное место:\n";
		std::cin >> carriage;
		if(carriage < 1 || carriage > 18) {
			std::cerr << "Такого вагона не существует. Попробуйте ещё раз\n";
			select_place_in_carriage_of_train(get_train);
		}
		std::cout << "Выберите место в этой вагоне для забронирования:\n";
		std::cin >> place;
		if(place < 1 || place > 36) {
			std::cerr << "Такого места в вагоне нет. Попробуйте ещё раз\n";
			select_place_in_carriage_of_train(get_train);
		}
		if(get_train[carriage][place] == 1) {
			std::cout << "Место уже забронировано. Попробуйте другое\n";
			select_place_in_carriage_of_train(get_train);
		} else {
			get_train[carriage][place] = 1;
		}
		std::cout << "Хотите опустошить забронированное место. Если да - напишите 1. Если нет - то для пропуска вопроса напишите любое рандомное число\n";
		std::cin >> empty_booked_places;
		if(empty_booked_places == 1) {
			empty_places(get_train);
		}
		std::cout << "Хотите продолжить бронировать места в вагонах поезда. Если да - напишите 1. Если нет, то 0 и будет выведен итоговый список заброниированных и пустых мест в вагонах поезда: \n";
		std::cin >> continue_session;
		if(continue_session == 1) {
			select_place_in_carriage_of_train(get_train);
		} else {	
			break;
		}
	}
	for(auto all_carriages = 0; all_carriages < 18; ++all_carriages) {
		std::cout << '\n' << all_carriages + 1 << " вагон: ";
		for(auto all_places = 0; all_places < 36; ++all_places) {
			std::cout << get_train[all_carriages][all_places] << " ";
		}
	}
	count_selected_and_empty_places(get_train);
}

int main() {
	setlocale(LC_ALL, "Rus");
	int select = 0;
	std::cout << "1. Рандомное заполнение\n";
	std::cout << "2. Всё пусто\n";
	std::cin >> select;
	if(select == 1) {
		select_place_in_carriage_of_train(train());
	} else {
		for(int i = 0; i < 18; ++i) {
			std::cout << "\n" << (i + 1) << " вагон: ";
			for(int j = 0; j < 36; ++j) {
				std::cout << train()[i][j] << " ";
			}
		}
		std::cout << "\n";
		for(int i = 0; i < 18; ++i) {
			delete[]train()[i];
		}
		delete[]train();
	}
	return 0;
}
