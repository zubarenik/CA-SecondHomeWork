#include "parallelepiped.h"

Parallelepiped::Parallelepiped(float density, int firstEdge, int secondEdge, int thirdEdge) : Figure(density) {
    this->firstEdge = firstEdge;
    this->secondEdge = secondEdge;
    this->thirdEdge = thirdEdge;
}

Parallelepiped *Parallelepiped::fileInput(std::ifstream *input) {
    float density;
    int firstEdge, secondEdge, thirdEdge;
    *input >> density >> firstEdge >> secondEdge >> thirdEdge;

    return new Parallelepiped(density, firstEdge, secondEdge, thirdEdge);
}

Parallelepiped *Parallelepiped::randomInput(float density) {
    return new Parallelepiped(density, randomInt(1, 10000), randomInt(1, 10000), randomInt(1, 10000));
}

void Parallelepiped::fileOutput(std::ofstream *output) const {
    *output << "Parallelepiped, first edge - " + std::to_string(firstEdge)
               + ", second edge - " + std::to_string(secondEdge)
               + ", third edge - " + std::to_string(thirdEdge);
    Figure::fileOutput(output);
}

float Parallelepiped::volume() {
    return firstEdge * secondEdge * thirdEdge;
}
