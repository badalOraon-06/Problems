#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
      int lenght = s.size();
      int left = lenght - 1;
      int right = lenght - 1;
      string result = "";
      while(left >= 0)
      {
        if(s[left] == ' ')
        {
          left--;
          continue;
        }
        if(s[right] == ' '){
          right--;
          continue;
        }

        if(left == 0 || s[left - 1] == ' ')
        {
          result += s.substr(left,right - left + 1);
          result += ' ';
          right = left - 1;
        }

        left--;    
      }    
      if(!result.empty())
          result.pop_back();
      return result;
    }
};

int main()
{
  Solution sol;
  string s = "the sky is blue";
  string reversed = sol.reverseWords(s);
  cout << reversed << endl;

  string p = "  hello world  ";
  string reversed1 = sol.reverseWords(p);
  cout << reversed1 << endl;

  string q = "a good   example";
  string reversed2 = sol.reverseWords(q);
  cout << reversed2 << endl;

  return 0;
}