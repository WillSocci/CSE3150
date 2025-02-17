#include "linkedlist.h"

int main() {
    
    linkedlist list;

    list.build_linked_list({1, 2, 3, 4, 5});
    list.print_linked_list();

    std::cout << "Node 2 value: " << list.get_linked_list_data_item_value(2) << std::endl;

    list.delete_list_element(2);
    list.print_linked_list();

    list.delete_entire_linked_list();
    list.print_linked_list();

    return 0;
}
