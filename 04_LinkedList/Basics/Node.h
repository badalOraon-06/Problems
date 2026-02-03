
class Node{
  public:
  int data;
  Node* next;

  Node(int data1,Node* next1)
  {
    data = data1;
    next = next1;
  }
  Node(int data1)
  {
    data = data1;
    next = nullptr;
  }
};

void print(Node* head)
{
  while(head != nullptr)
  {
    cout<<head -> data<<"->";
    head = head -> next;
  }
  cout<<"NULL"<<endl;
}