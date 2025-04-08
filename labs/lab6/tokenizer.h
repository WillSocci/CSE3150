#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <unordered_map>
#include <vector>

//gets all the functions from the seperate files to allow a test and a main file
class Tokenizer {

public:

    void loadFromFile(const std::string& filename);
    int getToken(const std::string& word) const;
    std::string getWord(int token) const;

private:

    std::unordered_map<std::string, int> wordToToken;
    std::vector<std::string> tokenToWord;
};

#endif
