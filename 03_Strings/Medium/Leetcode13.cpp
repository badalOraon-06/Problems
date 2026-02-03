#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
      int size = s.size();

      unordered_map<char,int> roman = {
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
      
      int number = roman[s[size - 1]];
      int previous = number;

      for(int i = size - 2; i >= 0; i--)
      {
        int current = roman[s[i]];
        if(current >= previous) number += current;

        else number -= current;

        previous = current;
      }

      return number;
    }
};

int main()
{
  Solution solution;
  cout << solution.romanToInt("III") << endl;    // Output: 3
  cout << solution.romanToInt("IV") << endl;     // Output: 4
  cout << solution.romanToInt("IX") << endl;     // Output: 9
  cout << solution.romanToInt("LVIII") << endl;  // Output: 58
  cout << solution.romanToInt("MCMXCIV") << endl; // Output: 1994

  return 0;
}