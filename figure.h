#include <iostream>
#include <fstream>

#ifndef SECONDHOMEWORK_FIGURE_H
#define SECONDHOMEWORK_FIGURE_H

class Figure {
private:
    float density;

protected:
    explicit Figure(float density);

public:
    // Ввод данных из файла.
    static Figure *fileInput(std::ifstream *input, int type);

    // Генерация случайных данных.
    static Figure *randomInput();

    // Вывод результата в файл.
    virtual void fileOutput(std::ofstream *output) const;

    // Вычисление объема.
    virtual float volume() = 0;
};

#endif //SECONDHOMEWORK_FIGURE_H
