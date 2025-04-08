#include "tokenizer.h"
#include <cassert>
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/workspaces/CSE3150/include/doctest.h"

TEST_CASE("get tokens and words") {
    Tokenizer tokenizer;
    tokenizer.loadFromFile("passage.txt");

    //check for the correct token for each word
    CHECK(tokenizer.getToken("I") == 0);
    CHECK(tokenizer.getToken("HAD") == 1);
    CHECK(tokenizer.getToken("always") == 2);
    CHECK(tokenizer.getToken("thought") == 3);
    CHECK(tokenizer.getToken("Jack") == 4);
    CHECK(tokenizer.getToken("Gisburn") == 5);
    CHECK(tokenizer.getToken("rather") == 6);
    CHECK(tokenizer.getToken("a") == 7);
    CHECK(tokenizer.getToken("cheap") == 8);

    //same thing but check the correct word for token
    CHECK(tokenizer.getWord(0) == "I");
    CHECK(tokenizer.getWord(1) == "HAD");
    CHECK(tokenizer.getWord(2) == "always");
    CHECK(tokenizer.getWord(3) == "thought");
    CHECK(tokenizer.getWord(4) == "Jack");
    CHECK(tokenizer.getWord(5) == "Gisburn");
    CHECK(tokenizer.getWord(6) == "rather");
    CHECK(tokenizer.getWord(7) == "a");
    CHECK(tokenizer.getWord(8) == "cheap");

}