#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  string prefixToInfix(string s)
  {
    stack<string> st;
    int len = s.size();

    for (int i = len - 1; i >= 0; i--)
    {
      string temp = "";
      temp += s[i];

      if (isalpha(s[i]))
      {
        st.push(temp);
      }

      else
      {
        string op1 = st.top();
        st.pop();
        string op2 = st.top();
        st.pop();

        string sol = '(' + op1 + s[i] + op2 + ')';

        st.push(sol);
      }
    }

    return st.top();
  }
};

int main()
{
    Solution solution;
    string prefix = "+-*AB/CDE";
    string infix = solution.prefixToInfix(prefix);
    cout << "Infix Expression: " << infix << endl;

  return 0;
}