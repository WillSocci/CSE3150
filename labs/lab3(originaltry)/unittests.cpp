#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/workspaces/CSE3150/include/doctest.h"
#include "linkedlist.h"

TEST_CASE("set up the list and then print it") {

    linkedlist list;
    list.build_linked_list({4, 1, 2, 3, 5});

    CHECK(list.get_linked_list_data_item_value(0) == 4);
    CHECK(list.get_linked_list_data_item_value(2) == 2);
}

TEST_CASE("delete one of the lists elements") {

    linkedlist list;
    list.build_linked_list({4, 1, 2, 3, 5});
    
    list.delete_list_element(2);
    CHECK(list.get_linked_list_data_item_value(2) == 3);
}

TEST_CASE("delete the whole list") {

    linkedlist list;
    list.build_linked_list({1, 2, 3});
    
    list.delete_entire_linked_list();
    
    CHECK(list.get_linked_list_data_item_value(0));
}
