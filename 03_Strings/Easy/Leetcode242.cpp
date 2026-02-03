#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size() != t.size()) return false;

      unordered_map<char,int> count;

      for(int i=0 ; i < s.size() ; i++)
      {
        if(count.find(s[i]) == count.end()) count.insert({s[i],1});   
        else count[s[i]]++;

        if(count.find(t[i]) == count.end()) count.insert({t[i],-1});   
        else count[t[i]]--;
      }

      for(auto i : count) if(i.second != 0) return false;

      return true;
    }
};

int main()
{
  Solution sol;

  string s = "anagram";
  string t = "nagaram";

  if(sol.isAnagram(s, t)) {
      cout << "The strings are anagrams." << endl;
  } else {
      cout << "The strings are not anagrams." << endl;
  }

  return 0;
}