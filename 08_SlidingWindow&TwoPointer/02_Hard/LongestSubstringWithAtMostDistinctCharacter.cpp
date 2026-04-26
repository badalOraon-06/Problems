#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int kDistinctChar(string& s, int k) {
      int l = 0, r = 0;
      int size = s.size();

      unordered_map<char, int> map;

      int maxSize = 0;

      while(r < size)
      {
        map[s[r]]++;

        while(map.size() > k)
        {
          map[s[l]]--;
          if(map[s[l]] == 0)
            map.erase(s[l]);
          l++;
        }

        maxSize = max(maxSize, r - l + 1);
        r++;
      }

      return maxSize;
    }
};


int main()
{
  Solution s;
  string str = "aababbcaacc";
  int k = 2;
  cout << s.kDistinctChar(str, k) << endl;


  return 0;
}