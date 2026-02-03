#include<iostream>

using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
public:
    ListNode *sortList(ListNode *head) {
      
      ListNode* zero = nullptr;
      ListNode* one = nullptr;
      ListNode* two = nullptr;

      ListNode* zeroHead = nullptr;
      ListNode* oneHead = nullptr;
      ListNode* twoHead = nullptr;

      ListNode* temp = head;

      while (temp != nullptr)
      {
        if(temp->val == 0)
        {
          if(zeroHead == nullptr)
          {
            zero = temp;
            zeroHead = temp;
          }
          else{
            zero->next = temp;
            zero = zero->next;
          }
        }
        else if(temp->val == 1)
        {
          if(oneHead == nullptr) {
            one = temp;
            oneHead = temp;
          }
          else 
          {
            one->next = temp;
            one = one->next;
          }
        }
        else{
          if(twoHead == nullptr) 
          {
            two = temp;
            twoHead = temp;
          }
          else 
          {
            two->next = temp;
            two = two->next;
          }
        }
        temp = temp->next;
      }

      if(two != nullptr) two->next = nullptr;
      if(one != nullptr) one->next = twoHead;
      if(zero != nullptr) zero->next = oneHead ? oneHead : twoHead;
      

    if(zeroHead != nullptr) return zeroHead;
    else if(oneHead != nullptr) return oneHead;
    else return twoHead;
    }
};

int main()
{
  ListNode* head = new ListNode(0);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(0);
  head->next->next->next->next = new ListNode(1);
  head->next->next->next->next->next = new ListNode(2);

  Solution sol;
  ListNode* sortedHead = sol.sortList(head);

  ListNode* curr = sortedHead;
  while (curr != nullptr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }

  return 0;
}