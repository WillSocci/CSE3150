#include "tokenizer.h"
#include <iostream>

int main() {
    Tokenizer tokenizer;
    tokenizer.loadFromFile("passage.txt");

    //prints out the words and tokens that are related to 
    std::cout << "Token: " << tokenizer.getToken("always") << std::endl;
    std::cout << "Token 24: " << tokenizer.getWord(24) << std::endl;
    std::cout << "Token 0: " << tokenizer.getWord(0) << std::endl;
    std::cout << "Token 1: " << tokenizer.getWord(1) << std::endl;
    std::cout << "Token 2: " << tokenizer.getWord(2) << std::endl;
    std::cout << "Token 3: " << tokenizer.getWord(3) << std::endl;
    std::cout << "Token 4: " << tokenizer.getWord(4) << std::endl;

    return 0;
}
