#include<iostream>

using namespace std;
#include"Node.h"



Node* addBeforeHead(Node* head, int val)
{
  Node* newHead = new Node(val);
  newHead ->next = head;

  return newHead;
}


  int main() {
    Node* head = new Node(10);   // Initial node
    head = addBeforeHead(head, 5);  // Add 5 before head
    head = addBeforeHead(head, 1);  // Add 1 before head

    print(head);  // Output: 1->5->10->NULL

    return 0;
}
