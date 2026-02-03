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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

      ListNode* dummy = new ListNode(0,nullptr);
      ListNode* curr = dummy;
      int carry = 0;

      while(l1 != nullptr || l2 != nullptr || carry)
      {
        int x = (l1 == nullptr) ? 0 : l1->val;
        int y = (l2 == nullptr) ? 0 : l2->val;

        int sum = x + y + carry;
        curr->next = new ListNode(sum % 10);
        carry = sum / 10;

        curr = curr->next;

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
      }

      return dummy->next;
  }
};

int main()
{
  ListNode* head1 = new ListNode(9);
  head1->next = new ListNode(9);
  head1->next->next = new ListNode(9);

  ListNode* head2 = new ListNode(1);
  head2->next = new ListNode(9);
  head2->next->next = new ListNode(9);
  head2->next->next->next = new ListNode(9);

  Solution sol;
  head1 = sol.addTwoNumbers(head1,head2);

  ListNode* temp = head1;
  while(temp != nullptr)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}