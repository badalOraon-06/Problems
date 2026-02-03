#include<iostream>
#include<unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        unordered_map <Node*,Node*> map;

        Node* newHead = new Node(head->val);
        map[head] = newHead;

        Node* iterator = head->next;
        Node* previous = newHead;

        while (iterator != nullptr)
        {
          Node* temp = new Node(iterator->val);

          previous->next = temp;
          map[iterator] = temp;

          previous = temp;
          iterator = iterator->next;
        }

        iterator = head;
        Node* newIterator = newHead;

        while(iterator != nullptr)
        {
          newIterator->random = iterator->random ? map[iterator->random] : nullptr;

          iterator = iterator->next;
          newIterator = newIterator->next;
        }

        return newHead;        
    }
};

int main()
{
    Solution s;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next;
    head->next->random = head;

    Node* copiedList = s.copyRandomList(head);

    // Print the original and copied list
    Node* original = head;
    Node* copy = copiedList;
    while (original != nullptr || copy != nullptr) {
        if (original != nullptr) {
            cout << "Original: " << original->val;
            if (original->random != nullptr) {
                cout << ", Random: " << original->random->val;
            }
            cout << endl;
            original = original->next;
        }
        if (copy != nullptr) {
            cout << "Copy: " << copy->val;
            if (copy->random != nullptr) {
                cout << ", Random: " << copy->random->val;
            }
            cout << endl;
            copy = copy->next;
        }
    }

  return 0;
}