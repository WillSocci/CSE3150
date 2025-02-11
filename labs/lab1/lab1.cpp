#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/workspaces/CSE3150/include/doctest.h"

bool non_negative_prefix_sum(int lst[], int len){
    bool value = true;
    int sum = 0;
    for (int i = 0; i < len; i++){
        sum += lst[i];
        if (sum < 0){
            value = false;
            break;
        }
    }
    return value;
}

bool non_positive_prefix_sum(int lst[], int len){
    bool value = true;
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += lst[i];
        if (sum > 0){
            value = false;
            break;
        }
    }
    return value;
}

TEST_CASE("testing the factorial function") {
    int lst0[] = {};
    int lst1[] = {1, -1, 1, -1};
    int lst2[] = {1, -1, -1, 1};
    int lst3[] = {0, -1, 1, -1};
    int lst4[] = {-1, 1, 0, 0};
    int lst5[] = {-1};
    int lst6[] = {1};
    int lst7[] = {0};
    int lst8[] = {0, -1, 1};
    int lst9[] = {0, 1, -1};
    int lst10[] = {-1, -1, -1, -1};
    int lst11[] = {1, 1, 1, 1};

    CHECK(non_negative_prefix_sum(lst0, sizeof(lst0)/sizeof(int)));
    CHECK(non_negative_prefix_sum(lst1, sizeof(lst1)/sizeof(int)));
    CHECK(non_negative_prefix_sum(lst2, sizeof(lst2)/sizeof(int)));
    CHECK(non_negative_prefix_sum(lst3, sizeof(lst3)/sizeof(int)));
    CHECK(non_negative_prefix_sum(lst4, sizeof(lst4)/sizeof(int)));
    CHECK(non_negative_prefix_sum(lst5, sizeof(lst5)/sizeof(int)));
    CHECK(non_negative_prefix_sum(lst6, sizeof(lst6)/sizeof(int)));
    CHECK(non_negative_prefix_sum(lst7, sizeof(lst7)/sizeof(int)));
    CHECK(non_negative_prefix_sum(lst8, sizeof(lst8)/sizeof(int)));
    CHECK(non_negative_prefix_sum(lst9, sizeof(lst9)/sizeof(int)));
    CHECK(non_negative_prefix_sum(lst10, sizeof(lst10)/sizeof(int)));
    CHECK(non_negative_prefix_sum(lst11, sizeof(lst11)/sizeof(int)));

    CHECK(non_positive_prefix_sum(lst0, sizeof(lst0)/sizeof(int)));
    CHECK(non_positive_prefix_sum(lst1, sizeof(lst1)/sizeof(int)));
    CHECK(non_positive_prefix_sum(lst2, sizeof(lst2)/sizeof(int)));
    CHECK(non_positive_prefix_sum(lst3, sizeof(lst3)/sizeof(int)));
    CHECK(non_positive_prefix_sum(lst4, sizeof(lst4)/sizeof(int)));
    CHECK(non_positive_prefix_sum(lst5, sizeof(lst5)/sizeof(int)));
    CHECK(non_positive_prefix_sum(lst6, sizeof(lst6)/sizeof(int)));
    CHECK(non_positive_prefix_sum(lst7, sizeof(lst7)/sizeof(int)));
    CHECK(non_positive_prefix_sum(lst8, sizeof(lst8)/sizeof(int)));
    CHECK(non_positive_prefix_sum(lst9, sizeof(lst9)/sizeof(int)));
    CHECK(non_positive_prefix_sum(lst10, sizeof(lst10)/sizeof(int)));
    CHECK(non_positive_prefix_sum(lst11, sizeof(lst11)/sizeof(int)));

}
