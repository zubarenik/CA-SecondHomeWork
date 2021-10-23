#include <cstdio>
#include <fstream>
#include "figure.h"
#include "random.h"

#ifndef SECONDHOMEWORK_PARALLELEPIPED_H
#define SECONDHOMEWORK_PARALLELEPIPED_H

class Parallelepiped : public Figure {
private:
    int firstEdge, secondEdge, thirdEdge;

public:
    Parallelepiped(float density, int firstEdge, int secondEdge, int thirdEdge);

    // Ввод данных из файла.
    static Parallelepiped *fileInput(std::ifstream *input);

    // Случайная генерация данных.
    static Parallelepiped *randomInput(float density);

    // Вывод результата в файл.
    void fileOutput(std::ofstream *output) const override;

    // Вычисление объема.
    float volume() override;
};

#endif //SECONDHOMEWORK_PARALLELEPIPED_H
