#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int size = s.size();

        int maxDepth = 0;
        int depth = 0;
        for(char c : s)
        {
          if(c == '(') depth++;
          else if(c == ')') depth--;
          else continue;

          maxDepth = max(maxDepth, depth);
        }
      return maxDepth;
    }
};

int main()
{
  Solution sol;
  string s = "(1+(2*3)+((8)/4))+1";
  cout << sol.maxDepth(s) << endl;

  return 0;
}