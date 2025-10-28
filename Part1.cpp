#include <bits/stdc++.h>

using string = std::string;

std::pair<int*,int> dynamic_array_distribution(int size) {
    if(size <= 0) {
        throw std::runtime_error("Размер массива не может быть нулевым или отрицательным");
    }
    int*dyn_array = new int[size];
    return {dyn_array,size};
}

void dynamic_array_initialize(int* &dyn_array, int size) {
    for(int i = 0; i < size; ++i) {
        dyn_array[i] = i + 1;
    }
}

void dynamic_array_typing(int* &dyn_array, int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << dyn_array[i] << " ";
    }
    std::cout << std::endl;
}

 void dynamic_array_append(int* &dyn_array, int &size, int element) {
    int* temporary_memory = new int[size];
    for(int i = 0; i < size; ++i) {
        temporary_memory[i] = std::move(dyn_array[i]);
    }
    delete[]dyn_array;
    size += 1;
    dyn_array = new int[size];
    for(int i = 0; i < size - 1; ++i) {
        dyn_array[i] = std::move(temporary_memory[i]);
    }
    dyn_array[size - 1] = element;
    delete[]temporary_memory;
    temporary_memory = nullptr;
}


void dynamic_array_deleting(int* &dyn_array) {
    delete[]dyn_array;
    dyn_array = nullptr;
}

int main() {
    setlocale(LC_ALL,"Rus");
    auto array = dynamic_array_distribution(10);
    dynamic_array_initialize(array.first,array.second);
    dynamic_array_typing(array.first,array.second);
    dynamic_array_append(array.first,array.second,11);
    dynamic_array_typing(array.first,array.second);
    dynamic_array_deleting(array.first);
    return 0;
}
