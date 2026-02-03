#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != nullptr)
        {
          lenA++;
          tempA = tempA->next;
        }
        while(tempB != nullptr)
        {
          lenB++;
          tempB = tempB->next;
        }

        int difference = abs(lenA - lenB);

        tempA = headA;
        tempB = headB;

        if(lenA > lenB)
        {
          while(difference > 0)
          {
            tempA = tempA->next;
            difference--;
          }
        }
        else{
          while(difference > 0)
          {
            tempB = tempB->next;
            difference--;
          }
        }

        while(tempA != tempB)
        {
          tempA = tempA->next;
          tempB = tempB->next;
        }

        return tempA;
    }
};

int main()
{
  Solution solution;

  ListNode* headA = new ListNode(1);
  headA->next = new ListNode(2);
  headA->next->next = new ListNode(3);
  headA->next->next->next = new ListNode(4);

  ListNode* headB = new ListNode(5);
  headB->next = new ListNode(6);
  headB->next->next = headA->next->next;  // Intersecting at node with value 3

  ListNode* intersection = solution.getIntersectionNode(headA, headB);
  if (intersection != nullptr) {
    cout << "Intersection at node with value: " << intersection->val << endl;
  } else {
    cout << "No intersection found." << endl;
  }

  // Clean up memory
  delete headA->next->next->next;
  delete headA->next->next;
  delete headA->next;
  delete headA;
  delete headB->next->next;
  delete headB->next;
  delete headB;

  return 0;
}