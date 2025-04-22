#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
#include <openssl/sha.h>

#include "NfToken.h"
#include "ShaMessageDigestHash.h"
#include "ManageTokens.h"

using namespace std;

ostream & operator<<(ostream & os, const NfToken & nft) {
    os << nft.getName() << " " << nft.getHash();
    return os;
}

int main() {
    int totalNfts = 0;
    ShaMessageDigestHash sha256Hash;

    cout << "How many NFTs? ";
    cin >> totalNfts;
    cout << endl;

    vector<unique_ptr<NfToken>> wallet1;
    vector<unique_ptr<NfToken>> wallet2;

    //based on the number of nfts enter names for them all
    string nftName;
    for (int i = 0; i < totalNfts; i++) {
        cout << "Enter the name for this NFT: ";
        cin >> nftName;

        auto newToken = ManageTokens::mintToken(nftName, nftName + to_string(i));
        wallet1.push_back(move(newToken));
    }
    
    //display wallet 1 and each token for the nft
    cout << "\nWallet1 before transfer:" << endl;
    for (const auto& token : wallet1)
        cout << *token << endl;

    if (!wallet1.empty()) {
        ManageTokens::transferToken(wallet2, wallet1, 0);
    }


    //after the transfer display wallet 1 and 2
    cout << "\nWallet1 after transfer:" << endl;
    for (const auto& token : wallet1)
        cout << *token << endl;

    cout << "\nWallet2 after transfer:" << endl;
    for (const auto& token : wallet2)
        cout << *token << endl;

    return 0;
}