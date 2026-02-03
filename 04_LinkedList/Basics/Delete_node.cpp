#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;

        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main()
{
  ListNode* head = new ListNode(4);
  ListNode* second = new ListNode(5);
  ListNode* third = new ListNode(1);
  ListNode* fourth = new ListNode(9);
  head->next = second;
  second->next = third;
  third->next = fourth;

  Solution sol;
  sol.deleteNode(second);

  ListNode* curr = head;
  while (curr != nullptr) {
    std::cout << curr->val << " ";
    curr = curr->next;
  }

  // Clean up memory
  curr = head;
  while (curr != nullptr) {
    ListNode* next = curr->next;
    delete curr;
    curr = next;
  }

  return 0;
}