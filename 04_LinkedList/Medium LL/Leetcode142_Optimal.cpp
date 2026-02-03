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
    ListNode *detectCycle(ListNode *head) {

      if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
          slow = slow->next;
          fast = fast->next->next;

          if(slow == fast){
            fast = head;

            while(slow != fast)
            {
              slow = slow->next;
              fast = fast->next;
            }
            return slow;
          }
        }

        return nullptr;
    }
};

int main()
{
  Solution sol;
  ListNode* head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next; // Create a cycle

  ListNode* cycleNode = sol.detectCycle(head);
  if (cycleNode) {
    cout << "Cycle detected at node with value: " << cycleNode->val << endl;
  } else {
    cout << "No cycle detected." << endl;
  }

  return 0;
}