#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
      int l = 0, r = 0;
      int size = s.size();

      vector<int> freq(3, 0);
      int count = 0;

      while(r < size)
      {
        if(s[r] == 'a') freq[0]++;
        else if(s[r] == 'b') freq[1]++;
        else freq[2]++;

        while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
        {
          count += (size - r);
          if(s[l] == 'a') freq[0]--;
          else if(s[l] == 'b') freq[1]--;
          else freq[2]--;
          l++;
        }

        r++;
      }
      
      return count;
    }
};

int main()
{
  Solution s;
  string str = "abcabc";
  cout << s.numberOfSubstrings(str) << endl;


  return 0;
}