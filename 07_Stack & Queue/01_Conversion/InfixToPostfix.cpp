#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string infixToPostfix(string s)
    {
        // Your code goes here
        stack<char> st;

        // mapping the preference for the operators
        unordered_map<char, int> precedence =
            {
                {'^', 3},
                {'*', 2},
                {'/', 2},
                {'+', 1},
                {'-', 1},
            };
            
        // storing the postfix expression    
        string postfix = "";
        
        // traversing through the each charater of the string
        for (char str : s)
        {
            // checking for the charater is an alphabet
            if (isalpha(str))
            {
                postfix += str;
            }

            // checking for the charater is a opening bracket 
            else if (str == '(')
            {
                st.push(str);
            }
            
            // checking for the charater is a closing bracket
            else if (str == ')')
            {
                // in the condition we are pushing the elements present in the stack into the postfix variable until the opening bracket
                int top = st.top();
                while (top != '(')
                {
                    postfix += top;
                    st.pop();
                    top = st.top();
                }
                st.pop();
            }

            // this condition works when we find an operator
            else
            {
                // if stack is empty or contains opening bracket at top then we directly push the operator into the stack and continue the loop
                if (st.empty() || st.top() == '(')
                {
                    st.push(str);
                    continue;
                }


                int top = st.top();

                // if the precedence of the topmost element in the stack has higher or equal (exception: equal condition for '^' operator )precedenc than the current operator of the infix expression then we push the top of the stack into the postfix string and push the curr operator in the stack
                while (!st.empty() && top != '(' && (precedence[top] > precedence[str] || (precedence[top] == precedence[str] && str != '^')))
                {
                    postfix += st.top();
                    st.pop();
                    if (!st.empty())
                        top = st.top();
                }
                st.push(str);
            }
        }

        // if stack is not empty after the loop is over then push all the elements present in the stack to the postfix string one by one
        while (!st.empty())
        {
            int top = st.top();
            postfix += top;
            st.pop();
        }

        return postfix;
    }
};

int main()
{
    Solution solution;
    string infix = "A+(B*C-(D/E^F)*G)*H";
    string postfix = solution.infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;


    return 0;
}