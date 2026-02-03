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
public:
    ListNode* sortList(ListNode* head) {

      vector<int> array;

      ListNode* temp = head;

      while(temp != nullptr)
      {
        array.push_back(temp->val);
        temp = temp->next;
      }
      sort(array.begin(),array.end());

      temp = head;
      for(int num : array)
      {
        temp->val = num;
        temp = temp->next;
      }

      return head;
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