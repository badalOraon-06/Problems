#include <iostream>

using namespace std;

class Node {
public:
    int data;    
    Node* next;  

    Node(int value) {
        data = value;
        next = nullptr;  
    }
};


class LinkedListQueue {
  Node* dummy;
  Node* tail;
public:
    LinkedListQueue() {
      this->dummy = new Node(-1);
      this->tail = dummy;
    }
    
    void push(int x) {
      Node* newNode = new Node(x);
      tail->next = newNode;

      tail = tail->next;
    }
    
    int pop() {
      if(dummy->next == nullptr) return -1;

      Node* temp = dummy->next;
      dummy->next = dummy->next->next;
      int toReturn = temp->data;

      delete temp;

      return toReturn;
    }
    
    int peek() {
      if(dummy->next == nullptr) return -1;

      return dummy->next->data;    
    }
    
    bool isEmpty() {
      if(dummy->next == nullptr) return true;

      return false;
    }
};


int main()
{

  return 0;
}