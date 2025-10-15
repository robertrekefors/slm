#include "LanguageModel.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <ctime>

LanguageModel::LanguageModel(int k) : k(k) {
    std::random_device rd;
    rng.seed(rd());
}
void LanguageModel::train(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);

    std::string text((std::istreambuf_iterator<char>(file)),
                      std::istreambuf_iterator<char>());

    // --- Rensa texten ---
    for (char& ch : text) {
        ch = std::tolower(static_cast<unsigned char>(ch));
        if (!std::isalpha(static_cast<unsigned char>(ch)) && ch != ' ' && ch != '.')
            ch = ' ';
    }

    // --- Ta bort dubbelmellanslag ---
    std::string cleaned;
    bool lastWasSpace = false;
    for (char ch : text) {
        if (ch == ' ') {
            if (!lastWasSpace) cleaned += ch;
            lastWasSpace = true;
        } else {
            cleaned += ch;
            lastWasSpace = false;
        }
    }

    // Ta bort mellanslag i början och slutet
    if (!cleaned.empty() && cleaned.front() == ' ')
        cleaned.erase(cleaned.begin());
    if (!cleaned.empty() && cleaned.back() == ' ')
        cleaned.pop_back();

    text = cleaned;

    if ((int)text.size() <= k) {
        throw std::runtime_error("Text too short for given k");
    }

    // --- Bygg frekvenstabeller ---
    for (size_t i = 0; i + k < text.size(); ++i) {
        std::string word = text.substr(i, k);
        char next = text[i + k];
        wordCounts[word]++;
        transitions[word][next]++;
    }
}

char LanguageModel::sampleNextChar(const std::string& word) {
    auto it = transitions.find(word);
    if (it == transitions.end()) {
        std::uniform_int_distribution<int> dist(32, 126);
        return static_cast<char>(dist(rng));
    }

    const auto& nextMap = it->second;
    int total = 0;
    for (const auto& p : nextMap)
        total += p.second;

    std::uniform_int_distribution<int> dist(1, total);
    int r = dist(rng);

    for (const auto& p : nextMap) {
        r -= p.second;
        if (r <= 0)
            return p.first;
    }

    return nextMap.begin()->first;
}

std::string LanguageModel::getRandomStartWord() const {
    if (wordCounts.empty())
        throw std::runtime_error("Model not trained.");

    int total = 0;
    for (const auto& p : wordCounts)
        total += p.second;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, total);
    int r = dist(gen);

    for (const auto& p : wordCounts) {
        r -= p.second;
        if (r <= 0)
            return p.first;
    }

    return wordCounts.begin()->first;
}