// #include <iostream>
// #include <vector>

// using namespace std;

// class Stack
// {
//   vector<int> stack;

// public:
//   void push(int data)
//   {
//     stack.push_back(data);
//   }

//   void pop()
//   {
//     if (stack.empty())
//     {
//       cout << "Stack is Empty" << endl;
//       return;
//     }
//     stack.pop_back();
//   }

//   int top()
//   {
//     if (stack.empty())
//     {
//       cout << "Stack is Empty" << endl;
//       return -1;
//     }
//     return stack.back();
//   }

//   int size()
//   {
//     return stack.size();
//   }

//   bool isEmpty()
//   {
//     return stack.empty();
//   }
// };

// int main()
// {
//   return 0;
// }





#include<iostream>

using namespace std;


class ArrayStack {
  int size;
  int Top;
  int *array;
public:
    ArrayStack() {
      this->size = 100;
      array = new int[size];
      Top = -1;
    }
    
    void push(int x) {
      if(Top + 1 == size) return;
      array[++Top] = x;   
    }
    
    int pop() {
      if(Top < 0) return -1;
      int x = array[Top];
      Top--;
      return x;  
    }
    
    int top() {
    return array[Top];
    }
    
    bool isEmpty() {
      if(Top < 0) return true;
      return false;
    }
};


int main()
{



  return 0;
}