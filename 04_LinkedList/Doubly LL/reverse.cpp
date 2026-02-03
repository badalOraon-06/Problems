#include<iostream>

using namespace std;

class Node{

  public:
  int data;
  Node* next;
  Node* back;

  Node(int data, Node* next, Node* back)
  {
    this->data = data;
    this->next = next;
    this->back = back;
  }

  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
    this->back = nullptr;
  }

};

Node* reverse(Node* head)
{
  if(head == nullptr || head->next == nullptr) return head;

  Node* curr = head;
  Node* temp = nullptr;

  while(curr != nullptr)
  {
    temp = curr->back;
    curr->back = curr->next;
    curr->next = temp;
    curr = curr->back;
  }

  return temp->back;
}
// Wrong
// Node* reverse(Node* head)
// {
//   Node* left = head;
//   Node* right = head;

//   while(right->next != nullptr)
//   {
//     right = right->next;
//   }

//   while(left != right && right->next != left)
//   {
//     Node* leftL = left->back;
//     Node* leftR = left->next;
//     Node* rightL = right->back;
//     Node* rightR = right->next;

//     left->back = rightL;
//     left->next = rightR;

//     right->back = leftL;
//     right->next = leftR;
//   }
// }

int main()
{
  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);
  Node* fourth = new Node(4);

  head->next = second;
  second->back = head;
  second->next = third;
  third->back = second;
  third->next = fourth;
  fourth->back = third;

  head = reverse(head);

  Node* curr = head;
  while(curr != nullptr)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  return 0;
}