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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0)
          return head;

        int size = 1;

        ListNode* temp = head;

        while(temp->next != nullptr)
        {
          size++;
          temp = temp->next;
        }

        k = k % size;
        if(k == 0) return head;

        ListNode* temp2 = head;

        int endIdx = size - k - 1;
        while(endIdx > 0)
        {
          temp2 = temp2->next;
          endIdx--;
        }

        ListNode* newHead = temp2->next;
        temp2->next = nullptr;
        temp->next = head;

        return newHead;

    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode* ans = s.rotateRight(head, 3);

    while(ans != nullptr)
    {
      cout<<ans->val<<" ";
      ans = ans->next;
    }
  return 0;
}