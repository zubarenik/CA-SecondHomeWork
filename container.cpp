#include "container.h"

Container::Container() {
    figures = new Figure*[CAPACITY];
    size = 0;
}

Container::~Container() {
    delete[] figures;
    figures = nullptr;
    size = 0;
}

void Container::fileInput(std::ifstream *input) {
    int type = 0;
    while (*input >> type) {
        try {
            figures[size] = Figure::fileInput(input, type);
            ++size;
        } catch (std::invalid_argument &exception) {
            std::cout << exception.what() << "Only the first " + std::to_string(size) + " objects are loaded! \n";
            break;
        } catch (std::exception &exception) {
            std::cout << "Only the first " + std::to_string(size) + " objects are loaded! \n";
            break;
        }
    }
}

void Container::randomInput(int size) {
    if (size < 0) {
        std::cout << "Size must be more than zero! \n";
        return;
    }

    while (this->size < size) {
        figures[this->size] = Figure::randomInput();
        ++this->size;

        if (this->size == CAPACITY) {
            printf("Only %i objects can be created! \n", CAPACITY);
            break;
        }
    }
}

void Container::fileOutput(std::ofstream *output) {
    *output << "\n Container's size - " + std::to_string(size) + " \n";

    for (int i = 0; i < size; ++i) {
        *output << std::to_string(i + 1) + ": ";
        figures[i]->fileOutput(output);
    }
}

void Container::swap(int i) {
    auto temp = figures[i];
    figures[i] = figures[i - 1];
    figures[i - 1] = temp;
}

void Container::shakerSort() {
    int left = 1, right = size - 1;

    while (left <= right) {
        for (int i = right; i >= left; --i) {
            if (figures[i - 1]->volume() < figures[i]->volume()) {
                swap(i);
            }
        }
        ++left;
        for (int i = left; i <= right; ++i) {
            if (figures[i - 1]->volume() < figures[i]->volume()) {
                swap(i);
            }
        }
        --right;
    }
}
