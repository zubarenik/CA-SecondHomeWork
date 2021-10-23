#include <cstdio>
#include <fstream>
#include <cmath>
#include "random.h"
#include "figure.h"

#ifndef SECONDHOMEWORK_SPHERE_H
#define SECONDHOMEWORK_SPHERE_H


class Sphere : public Figure {
private:
    int radius;

public:
    Sphere(float density, int radius);

    // Ввод данных из файла.
    static Sphere *fileInput(std::ifstream *input);

    // Случайная генерация данных.
    static Sphere *randomInput(float density);

    // Вывод результата в файл.
    void fileOutput(std::ofstream *output) const override;

    // Вычисление объема.
    float volume() override;
};

#endif //SECONDHOMEWORK_SPHERE_H
