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

    ListNode* reverseList(ListNode* head) {
      ListNode* prev = nullptr;  
      ListNode* curr = head;
      
      while(curr != nullptr)
      {
        head = curr->next;
        curr->next = prev;
        prev = curr;
        curr = head;        
      }
      return prev;
    }

    bool isPalindrome(ListNode* head) {

      ListNode* slow = head;
      ListNode* fast = head;

      while(fast != nullptr && fast->next != nullptr)
      {
        slow = slow->next;
        fast = fast->next->next;
      }

      if(fast != nullptr) slow = slow->next;

      ListNode* rev= reverseList(slow);
      fast = rev;
      slow = head;

      while(fast != nullptr)
      {
        if(slow ->val != fast -> val) return false;
        slow = slow->next;
        fast = fast->next;
      }
      reverseList(rev);
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