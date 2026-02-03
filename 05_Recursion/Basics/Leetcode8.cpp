#include <iostream>
#include <climits>

using namespace std;

class Solution
{
public:
  long long helper(string str, int currIdx, long long result)
  {
    if (currIdx == str.length())
      return result;

    if (!isdigit(str[currIdx]))
      return result;

    result = (result * 10) + (str[currIdx] - '0');
    return helper(str, currIdx + 1, result);
  }

  int myAtoi(string s)
  {
    if (s.length() == 0)
      return 0;

    int currIdx = 0;
    int sign = 1;

    // Skip leading whitespace
    while (currIdx < s.length() && s[currIdx] == ' ')
      currIdx++;

    // Handle sign
    if (currIdx < s.length() && (s[currIdx] == '-' || s[currIdx] == '+'))
    {
      sign = (s[currIdx] == '-') ? -1 : 1;
      currIdx++;
    }

    long long result = 0;
    long long digit = helper(s, currIdx, result);

    if(digit > INT_MAX && sign == 1) return INT_MAX;

    else if(digit > (long long)INT_MAX + 1 && sign == -1) return INT_MIN;

    return (int)digit * sign;
  }
};




// class Solution
// {
// public:
//   string helper(string str, int currIdx, string result)
//   {
//     if (currIdx == str.length())
//       return result;

//     if (!isdigit(str[currIdx]))
//       return result;

//     result = result + str[currIdx];
//     return helper(str, currIdx + 1, result);
//   }

//   int myAtoi(string s)
//   {
//     if (s.length() == 0)
//       return 0;

//     int currIdx = 0;
//     int sign = 1;

//     // Skip leading whitespace
//     while (currIdx < s.length() && s[currIdx] == ' ')
//       currIdx++;

//     // Handle sign
//     if (currIdx < s.length() && (s[currIdx] == '-' || s[currIdx] == '+'))
//     {
//       sign = (s[currIdx] == '-') ? -1 : 1;
//       currIdx++;
//     }

//     string result = "";
//     string digitStr = helper(s, currIdx, result);

//     if (digitStr.empty())
//       return 0;

//     long long ans = 0;
//     for (int i = 0; i < digitStr.size(); i++)
//     {
//       ans = (ans * 10) + (digitStr[i] - '0');

//       // Check for overflow
//       if (sign == 1 && ans > INT_MAX)
//         return INT_MAX;
//       if (sign == -1 && ans > (long long)INT_MAX + 1)
//         return INT_MIN;
//     }

//     return (int)(ans * sign);
//   }
// };

int main()
{
  Solution s;
  string str = "   -42";
  cout << s.myAtoi(str)<<endl;

  string str2 = "4193 with words";
  cout << s.myAtoi(str2)<<endl;
  return 0;
}