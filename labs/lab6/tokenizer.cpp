#include "tokenizer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>

//opens up the file
void Tokenizer::loadFromFile(const std::string& filename) {

    std::ifstream file(filename);
    std::string line;
    int tokenNum = 0;

    //gets rid of punctuation
    std::regex word_regex(R"(\b\w+\b)");

    //searches through every word and assigns the token if it's been seen already then no need
    while (std::getline(file, line)) {

        std::sregex_iterator begin(line.begin(), line.end(), word_regex);
        std::sregex_iterator end;

        for (std::sregex_iterator i = begin; i != end; ++i) {

            std::string word = i->str();

            if (wordToToken.find(word) == wordToToken.end()) {
                wordToToken[word] = tokenNum;
                tokenToWord.push_back(word);
                ++tokenNum;
            }
        }
    }
}

//searches through tokens to find the corresponding word
int Tokenizer::getToken(const std::string& word) const {

    auto i = wordToToken.find(word);
    return (i != wordToToken.end()) ? i->second : -1;

}

//searches through words to find the corresponding token
std::string Tokenizer::getWord(int token) const {

    if (token >= 0 && token < tokenToWord.size()) {
        return tokenToWord[token];
    }
    return "";

}
