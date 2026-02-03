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
  
  ListNode* addOne(ListNode* head)
  {
    ListNode* temp = head;
    long long x = 0;
    int len = 0;

    while(temp != nullptr){
      x = (x * 10) + temp->val;
      temp = temp->next;
      len++;
    }

    string newNumber = to_string(x + 1);

    int newLen = newNumber.size();

    if(newLen > len){
      ListNode* add = new ListNode(-1,head);
      head = add;
    }

    temp = head;

    for(char str : newNumber)
    {
      temp->val = (int)(str - '0');
      temp = temp->next;
    }

    return head;
  }

};

int main()
{
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);

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