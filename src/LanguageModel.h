#pragma once
#include <string>
#include <map>
#include <vector>
#include <random>

class LanguageModel {
private:
    int k;  // ordlängd
    std::map<std::string, std::map<char, int>> transitions; // w -> (c -> n(w,c))
    std::map<std::string, int> wordCounts; // w -> n(w)
    std::mt19937 rng; // slumpgenerator

public:
    LanguageModel(int k);
    void train(const std::string& filename);
    char sampleNextChar(const std::string& word);
    std::string getRandomStartWord() const;
};