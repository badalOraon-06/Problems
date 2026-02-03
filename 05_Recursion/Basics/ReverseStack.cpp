#include <iostream>
#include<stack>

using namespace std;

class Solution {
public:
    void copy(stack<int> &st, stack<int> &temp)
    {
      if(st.empty()) return;

      int top = st.top();
      st.pop();

      copy(st, temp);

      temp.push(top);

      return;
    }

    void reverseStack(stack<int> &st) {
        if(st.empty()) return;

        stack<int> temp;

        copy(st, temp);

        while(!temp.empty())
        {
          st.push(temp.top());
          temp.pop();
        }

        return;
    }
};


int main()
{
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);

  Solution sol;
  sol.reverseStack(st);

  while(!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }

  return 0;
}