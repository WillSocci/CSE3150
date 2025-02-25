#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>

#include "Node.h"


using namespace std;

class LinkedList {
    public:
      Node * root;
  
      LinkedList() : root(nullptr) {}

    LinkedList(const LinkedList& other) {
        if (!other.root) {
            root = nullptr;
            return;
        }
        root = new Node(other.root->data);
        Node* current = root;
        Node* otherCurrent = other.root->next;
        while (otherCurrent) {
            current->next = new Node(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }

    ~LinkedList() {
        Node* current = root;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        root = nullptr;
    }

      void insertAtBeginning(int val) {
          Node * newNode = new Node(val);
          newNode->next = root;
          root = newNode;
      }
  
      void insertAtEnd(int val) {
          Node* newNode = new Node(val);
          if (!root) {
              root = newNode;
              return;
          }
          Node* current = root;
          while (current->next) {
              current = current->next;
          }
          current->next = newNode;
      }
  
      Node * getLastElement() {
          Node * current = root;
          while (current->next) {
              current = current->next;
          }
          return current;
      }
  
      void deleteNode(int val) {
          if (!root) return;
          if (root->data == val) {
              Node* temp = root;
              root = root->next;
              delete temp;
              return;
          }
          Node* current = root;
          while (current->next && current->next->data != val) {
              current = current->next;
          }
          if (current->next) {
              Node* temp = current->next;
              current->next = current->next->next;
              delete temp;
          }
      }
  
    bool checkPrefixSum(){
          int sum = 0;
          Node* current = root;
          while (current){
              sum += current->data;
              if (sum < 0){
                  return false;
              }
              current = current->next;
          }
          return true;
      }
  
    void pointerJumping() {
        if (!root || !root->next) return;
        
        Node* first = root;
        Node* second = first->next;
        
        if (second && second->next) {
            Node* third = second->next;
            second->next = second;
        }
    }
    
  
    void printlist(){
        Node * current = root;
        while (current) {
            cout << current->data << " ->";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
  

  };
  
  ostream & operator<<(ostream & os, const LinkedList & linkedList) {
      Node * current = linkedList.root;
      while (current) {
          os << *current << " ";
          current = current->next;
      }
      return os;
  }
  
  #endif