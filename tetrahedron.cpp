#include "tetrahedron.h"

Tetrahedron::Tetrahedron(float density, int edge) : Figure(density) {
    this->edge = edge;
}

Tetrahedron *Tetrahedron::fileInput(std::ifstream *input) {
    float density;
    int edge;
    *input >> density >> edge;

    return new Tetrahedron(density, edge);
}

Tetrahedron *Tetrahedron::randomInput(float density) {
    return new Tetrahedron(density, randomInt(1, 10000));
}

void Tetrahedron::fileOutput(std::ofstream *output) const {
    *output << "Tetrahedron, edge - " + std::to_string(edge);
    Figure::fileOutput(output);
}

float Tetrahedron::volume() {
    return sqrt(2) / 12 * edge * edge * edge;
}
