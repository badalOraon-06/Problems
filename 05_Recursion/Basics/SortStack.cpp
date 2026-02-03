#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    void arrange(stack<int> &st, int data)
    {
      if(st.empty() || st.top() < data)
      {
        st.push(data);
        return;
      }
      
      int currTop = st.top();
      st.pop();
      arrange(st, data);
      st.push(currTop);
      return;
    }

    void sortStack(stack<int> &st) {
      if(st.empty()) return;

      int data = st.top();
      st.pop();

      sortStack(st);

      arrange(st, data);
    }
};

int main()
{
  stack<int> st;
  st.push(3);
  st.push(1);
  st.push(4);
  st.push(2);

  Solution sol;
  sol.sortStack(st);

  while(!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}