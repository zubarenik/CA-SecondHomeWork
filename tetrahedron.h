#include <cstdio>
#include <fstream>
#include <cmath>
#include "figure.h"
#include "random.h"

#ifndef SECONDHOMEWORK_TETRAHEDRON_H
#define SECONDHOMEWORK_TETRAHEDRON_H

class Tetrahedron : public Figure {
private:
    int edge;

public:
    Tetrahedron(float density, int edge);

    // Ввод данных из файла.
    static Tetrahedron *fileInput(std::ifstream *input);

    // Случайная генерация данных.
    static Tetrahedron *randomInput(float density);

    // Вывод результата в файл.
    void fileOutput(std::ofstream *output) const override;

    // Вычисление объема.
    float volume() override;
};

#endif //SECONDHOMEWORK_TETRAHEDRON_H
