#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

  void generate(int n, int open, int close, vector<string>& result, string str)
  {
    if(open == close && close == n)
    {
      result.push_back(str);
      return ;
    }

    if(open < n)
    {
      generate(n, open + 1, close, result, str + '(');
    }

    if(open > close)
    {
      generate(n, open, close + 1, result, str + ')');
    }

    return;
  }
  

    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close  = 0;

        vector<string> result;

        generate(n, open, close, result, "");

        return result;
    }
};


int main()
{
  Solution s;
  int n = 3;
  vector<string> result = s.generateParenthesis(n);
  for(const string& str : result)
  {
    cout << str << endl;
  }

  return 0;
}