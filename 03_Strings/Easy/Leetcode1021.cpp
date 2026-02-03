#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
      string result;
      int depth = 0;

      for(int c : s)
      {
        if(c == '('){
          if(depth > 0) result += c;
          depth++;
        }

        else{
          depth--;
          if(depth > 0) result +=c;
        }
      }

      return result;

    }
};

int main()
{
  Solution sol;
  string s = "(()())(())(()(()))";
  cout << sol.removeOuterParentheses(s) << endl;

  return 0;
}