#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    ListNode *curr = head;

    ListNode *dummy = new ListNode(0, head);

    ListNode *prevLLtail = dummy;
    // ListNode *currLLhead = nullptr;
    ListNode *currLLtail = nullptr;

    while (curr != nullptr)
    {
      int cnt = 0;
      ListNode *prev = nullptr;

      ListNode *end = curr;
      currLLtail = curr;

      while (cnt < k && end != nullptr)
      {
        end = end->next;
        cnt++;
      }

      if (cnt < k)
      {
        prevLLtail->next = curr;
        return dummy->next;
      }

      while (curr != end)
      {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }

      // currLLhead = prev;
      prevLLtail->next = prev;
      prevLLtail = currLLtail;
    }

    return dummy->next;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  Solution sol;
  ListNode *newHead = sol.reverseKGroup(head, 2);

  while (newHead != nullptr)
  {
    cout << newHead->val << " ";
    newHead = newHead->next;
  }

  return 0;
}