#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {


  ListNode* mid(ListNode* head)
  {
    if(head == nullptr) return head;
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != nullptr && fast->next->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  ListNode* merge2sortedLL(ListNode* left, ListNode* right)
  {
    ListNode* dummy = new ListNode(-1);
    ListNode*tail = dummy;

    while(left != nullptr && right != nullptr){

      if(left->val <= right->val)
      {
       tail->next = left;
        left = left->next;
      }
      else{
       tail->next = right;
        right = right->next;
      }
     tail =tail->next;
    }

    if(left != nullptr)tail->next = left;
    else if(right != nullptr)tail->next = right;

    return dummy->next;;
  }

public:
    ListNode* sortList(ListNode* head) {

      if(head == nullptr || head->next == nullptr) return head;

      ListNode* middle = mid(head);

      ListNode* right = middle->next;
      middle->next = nullptr;
      ListNode* left = head;

      left = sortList(left);
      right = sortList(right);

      return merge2sortedLL(left,right);
      
    }
};

int main()
{
  Solution sol;
  ListNode* head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);

  head = sol.sortList(head);

  ListNode* temp = head;
  while(temp != nullptr)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

  return 0;
}