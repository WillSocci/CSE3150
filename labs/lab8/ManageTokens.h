#ifndef MANAGETOKENS_H
#define MANAGETOKENS_H

#include <vector>
#include <memory>
#include "NfToken.h"
#include "ShaMessageDigestHash.h"


//links the manage tokens to eveything else to be called easy
class ManageTokens {
public:
    static std::unique_ptr<NfToken> mintToken(const std::string& name, const std::string& uniqueData);
    static void transferToken(std::vector<std::unique_ptr<NfToken>>& toWallet, std::vector<std::unique_ptr<NfToken>>& fromWallet, size_t index);
};

#endif