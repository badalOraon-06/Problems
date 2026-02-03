#include<iostream>
#include<stack>
#include<string>

using namespace std;


class Solution {
public:
    string prefixToPostfix(const string& s) {
        // Your code goes here
        stack<string> st;

        int len = s.size();

        for(int i = len - 1; i >= 0; i--)
        {
          string temp = "";
          temp += s[i];

          if(isalpha(s[i]))
          {
            st.push(temp);
          }
          else{
            string op1 = st.top();
            st.pop();
            
            string op2 = st.top();
            st.pop();

            st.push(op1 + op2 + s[i]);
          }

        }

        return st.top();
    }
};


int main()
{
    Solution solution;
    string prefix = "+-*AB/CDE";
    string postfix = solution.prefixToPostfix(prefix);
    cout << "Postfix Expression: " << postfix << endl;


  return 0;
}