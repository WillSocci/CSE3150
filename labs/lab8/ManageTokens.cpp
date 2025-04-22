#include "ManageTokens.h"

//manages the tokens and
std::unique_ptr<NfToken> ManageTokens::mintToken(const std::string& name, const std::string& uniqueData) {
    ShaMessageDigestHash hashTool;
    hashTool.compHash(uniqueData);

    auto token = std::make_unique<NfToken>(name);
    token->setHash(hashTool.getHash());
    return token;
}

//transfers a token from one wallet to the other
void ManageTokens::transferToken(std::vector<std::unique_ptr<NfToken>>& toWallet, std::vector<std::unique_ptr<NfToken>>& fromWallet, size_t index) {

    if (index < fromWallet.size()) {

        toWallet.push_back(std::move(fromWallet[index]));
        fromWallet.erase(fromWallet.begin() + index);

    }
}