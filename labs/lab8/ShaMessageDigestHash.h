#ifndef SHAMESSAGEDIGESTHASH_H
#define SHAMESSAGEDIGESTHASH_H

#include <string>

//set up the hash
class ShaMessageDigestHash {
private:
    std::string hash;

public:
    void compHash(const std::string& input);
    std::string getHash() const;
};

#endif