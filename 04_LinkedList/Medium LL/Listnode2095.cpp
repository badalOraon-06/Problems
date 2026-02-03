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
    ListNode* deleteMiddle(ListNode* head) {
      
      if(head == nullptr || head->next == nullptr)
      {
        return nullptr;
      }
        ListNode* dummy = new ListNode(0,head);
        ListNode* slow = dummy;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
          slow = slow->next;
          fast = fast->next->next;
        }
      
        
        slow->next = slow->next->next;
        return dummy->next;
    }
};

int main()
{

  return 0;
}