#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    int arrSize = strs.size();
    string str = strs[0];
    

    while (str.size() > 0)
    {
      bool check = true;
      int len = str.size();
      for (int i = 1; i < arrSize; i++)
      {
        if (strs[i].find(str, 0) != 0)
        {
          check = false;
          break;
        }
      }

      if(check) return str;
      str = str.substr(0,len -1);
    }
    

    return "";
  }
};

int main()
{
  Solution sol;
  vector<string> strs = {"flower", "flow", "flight"};
  cout << sol.longestCommonPrefix(strs) << endl;

  return 0;
}