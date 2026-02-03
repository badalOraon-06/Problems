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
        unordered_map<ListNode*, int> map;

        ListNode* temp = head;

        while(temp != nullptr)
        {
          if(map.find(temp) != map.end())
          {
            return temp;
          }
          else map[temp] = 1;

          temp = temp->next;
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