#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {

      int length = num.size();
      int index = length - 1;
      while(index >= 0)
      {
        if(int(num[index]) % 2 == 0) index--;

        else{
          return num.substr(0,index+1);
        }
      }

      return "";
    }
};


int main()
{
  Solution sol;
  string num = "52";
  cout << sol.largestOddNumber(num) << endl;  
  string num1 = "4206";
  cout << sol.largestOddNumber(num1) << endl;
  string num2 = "35427";
  cout << sol.largestOddNumber(num2) << endl;

  return 0;
}