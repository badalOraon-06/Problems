#include<iostream>
#include<vector>  
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {

      stack<char> st;
      int size = num.size();
      
      int toRemove = k; 

      if(k > size)
      {
        return "0";
      }

      int i = 0; 

      while(i < size)
      {
        char curr = num[i];

        while(!st.empty() && st.top() > curr && toRemove > 0)
        {
          st.pop();
          toRemove--;
        }

        st.push(curr);
        i++;
      }

      string result = "";


      while(toRemove > 0)
      {
        st.pop();
        toRemove--;
      }

      while(!st.empty())
      {
        result += st.top();
        st.pop();
      }

      reverse(result.begin(), result.end());

      int cnt = 0;

      for(char c : result)
      {
        if(c != '0') break;
        cnt++;
      }

      result = result.substr(cnt);

      if(result == "") return "0";

      return result;

    }
};


int main()
{
  Solution s;
  string num = "1432219";
  int k = 3;

  cout << s.removeKdigits(num, k) << endl;

  return 0;
}