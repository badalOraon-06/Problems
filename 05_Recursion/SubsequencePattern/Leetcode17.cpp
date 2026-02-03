#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    void find(string digits, int index, string current, vector<string>& result, unordered_map<char, string>& dict)
    {
      if(index == digits.size())
      {
        result.push_back(current);
        return;
      }

      string currStr = dict[digits[index]];
      int n = dict[digits[index]].size();

      for(int i = 0; i < n; i++)
      {
        current = current + currStr[i];
        find(digits, index + 1, current, result,dict);
        current.pop_back();
      }
      
      return;
    }

    vector<string> letterCombinations(string digits) {
      unordered_map<char,string> dict = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
      };

      vector<string> result;
      string current = "";

      find(digits, 0, current, result,dict);

      return result; 
    }
};


int main()
{
    Solution sol;
    string digits = "23";

    vector<string> result = sol.letterCombinations(digits);

    cout << "The combinations are:" << endl;
    for(string combination : result)
    {
      cout << combination << endl;
    }


  return 0;
}