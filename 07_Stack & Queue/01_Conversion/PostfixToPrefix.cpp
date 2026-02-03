#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    string postToPre(string postfix) {
        // Your code goes here
        stack<string> st;

        int len = postfix.size();

        for(int i = 0; i < len; i++)
        {
          string temp = "";
          temp += postfix[i];

          if(isalpha(postfix[i]))
          {
            st.push(temp);
          }

          else{
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            st.push(postfix[i] + op2+ op1);
          }
        }

        return st.top();
    }

};

int main()
{
    Solution solution;
    string postfix = "AB*C/DE-+";
    string prefix = solution.postToPre(postfix);
    cout << "Prefix Expression: " << prefix << endl;

  return 0;
}