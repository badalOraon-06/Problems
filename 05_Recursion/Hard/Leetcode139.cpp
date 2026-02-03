#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool find(string s, unordered_set<string>& DictSet, int start, int count)
    {
      // this function will recusivly call iteself and check for if the s is a valid string or not
      if(start == s.size())
      {
        return true;
      }
      
      else if(start + count == s.size() && DictSet.find(s.substr(start, count)) == DictSet.end()) return false;

      string curr = s.substr(start, count);

      if(DictSet.find(curr) != DictSet.end())
      {
        return find(s, DictSet, start + count, 1);
      }
      else{
        return find(s, DictSet, start, count+1);
      }

    }


    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> DictSet;

        for(string str : wordDict)
        {
          DictSet.insert(str);
        }

        if(DictSet.find(s) != DictSet.end()) return true;

        return find(s, DictSet, 0, 1);        
      }
};

int main()
{

    Solution sol;
    string s = "applepenapple";
    vector<string> wordDict = {"apple","pen"};

    bool result = sol.wordBreak(s, wordDict);

    cout << (result ? "true" : "false") << endl;


  return 0;
}
