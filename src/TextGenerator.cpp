#include "TextGenerator.h"

TextGenerator::TextGenerator(LanguageModel& model) : model(model) {}

std::string TextGenerator::generateText(int length) {
    std::string output;
    std::string word = model.getRandomStartWord();
    output += word;

    while ((int)output.size() < length) {
        char next = model.sampleNextChar(word);
        output += next;
        word = word.substr(1) + next;
    }

    return output.substr(0, length);
}