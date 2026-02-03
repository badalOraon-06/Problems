#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution{
  public:
  bool ListLen(ListNode* head, int element)
  {
    ListNode* temp = head;
    while(temp != nullptr)
    {
      if(temp->val == element) return true;
      temp = temp->next;
    }

    return false;    
  }
};

int main()
{
  ListNode* head = new ListNode(1);
  ListNode* second = new ListNode(2);
  ListNode* third = new ListNode(3);
  head->next = second;
  second->next = third;

  Solution sol;
  int element = 2;
  bool found = sol.ListLen(head, element);
  if (found) {
    cout << "Element " << element << " found in the linked list." << endl;
  } else {
    cout << "Element " << element << " not found in the linked list." << endl;
  }

  // Clean up memory
  ListNode* curr = head;
  while (curr != nullptr) {
    ListNode* next = curr->next;
    delete curr;
    curr = next;
  }

  return 0;
}