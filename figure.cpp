#include "figure.h"
#include "sphere.h"
#include "parallelepiped.h"
#include "tetrahedron.h"

Figure::Figure(float density) {
    this->density = density;
}

Figure *Figure::fileInput(std::ifstream *input, int type) {
    if (type == 1) {
        return Sphere::fileInput(input);
    } else if (type == 2) {
        return Parallelepiped::fileInput(input);
    } else if (type == 3) {
        return Tetrahedron::fileInput(input);
    }

    throw std::invalid_argument("An object of this type does not exist! \n");
}

Figure *Figure::randomInput() {
    float density = randomFloat();
    int type = randomInt(1, 3);
    if (type == 1) {
        return Sphere::randomInput(density);
    } else if (type == 2) {
        return Parallelepiped::randomInput(density);
    } else {
       return Tetrahedron::randomInput(density);
    }
}

void Figure::fileOutput(std::ofstream *output) const {
    *output << ", density - " + std::to_string(density) +  " \n";
}
