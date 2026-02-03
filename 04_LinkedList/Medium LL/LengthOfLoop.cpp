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
    int detectCycle(ListNode *head) {

      if(head == nullptr || head->next == nullptr) return -1;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
          slow = slow->next;
          fast = fast->next->next;

          if(slow == fast){
            fast = head;
            int length = 0;

            while(slow != fast)
            {
              fast = fast->next;
              length++;
            }
            return length;
          }
        }

        return 0;
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

  int cycleLength = sol.detectCycle(head);
  if (cycleLength != -1) {
    cout << "Cycle detected with length: " << cycleLength << endl;
  } else {
    cout << "No cycle detected." << endl;
  }

  return 0;
  
}