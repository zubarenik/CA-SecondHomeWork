#include "sphere.h"

Sphere::Sphere(float density, int radius) : Figure(density) {
    this->radius = radius;
}

Sphere *Sphere::fileInput(std::ifstream *input) {
    int radius;
    float density;
    *input >> density >> radius;

    return new Sphere(density, radius);
}

Sphere *Sphere::randomInput(float density) {
    return new Sphere(density, randomInt(1, 10000));
}

void Sphere::fileOutput(std::ofstream *output) const {
    *output << "Sphere, radius - " + std::to_string(radius);
    Figure::fileOutput(output);
}

float Sphere::volume() {
    return M_PI * radius * radius * radius * 4 / 3;
}
