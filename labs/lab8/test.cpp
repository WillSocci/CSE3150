#include "NfToken.h"
#include "ManageTokens.h"
#include "ShaMessageDigestHash.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/workspaces/CSE3150/include/doctest.h"
#include <memory>
#include <vector>

TEST_CASE("NfToken tests") {
    SUBCASE("token creation and hash generation") {

        // manually create a token and set hash using the hashing tool
        auto token = std::make_unique<NfToken>();
        token->setName("TestToken");

        ShaMessageDigestHash hasher;
        hasher.compHash("asset123");
        token->setHash(hasher.getHash());

        CHECK(token->getName() == "TestToken");
        CHECK(token->getHash() != "");

        //check same hash for same input
        ShaMessageDigestHash hasherA;
        ShaMessageDigestHash hasherB;
        hasherA.compHash("sameAsset");
        hasherB.compHash("sameAsset");

        CHECK(hasherA.getHash() == hasherB.getHash());

        //check different hash for different input
        ShaMessageDigestHash hasherC;
        hasherC.compHash("differentAsset");
        CHECK(hasherA.getHash() != hasherC.getHash());
    }
}

TEST_CASE("ManageTokens tests") {
    std::vector<std::unique_ptr<NfToken>> wallet1;
    std::vector<std::unique_ptr<NfToken>> wallet2;

    SUBCASE("minting tokens") {
        CHECK(wallet1.size() == 0);
        CHECK(wallet2.size() == 0);

        auto token1 = ManageTokens::mintToken("Token1", "asset1");
        wallet1.push_back(std::move(token1));
        CHECK(wallet1.size() == 1);
        CHECK(wallet2.size() == 0);

        auto token2 = ManageTokens::mintToken("Token2", "asset2");
        wallet1.push_back(std::move(token2));
        CHECK(wallet1.size() == 2);
    }

    SUBCASE("transferring tokens") {
        auto token1 = ManageTokens::mintToken("Token1", "asset1");
        auto token2 = ManageTokens::mintToken("Token2", "asset2");
        wallet1.push_back(std::move(token1));
        wallet1.push_back(std::move(token2));

        CHECK(wallet1.size() == 2);
        CHECK(wallet2.size() == 0);

        //transfer first token
        ManageTokens::transferToken(wallet2, wallet1, 0);
        CHECK(wallet1.size() == 1);
        CHECK(wallet2.size() == 1);

        //transfer second token
        ManageTokens::transferToken(wallet2, wallet1, 0);
        CHECK(wallet1.size() == 0);
        CHECK(wallet2.size() == 2);

        //try bad transfer
        ManageTokens::transferToken(wallet2, wallet1, 0);
        CHECK(wallet1.size() == 0);
        CHECK(wallet2.size() == 2);
    }
}