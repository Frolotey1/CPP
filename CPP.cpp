#include <iostream>
#include <vector>
#include <cmath>

using string = std::string;

/*
int = -214796986...214729457567
short = -32768...32767
long = -429695876859586...429605857759494
float = 4 байта
double = 8 байт 
long double = 3i3545949595.59459575759
char = 1 байт

математические операторы = + - / * % ++ -- = 
логические операторы = || && !
операторы присваивания = > < <= >= != == <=>

*/

double 
fruit_prices[5]{ 0.0,30.7,20.1,50.3,40.5 }, 
vegetable_prices[4]{ 0.0,10.0,5.0,1.0 }, 
tea_prices[3]{0.0,2.0,3.0};
int count_fruit_products[5]{ 0,5,2,6,5 }, count_vegetable_products[5]{ -1,2,3,4,0 }, count_tea_products[3]{0,4,5};
std::vector<string>
fruit_juices{"","Яблочный","Апельсиновый","Абрикосовый","Грушевый" },
vegetable_juices{"","Томатный","Луковый","Огуречный" },
tea{"","Чесночный","Петрушевый" };
std::vector<int> discounts;

static void select_necessary_category(double count_rubles) {
    int select_category = 0, 
    select_product = 0, 
    count_products = 0,
    continue_shopping = 0,
    refuse_from_product = 0,
    sum_discounts = 0;
	while(true) {
        string product_category[3]{ "Фруктовые соки","Овощные соки","Чаи" };
	for (auto i = 0; i < 3; ++i) {
		std::cout << (i + 1) << ") " << product_category[i] << "\n";
	}
	std::cout << "Выберите интересную вам категорию товаров: \n";
	std::cin >> select_category;
	if (select_category == 1) {
		std::cout << "Вы выбрали категорию '" << product_category[0] << "'. Выберите для себя нужный товар. Если хотите, то можете отказаться от данной категории и выбрать другую: \n";
		for (auto i = 1; i < fruit_juices.size(); ++i) {
			std::cout << i << ") " << fruit_juices.at(i) << " | " << fruit_prices[i] << " рублей" << " | " << count_fruit_products[i] << "\n";
		}
		std::cout << 5 << ") " << "Отказаться от категории\n";
		std::cin >> select_product;
		if (select_product == 1) {
			std::cout << "Вы выбрали продукт '" << fruit_juices[select_product] << "' \nНапишите количество товара, которое хотите приобрести:" << std::endl;
			std::cin >> count_products;
			if (count_products == count_fruit_products[select_product]) {
				if ((fruit_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (fruit_prices[select_product] * count_fruit_products[select_product])) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (fruit_prices[select_product] * count_fruit_products[select_product]);
				}
				std::cout << "Вы приобрели товар '" << fruit_juices[select_product] << " с количеством в " << count_fruit_products[select_product] << " на сумму " << (fruit_prices[select_product] * count_fruit_products[select_product]) << " рублей\n";
                std::cout << "Хотите отказаться от товара '" << fruit_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (fruit_prices[select_product] * count_fruit_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
			else {
				if ((fruit_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (fruit_prices[select_product] * count_products)) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (fruit_prices[select_product] * count_products);
				}
				std::cout << "Вы приобрели товар '" << fruit_juices[select_product] << " с количеством в " << count_fruit_products[select_product] << " на сумму " << (fruit_prices[select_product] * count_fruit_products[select_product]) << " рублей\n";
                std::cout << "Хотите отказаться от товара '" << fruit_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (fruit_prices[select_product] * count_fruit_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
		}
		else if (select_product == 2) {
			std::cout << "Вы выбрали продукт '" << fruit_juices[select_product] << "' \nНапишите количество товара, которое хотите приобрести:" << std::endl;
			std::cin >> count_products;
			if (count_products == count_fruit_products[select_product]) {
				if ((fruit_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (fruit_prices[select_product] * count_fruit_products[select_product])) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (fruit_prices[select_product] * count_fruit_products[select_product]);
				}
				std::cout << "Вы приобрели товар '" << fruit_juices[select_product] << " с количеством в " << count_fruit_products[select_product] << " на сумму " << (fruit_prices[select_product] * count_fruit_products[select_product]) << " рублей\n";
                std::cout << "Хотите отказаться от товара '" << fruit_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (fruit_prices[select_product] * count_fruit_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
			else {
				if ((fruit_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (fruit_prices[select_product] * count_products)) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (fruit_prices[select_product] * count_products);
				}
				std::cout << "Вы приобрели товар '" << fruit_juices[select_product] << " с количеством в " << count_fruit_products[select_product] << " на сумму " << (fruit_prices[select_product] * count_fruit_products[select_product]) << " рублей\n";
                std::cout << "Хотите отказаться от товара '" << fruit_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (fruit_prices[select_product] * count_fruit_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
		}
		else if (select_product == 3) {
			std::cout << "Вы выбрали продукт '" << fruit_juices[select_product] << "' \nНапишите количество товара, которое хотите приобрести:" << std::endl;
			std::cin >> count_products;
			if (count_products == count_fruit_products[select_product]) {
				if ((fruit_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (fruit_prices[select_product] * count_fruit_products[select_product])) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (fruit_prices[select_product] * count_fruit_products[select_product]);
				}
				std::cout << "Вы приобрели товар '" << fruit_juices[select_product] << " с количеством в " << count_fruit_products[select_product] << " на сумму " << (fruit_prices[select_product] * count_fruit_products[select_product]) << " рублей\n";
                std::cout << "Хотите отказаться от товара '" << fruit_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (fruit_prices[select_product] * count_fruit_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
			else {
				if ((fruit_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (fruit_prices[select_product] * count_products)) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (fruit_prices[select_product] * count_products);
				}
				std::cout << "Вы приобрели товар '" << fruit_juices[select_product] << " с количеством в " << count_fruit_products[select_product] << " на сумму " << (fruit_prices[select_product] * count_fruit_products[select_product]) << " рублей\n";
                std::cout << "Хотите отказаться от товара '" << fruit_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (fruit_prices[select_product] * count_fruit_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
		}
		else if (select_product == 4) {
			std::cout << "Вы выбрали продукт '" << fruit_juices[select_product] << "' \nНапишите количество товара, которое хотите приобрести:" << std::endl;
			std::cin >> count_products;
			if (count_products == count_fruit_products[select_product]) {
				if ((fruit_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (fruit_prices[select_product] * count_fruit_products[select_product])) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (fruit_prices[select_product] * count_fruit_products[select_product]);
				}
				std::cout << "Вы приобрели товар '" << fruit_juices[select_product] << " с количеством в " << count_fruit_products[select_product] << " на сумму " << (fruit_prices[select_product] * count_fruit_products[select_product]) << " рублей\n";
                std::cout << "Хотите отказаться от товара '" << fruit_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (fruit_prices[select_product] * count_fruit_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
			else {
				if ((fruit_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (fruit_prices[select_product] * count_fruit_products[select_product])) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (fruit_prices[select_product] * count_products);
				}
				std::cout << "Вы приобрели товар '" << fruit_juices[select_product] << " с количеством в " << count_fruit_products[select_product] << " на сумму " << (fruit_prices[select_product] * count_fruit_products[select_product]) << " рублей\n";
                std::cout << "Хотите отказаться от товара '" << fruit_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (fruit_prices[select_product] * count_fruit_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
		}
		else if (select_product == 5) {
			select_necessary_category(count_rubles);
		}
		else {
			std::cerr << "Вы выбрали что-то не то\n";
			exit(0);
		}
	}
	else if (select_category == 2) {
		std::cout << "Вы выбрали категорию << '" << product_category[1] << "'. Выберите для себя нужный товар. Если хотите, то можете отказаться от данной категории и выбрать другую: \n";
		for (auto i = 1; i < vegetable_juices.size(); ++i) {
			std::cout << i << ") " << vegetable_juices.at(i) << " | " << vegetable_prices[i] << " рублей" << " | " << count_vegetable_products[i] << "\n";
		}
		std::cout << 4 << ") " << "Отказаться от категории\n";
		std::cin >> select_product;
		if (select_product == 1) {
			std::cout << "Вы выбрали продукт '" << vegetable_juices[select_product] << "' \nНапишите количество товара, которое хотите приобрести:" << std::endl;
			std::cin >> count_products;
			if (count_products == count_vegetable_products[select_product]) {
				if ((vegetable_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (vegetable_prices[select_product] * count_vegetable_products[select_product])) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (vegetable_prices[select_product] * count_vegetable_products[select_product]);
				}
                std::cout << "Вы приобрели товар '" << vegetable_juices[select_product] << " с количеством в " << count_vegetable_products[select_product] << " на сумму " << (vegetable_prices[select_product] * count_vegetable_products[select_product]) << " рублей\n";
				std::cout << "Хотите отказаться от товара '" << vegetable_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (vegetable_prices[select_product] * count_vegetable_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
			else {
				if ((vegetable_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (vegetable_prices[select_product] * count_products)) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (vegetable_prices[select_product] * count_products);
				}
				std::cout << "Вы приобрели товар '" << vegetable_juices[select_product] << " с количеством в " << count_vegetable_products[select_product] << " на сумму " << (vegetable_prices[select_product] * count_vegetable_products[select_product]) << " рублей\n";
				std::cout << "Хотите отказаться от товара '" << vegetable_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (vegetable_prices[select_product] * count_vegetable_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
		}
		else if (select_product == 2) {
			std::cout << "Вы выбрали продукт '" << vegetable_juices[select_product] << "' \nНапишите количество товара, которое хотите приобрести:" << std::endl;
			std::cin >> count_products;
			if (count_products == count_vegetable_products[select_product]) {
				if ((vegetable_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (vegetable_prices[select_product] * count_vegetable_products[select_product])) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (vegetable_prices[select_product] * count_vegetable_products[select_product]);
				}
                std::cout << "Вы приобрели товар '" << vegetable_juices[select_product] << " с количеством в " << count_vegetable_products[select_product] << " на сумму " << (vegetable_prices[select_product] * count_vegetable_products[select_product]) << " рублей\n";
				std::cout << "Хотите отказаться от товара '" << vegetable_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (vegetable_prices[select_product] * count_vegetable_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
			else {
				if ((vegetable_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (vegetable_prices[select_product] * count_products)) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (vegetable_prices[select_product] * count_products);
				}
				std::cout << "Вы приобрели товар '" << vegetable_juices[select_product] << " с количеством в " << count_vegetable_products[select_product] << " на сумму " << (vegetable_prices[select_product] * count_vegetable_products[select_product]) << " рублей\n";
				std::cout << "Хотите отказаться от товара '" << vegetable_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (vegetable_prices[select_product] * count_vegetable_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
		}
		else if (select_product == 3) {
			std::cout << "Вы выбрали продукт '" << vegetable_juices[select_product] << "' \nНапишите количество товара, которое хотите приобрести:" << std::endl;
			std::cin >> count_products;
			if (count_products == count_vegetable_products[select_product]) {
				if ((vegetable_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (vegetable_prices[select_product] * count_vegetable_products[select_product])) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (vegetable_prices[select_product] * count_vegetable_products[select_product]);
				}
                std::cout << "Вы приобрели товар '" << vegetable_juices[select_product] << " с количеством в " << count_vegetable_products[select_product] << " на сумму " << (vegetable_prices[select_product] * count_vegetable_products[select_product]) << " рублей\n";
				std::cout << "Хотите отказаться от товара '" << vegetable_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (vegetable_prices[select_product] * count_vegetable_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
			else {
				if ((vegetable_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (vegetable_prices[select_product] * count_products)) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (vegetable_prices[select_product] * count_products);
				}
				std::cout << "Вы приобрели товар '" << vegetable_juices[select_product] << " с количеством в " << count_vegetable_products[select_product] << " на сумму " << (vegetable_prices[select_product] * count_vegetable_products[select_product]) << " рублей\n";
				std::cout << "Хотите отказаться от товара '" << vegetable_juices[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (vegetable_prices[select_product] * count_vegetable_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			}
		}
	}
	else if (select_category == 3) {
		std::cout << "Вы выбрали категорию << '" << product_category[2] << "'. Выберите для себя нужный товар. Если хотите, то можете отказаться от данной категории и выбрать другую: \n";
		for (auto i = 1; i < tea.size(); ++i) {
			std::cout << i << ") " << tea.at(i) << " | " << tea_prices[i] << " рублей" << " | " << count_tea_products[i] << "\n";
		}
		std::cout << 3 << ") " << "Отказаться от категории\n";
		std::cin >> select_product;
		if (select_product == 1) {
			std::cout << "Вы выбрали продукт '" << tea[select_product] << "' \nНапишите количество товара, которое хотите приобрести:" << std::endl;
			std::cin >> count_products;
			if (count_products > count_tea_products[select_product]) {
				std::cerr << "Вы не можете приобрести такое количество товаров. Выберите другое количество товаров\n";
			}
			else if (count_products == count_tea_products[select_product]) {
				if ((tea_prices[select_product] * count_tea_products[select_product]) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (tea_prices[select_product] * count_tea_products[select_product])) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
				}
				else {
					count_rubles -= (tea_prices[select_product] * count_tea_products[select_product]);
				}
				std::cout << "Вы приобрели товар '" << tea[select_product] << " с количеством в " << count_tea_products[select_product] << " на сумму " << (tea_prices[select_product] * count_tea_products[select_product]) << " рублей\n";
				std::cout << "Хотите отказаться от товара '" << tea[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (tea_prices[select_product] * count_tea_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			} else {
                if ((tea_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (tea_prices[select_product] * count_products)) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (tea_prices[select_product] * count_products);
				}
				std::cout << "Вы приобрели товар '" << tea[select_product] << " с количеством в " << count_tea_products[select_product] << " на сумму " << (vegetable_prices[select_product] * count_vegetable_products[select_product]) << " рублей\n";
				std::cout << "Хотите отказаться от товара '" << tea[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (tea_prices[select_product] * count_tea_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
            }
		}
		else if (select_product == 2) {
            std::cout << "Вы выбрали продукт '" << tea[select_product] << "' \nНапишите количество товара, которое хотите приобрести:" << std::endl;
			std::cin >> count_products;
			if (count_products > count_tea_products[select_product]) {
				std::cerr << "Вы не можете приобрести такое количество товаров. Выберите другое количество товаров\n";
			}
			else if (count_products == 5) {
                discounts.emplace_back(count_rubles * 5 / 100);
				if ((tea_prices[select_product] * count_tea_products[select_product]) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (tea_prices[select_product] * count_tea_products[select_product])) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
				}
				else {
					count_rubles -= (tea_prices[select_product] * count_tea_products[select_product]);
				}
				std::cout << "Вы приобрели товар '" << tea[select_product] << " с количеством в " << count_tea_products[select_product] << " на сумму " << (tea_prices[select_product] * count_tea_products[select_product]) << " рублей\n";
				std::cout << "Хотите отказаться от товара '" << tea[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (tea_prices[select_product] * count_tea_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
			} else {
                if ((tea_prices[select_product] * count_products) > count_rubles) {
					count_rubles = count_rubles * 13 / 100;
                    discounts.emplace_back(count_rubles);
				}
				else if (count_rubles < (tea_prices[select_product] * count_products)) {
					std::cerr << "У вас недостаточно средств, чтобы приобрести определенное количество товара.\n";
					exit(0);
				}
				else {
					count_rubles -= (tea_prices[select_product] * count_products);
				}
				std::cout << "Вы приобрели товар '" << tea[select_product] << " с количеством в " << count_tea_products[select_product] << " на сумму " << (vegetable_prices[select_product] * count_vegetable_products[select_product]) << " рублей\n";
				std::cout << "Хотите отказаться от товара '" << tea[select_product] << "'. Если да, то напишите 1. Если нет, то 0: \n";
                std::cin >> refuse_from_product;
                if(refuse_from_product == 1) {
                    count_rubles += (tea_prices[select_product] * count_tea_products[select_product]);
                    std::cout << "Ваш баланс при отказе от товара: " << count_rubles << "\n";
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                if(continue_shopping == 1) {
                    select_necessary_category(count_rubles);
                } else {
                    std::cout << "Покупка товаров завершена." << std::endl;
                    std::cout << "Итог:" << std::endl;
                    break;
                }
                } else {
                    std::cout << "Хотите продолжить покупку. Напишите 1 если да. Если нет, то 0: \n";
                    std::cin >> continue_shopping;
                    if(continue_shopping == 1) {
                        select_necessary_category(count_rubles);
                    } else {
                        std::cout << "Покупка товаров завершена." << std::endl;
                        std::cout << "Итог:" << std::endl;
                        break;
                    }
                }
            }
		}
		else if (select_product == 3) {
			select_necessary_category(count_rubles);
		}
		else {
			std::cerr << "Вы выбрали что-то не то\n";
			exit(0);
		}
	}
    }
    std::cout << "Всего на счету осталось: " << count_rubles << " рублей" << "\n";
    for(auto& every_discount : discounts) {
        sum_discounts += every_discount;
    }
    std::cout << "Было всего потрачено с учетом скидок (если они были): " << sum_discounts << " рублей" << std::endl;
    exit(0);
}

int main() {
	setlocale(LC_ALL, "Rus");
	double count_rubles = 0.0;
	std::cout << "Введите количество рублей на своем счету:\n";
	std::cin >> count_rubles;
	select_necessary_category(count_rubles);
	return 0;

}
