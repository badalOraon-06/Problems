#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    void generate(int n,vector<string>& ans)
    {
      if(n == 0)
      {
        return ;
      }

      if(n == 1)
      {
        ans.push_back("0");
        ans.push_back("1");
        return;
      }

      generate(n - 1, ans);

      vector<string> temp;
      for(string s : ans)
      {
        temp.push_back(s + '0');

        if(s.back() != '1')
        {
          temp.push_back(s + '1');
        }
      }
      ans = temp;
      return;
    }


    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;

        generate(n, ans);

        return ans;
    }
};



int main()
{
  Solution s;
  vector<string> ans = s.generateBinaryStrings(3);

  for(string str : ans)
  {
    cout << str << endl;
  }

  return 0;
}