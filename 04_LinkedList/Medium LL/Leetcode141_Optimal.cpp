#include<iostream>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
      if(head == nullptr || head->next == nullptr) return false;

      ListNode* slow = head;
      ListNode* fast = head;

      while(fast != nullptr && fast->next != nullptr)
      {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow) return true;

      }

      return false;
    }
};

int main()
{
  Solution sol;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = head->next;  // Create a cycle

  if(sol.hasCycle(head))
    cout << "Cycle detected" << endl;
  else
    cout << "No cycle detected" << endl;

  return 0;
}