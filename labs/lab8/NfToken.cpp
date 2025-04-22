#include "NfToken.h"

//default constructor
NfToken::NfToken() {}

//constructor initializes the name
NfToken::NfToken(const std::string& n) : name(n) {}

//returns the name of the token
std::string NfToken::getName() const {
    return name;
}

//returns the hash of the token
std::string NfToken::getHash() const {
    return hash;
}

//sets the name of the token
void NfToken::setName(const std::string& n) {
    name = n;
}

//sets the hash of the token
void NfToken::setHash(const std::string& h) {
    hash = h;
}