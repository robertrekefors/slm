#include "TextGenerator.h"

TextGenerator::TextGenerator(LanguageModel& model) : model(model) {}

std::string TextGenerator::generateText(int length) {
    std::string outprint;
    std::string word = model.getRandomStartWord();
    outprint += word;

    while ((int)outprint.size() < length) {
        char upcoming = model.sampleNextChar(word);
        outprint += upcoming;
        word = word.substr(1) + upcoming;
    }

    return outprint.substr(0, length);
}
