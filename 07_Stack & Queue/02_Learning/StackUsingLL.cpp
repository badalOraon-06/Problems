#include<iostream>
#include<list>

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

class LinkedListStack {
  Node* dummy;
public:
    LinkedListStack() {
      this->dummy = new Node(-1);
    }
    
    void push(int x) {
      Node* newHead = new Node(x);
      newHead->next = dummy->next;
      dummy->next = newHead;
    }
    
    int pop() {
      if(dummy->next == nullptr) return -1;
      
      Node* temp = dummy->next;
      dummy->next = dummy->next->next;
      int toReturn = temp->data;

      delete temp;
      
      return toReturn;
    }
    
    int top() {
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