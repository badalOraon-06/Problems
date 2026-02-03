#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
  bool palindromeCheck(string str)
  {
    int n = str.size() - 1;
    int i = 0;
    while(i < n)
    {
      if(str[i] != str[n]) return false;
      i++;
      n--;
    }
    return true;
  }

  void find(string s, int index,vector<vector<string>>& result, vector<string>& temp)
  {
    if(index == s.size())
    {
      result.push_back(temp);
      return;
    }

     for(int i = index; i < s.size(); i++)
     {
      string substring = s.substr(index, i - index + 1);
      if(palindromeCheck(substring))
      {
        temp.push_back(substring);
        find(s, i + 1, result, temp);
        temp.pop_back();
      }
      
     }

     return;
  }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        string currStr;

        find(s, 0, result, temp);

        return result;
    }
};


int main()
{
  Solution sol;
  string s = "aba";
  vector<vector<string>> result = sol.partition(s);
  cout << "The palindrome partitions are:" << endl;
  for(const auto& partition : result)
  {
    cout << "{ ";
    for(const auto& str : partition)
    {
      cout << str << " ";
    }
    cout << "}" << endl;
  }


  return 0;
}