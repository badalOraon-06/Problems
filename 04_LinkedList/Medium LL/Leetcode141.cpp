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
      unordered_map<ListNode*,int> mt;
      ListNode* temp = head;
      while(temp != nullptr)
      {
        if(mt.find(temp) != mt.end()) return true;
        
        mt.insert({temp,1});
        temp = temp->next;
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