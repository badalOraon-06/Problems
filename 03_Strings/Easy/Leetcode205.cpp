#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char,char> check1;
      unordered_map<char,char> check2;

      for(int i = 0; i < s.size(); i++)
      {
        char c1 = s[i], c2 = t[i];
        if(check1.find(c1) != check1.end())
        {
          if(check1[c1] != c2) return false;
        }
        if(check2.find(c2) != check2.end())
        {
          if(check2[c2] != c1) return false;
        }

        
        check1[c1] = c2;
        check2[c2] = c1;
        
      }
        
      return true;
    }
};

int main()
{
  Solution sol;
  cout << sol.isIsomorphic("egg", "add") << endl;  // Output: 1 (true)
  cout << sol.isIsomorphic("foo", "bar") << endl;  // Output: 0 (false)
  cout << sol.isIsomorphic("badc", "baba") << endl;  // Output: 1 (true)

  return 0;
}
