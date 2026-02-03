#include<iostream>
#include<string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
  public:

  ListNode* reverseList(ListNode* head) {
      ListNode* prev = nullptr;  
      ListNode* curr = head;
      
      while(curr != nullptr)
      {
        head = curr->next;
        curr->next = prev;
        prev = curr;
        curr = head;        
      }
      return prev;
    }


  ListNode* addOne(ListNode* head)
  {
    ListNode* temp = head;

    head = reverseList(temp);
    temp = head;

    int x = temp->val + 1;
    int carry = 0;

    if(x > 9){
      temp->val = 0;
      carry = 1;
    }
    else{
      carry = 0;
      temp->val = x;
    }

    while(carry && temp->next != nullptr)
    {
      temp = temp->next;

      x = temp->val + 1;

      if(x > 9){
      temp->val = 0;
      carry = 1;
      }
      
      else 
      {
        temp->val = x;
        carry = 0;
      }
    }
    if(carry){
       temp->next = new ListNode(1);
    }

    head = reverseList(head);

    return head;
  }

};

int main()
{
  ListNode* head = new ListNode(9);
  head->next = new ListNode(9);
  head->next->next = new ListNode(9);

  Solution sol;
  head = sol.addOne(head);

  ListNode* temp = head;
  while(temp != nullptr)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}