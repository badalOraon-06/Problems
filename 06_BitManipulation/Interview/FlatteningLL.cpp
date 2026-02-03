#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode *child;
  ListNode()
  {
    val = 0;
    next = NULL;
    child = NULL;
  }
  ListNode(int data1)
  {
    val = data1;
    next = NULL;
    child = NULL;
  }
  ListNode(int data1, ListNode *next1, ListNode *next2)
  {
    val = data1;
    next = next1;
    child = next2;
  }
};

class Solution
{
public:
  ListNode *merge2sortedLL(ListNode *left, ListNode *right)
  {
    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;

    while (left != nullptr && right != nullptr)
    {
      if (left->val <= right->val)
      {
        temp->child = left;
        left = left->child;
      }
      else
      {
        temp->child = right;
        right = right->child;
      }
      temp = temp->child;
    }

    if (left != nullptr)
      temp->child = left;
    else if (right != nullptr)
      temp->child = right;

    return dummy->child;
  }

  ListNode *flattenLinkedList(ListNode *&head)
  {

    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *temp = head;
    ListNode *merged = nullptr;

    while (temp != nullptr)
    {
      head = temp->next;
      temp->next = nullptr;
      merged = merge2sortedLL(temp, merged);

      temp = head;
    }

    return merged;
  }
};

// we can do this just like merge sort to reduce time complexity to O(N log k) where k is number of linked lists

int main()
{
  Solution s;
  ListNode *head = new ListNode(1);
  head->child = new ListNode(2);
  head->child->child = new ListNode(3);
  head->next = new ListNode(4);
  head->next->child = new ListNode(5);
  head->next->child->child = new ListNode(6);

  ListNode *flattened = s.flattenLinkedList(head);
  while (flattened != nullptr)
  {
    cout << flattened->val << " ";
    flattened = flattened->child;
  }

  return 0;
}