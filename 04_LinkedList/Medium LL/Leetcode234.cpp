#include<iostream>
#include<stack>

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
    stack<int> stackt;
    bool isPalindrome(ListNode* head) {

      ListNode* slow = head;
      ListNode* fast = head;

      while(fast != nullptr && fast->next != nullptr)
      {
        stackt.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
      }

      if(fast != nullptr) slow = slow->next;   
      

      while(slow != nullptr)
      {
        if(slow->val == stackt.top())
        {
          stackt.pop();
          slow = slow->next;
        }
        else return false;
      }
      return true;         
    }
};

int main()
{
  Solution sol;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(1);

  cout << sol.isPalindrome(head) << endl;

  ListNode* head2 = new ListNode(1);
  head2->next = new ListNode(2);
  head2->next->next = new ListNode(3);
  head2->next->next->next = new ListNode(2);
  head2->next->next->next->next = new ListNode(1);

  cout << sol.isPalindrome(head2) << endl;

  return 0;
}