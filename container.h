#include <iostream>
#include <fstream>
#include <string>
#include "figure.h"

#ifndef SECONDHOMEWORK_CONTAINER_H
#define SECONDHOMEWORK_CONTAINER_H

class Container {
private:
    const int CAPACITY = 10000;
    int size;
    Figure **figures;

public:
    Container();

    ~Container();

    // Ввод данных из файла.
    void fileInput(std::ifstream *input);

    // Случайная генерация данных.
    void randomInput(int size);

    // Вывод результата в файл.
    void fileOutput(std::ofstream *output);

    // Меняет элементы местами.
    void swap(int i);

    // Сортировка Shaker Sort.
    void shakerSort();
};

#endif //SECONDHOMEWORK_CONTAINER_H
