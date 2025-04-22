#ifndef NFTOKEN_H
#define NFTOKEN_H

#include <string>

//set the NfTokens
class NfToken {
private:
    std::string name;
    std::string hash;

public:
    NfToken();
    NfToken(const std::string& name);

    std::string getName() const;
    std::string getHash() const;

    void setName(const std::string& n);
    void setHash(const std::string& h);
};

#endif