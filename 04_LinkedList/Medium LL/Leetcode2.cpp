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
      
      ListNode* temp1 = l1;
      ListNode* temp2 = l2;

      int x = temp1->val;
      int y = temp2->val;

      x = x + y;
      int carry = 0;
      
      if(x > 9) 
      {
        carry = 1;
        temp1->val = x % 10;
      }
      else 
      {
        carry = 0;
        temp1->val = x;
      }

      while(carry && (temp1->next != nullptr && temp2->next != nullptr))
      {
        temp1 = temp1->next;
        temp2 = temp2->next;

        x = temp1->val;
        y = temp2->val;

        x = x + y + 1;
      
        if(x > 9) 
        {
          carry = 1;
          temp1->val = x % 10;
        }
        else 
        {
          carry = 0;
          temp1->val = x;
        }
      }
      
      while(carry && temp1->next != nullptr)
      {
        temp1 = temp1->next;

        x = temp1->val;

        x = x + 1;

        if(x > 9) 
        {
          carry = 1;
          temp1->val = 0;
        }
        else 
        {
          carry = 0;
          temp1->val = x;
        }
      }

      while(carry && temp2->next != nullptr)
      {
        temp2 = temp2->next;

        y = temp2->val;

        y = y + 1;
      
        if(y > 9) 
        {
          carry = 1;
          temp1->next = new ListNode(0);
        }
        else 
        {
          carry = 0;
          temp1->next = new ListNode(x);
        }
        temp1 = temp1->next;
      }

      if(carry) temp1->next = new ListNode(1);
    

    return l1;
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