#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "container.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Only 4 arguments can be entered!\n";
        return 0;
    }

    Container container;
    srand(static_cast<unsigned int>(time(0)));

    std::ofstream output;
    if (!strcmp(argv[1], "random")) {
        // Случайное заполнение данных.
        int size = atoi(argv[2]);
        container.randomInput(size);

        output.open(argv[3]);
    } else if (!strcmp(argv[1], "file")) {
        // Ввод данных из файла.
        std::ifstream input(argv[2]);

        if (!input) {
            std::cout << "This file does not exists!\n";
            return 0;
        }

        container.fileInput(&input);
        input.close();

        output.open(argv[3]);
    } else {
        std::cout << "This command is not available!\n";
        return 0;
    }

    container.fileOutput(&output);
    container.shakerSort();
    output << "\n After shaker sort... \n";
    container.fileOutput(&output);

    output.close();
    std::cout << "\n Program has terminated :)\n";

    return 0;
}
