#pragma once
#include "LanguageModel.h"

class TextGenerator {
private:
    LanguageModel& model;

public:
    TextGenerator(LanguageModel& model);
    std::string generateText(int length);
};