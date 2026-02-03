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
    ListNode* reverseList(ListNode* head) {
      if(head == nullptr || head->next == nullptr) return head;
      

      ListNode* newHead = reverseList(head->next);

      head->next->next = head;
      head->next = nullptr;
      
      return newHead;
    }
};

int main()
{
  Solution sol;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode* reversed = sol.reverseList(head);
  while (reversed != nullptr) {
    cout << reversed->val << " ";
    reversed = reversed->next;
  }
  return 0;
}