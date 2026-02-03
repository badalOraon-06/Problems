#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution{
  public:
  int ListLen(ListNode* head)
  {
    int len = 1;
    ListNode* temp = head;
    while(temp -> next != nullptr)
    {
      len++;
      temp = temp->next;
    }

    return len;
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
  int length = sol.ListLen(head);
  cout << "Length of the linked list: " << length << endl;

  // Clean up memory
  ListNode* curr = head;
  while (curr != nullptr) {
    ListNode* next = curr->next;
    delete curr;
    curr = next;
  }

  return 0;
}