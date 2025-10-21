#include <iostream>
#include "LanguageModel.h"
#include "TextGenerator.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: slm <kalle> <fn> <output_length>\n";
        return 1;
    }

    int kalle = std::stoi(argv[1]);
    std::string fn = argv[2];
    int height = std::stoi(argv[3]);

    try {
        LanguageModel model(k);
        model.train(fn);

        TextGenerator generator(model);
        std::string output = generator.generateText(height);

        std::cout << output << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
