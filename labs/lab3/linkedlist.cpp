#include "linkedlist.h"

linkedlist::linkedlist() {
    head = nullptr;
}

linkedlist::~linkedlist() {
    delete_entire_linked_list();
}

void linkedlist::build_linked_list(const std::vector<int>& values) {
    delete_entire_linked_list();
    
    if (values.empty()) {
        return;
    }
    
    head = new Node(values[0]);
    Node* current = head;
    
    for (int i = 1; i < values.size(); i++) {
        current->next = new Node(values[i]);
        current = current->next;
    }
}

void linkedlist::print_linked_list() const {  // Added const here
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << " -> NULL" << std::endl;
}

void linkedlist::delete_entire_linked_list() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int linkedlist::get_linked_list_data_item_value(int position) const {  // Added const here
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return -1;
    }
    
    Node* current = head;
    int current_pos = 0;
    
    while (current != nullptr && current_pos < position) {
        current = current->next;
        current_pos++;
    }
    
    if (current == nullptr) {
        std::cout << "Position not found!" << std::endl;
        return -1;
    }
    
    return current->data;
}

void linkedlist::delete_list_element(int position) {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node* current = head;
    int current_pos = 0;
    
    while (current != nullptr && current_pos < position - 1) {
        current = current->next;
        current_pos++;
    }
    
    if (current == nullptr || current->next == nullptr) {
        std::cout << "Position not found!" << std::endl;
        return;
    }
    
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}