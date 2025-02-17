#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <vector>
#include <iostream>

class linkedlist {
    private:
        Node* head;
    
    public:
        linkedlist();
        ~linkedlist();
    
        void build_linked_list(const std::vector<int>& values);
        void print_linked_list() const;
        void delete_entire_linked_list();
        int get_linked_list_data_item_value(int node_number) const;
        void delete_list_element(int node_number);
    };
    
    #endif
