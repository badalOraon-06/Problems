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

Node* insert(Node* head, int data)
{
  Node* newNode = new Node(data);

  if(head == nullptr) return newNode;

  Node* tail = head;

  while(tail->next != nullptr) tail = tail->next;

  tail->next = newNode;
  newNode->back = tail;

  return newNode;
}

Node* deleteLast(Node* head)
{
  if(head == nullptr) return head;

  else if(head->next == nullptr)
  {
    delete head;
    return nullptr;
  }

  Node* temp = head;

  while(temp->next->next != nullptr)
  {
    temp = temp->next;
  }

  Node* tail = temp->next;
  temp->next = nullptr;
  delete tail;

  return head;
}


int main()
{


  return 0;

}