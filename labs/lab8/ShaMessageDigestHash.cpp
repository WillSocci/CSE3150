#include "ShaMessageDigestHash.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

//computes a hash of the input string
void ShaMessageDigestHash::compHash(const std::string& input) {

    unsigned char result[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.length(), result); //compute the hash

    std::ostringstream ss;

    //convert each byte to a hex string and append to stream
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)result[i];

    hash = ss.str();
}

//returns the hash string
std::string ShaMessageDigestHash::getHash() const {
    return hash;
}