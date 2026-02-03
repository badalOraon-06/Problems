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
    ListNode* oddEvenList(ListNode* head) {
      if(head == nullptr || head->next == nullptr) 
            return head;

        ListNode* oddEnd = head;

        ListNode* evenHead = head->next;
        ListNode* evenEnd = head->next;

        while(evenEnd != nullptr && evenEnd->next != nullptr)
        {
          oddEnd->next = evenEnd->next;
          oddEnd = oddEnd->next;

          evenEnd->next = evenEnd->next->next;
          evenEnd = evenEnd->next;
          
          
        }

        oddEnd->next = evenHead;
        return head;
    }
};


int main()
{
  Solution sol;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  // head->next->next->next->next = new ListNode(5);
  // head->next->next->next->next->next = new ListNode(6);
  // head->next->next->next->next->next->next = new ListNode(7);

  ListNode* result = sol.oddEvenList(head);
  while (result != nullptr) {
      cout << result->val << " ";
      result = result->next;
  }

  return 0;
}