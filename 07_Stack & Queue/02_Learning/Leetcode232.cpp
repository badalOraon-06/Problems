#include <iostream>
#include <stack>

using namespace std;

class StackQueue
{
  stack<int> stack1;
  stack<int> stack2;

public:
  StackQueue()
  {
  }

  void push(int x)
  {

    while (!stack1.empty())
    {
      stack2.push(stack1.top());
      stack1.pop();
    }

    stack1.push(x);

    while (!stack2.empty())
    {
      stack1.push(stack2.top());
      stack2.pop();
    }

    return;
  }

  int pop()
  {
    if (stack1.empty())
      return -1;
    int x = stack1.top();

    stack1.pop();
    return x;
  }

  int peek()
  {
    if (stack1.empty())
      return -1;
    return stack1.top();
  }

  bool isEmpty()
  {
    return stack1.empty();
  }
};

int main()
{

  return 0;
}