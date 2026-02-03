#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    string postToInfix(string postExp) {
        // Your code goes here

        stack<string> st;

        for(char ch : postExp)
        {
            string temp = "";
            temp += ch;

            if(isalpha(ch))
            {
                st.push(temp);
            }

            else{
                string op1 = st.top();
                st.pop();

                string op2 = st.top();
                st.pop();

                st.push("(" + op2 + ch + op1 + ")");
            }
        }

        return st.top();
    }
};


int main()
{

    Solution solution;
    string postfix = "AB*C/DE-+";
    string infix = solution.postToInfix(postfix);
    cout << "Infix Expression: " << infix << endl;

  return 0;
}