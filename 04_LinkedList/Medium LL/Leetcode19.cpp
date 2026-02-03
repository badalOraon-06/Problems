#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

      ListNode* dummy = new ListNode(0,head);
      ListNode* fast = dummy;
      ListNode* slow = dummy;

      for(int i = 0; i <= n; i++)
      {
        fast = fast->next;
      }

      while(fast != nullptr)
      {
        fast = fast->next;
        slow = slow->next;
      }

      slow->next = slow->next->next;

      return dummy->next;
    }
};

int main()
{
  Solution sol;
  ListNode* head = new ListNode(1);
  // head->next = new ListNode(2);
  // head->next->next = new ListNode(3);
  // head->next->next->next = new ListNode(4);
  // head->next->next->next->next = new ListNode(5);
  // head->next->next->next->next->next = new ListNode(6);

  head = sol.removeNthFromEnd(head, 1);

  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }

  return 0;
}