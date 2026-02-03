#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    string infixToPrefix(const string& s) {
        // Your code goes here
        int len = s.size();
        stack<char> st;

        unordered_map<char, int> precedence =
            {
                {'^', 3},
                {'*', 2},
                {'/', 2},
                {'+', 1},
                {'-', 1},
            };

        string postfix = "";

        for(int i = len - 1; i >= 0; i--)
        {
            if(isalpha(s[i]))
            {
                postfix += s[i];                
            }

            else if(s[i] == ')')
            {
                st.push(')');
            }

            else if(s[i] == '(')
            {
                char top = st.top();
                while(top != ')')
                {
                    postfix += top;
                    st.pop();
                    top = st.top();
                }

                st.pop();
            }

            else{
                if(st.empty() || st.top() == ')')
                {
                    st.push(s[i]);
                    continue;
                }

                char top = st.top();

                while(!st.empty() && st.top() != ')' && (precedence[top] > precedence[s[i]] || (precedence[top] == precedence[s[i]] && s[i] != '^')))
                {
                    postfix += top;
                    st.pop();

                    if(!st.empty()) top = st.top();
                }

                st.push(s[i]);
            }
        }

        reverse(postfix.begin(), postfix.end());        

        return postfix;
    }
};

int main()
{
    Solution solution;
    string infix = "(A-B/C)*(A/K-L)";
    string prefix = solution.infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;


  return 0;
}