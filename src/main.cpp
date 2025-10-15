#include <iostream>
#include "LanguageModel.h"
#include "TextGenerator.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: slm <k> <filename> <output_length>\n";
        return 1;
    }

    int k = std::stoi(argv[1]);
    std::string filename = argv[2];
    int length = std::stoi(argv[3]);

    try {
        LanguageModel model(k);
        model.train(filename);

        TextGenerator generator(model);
        std::string output = generator.generateText(length);

        std::cout << output << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}