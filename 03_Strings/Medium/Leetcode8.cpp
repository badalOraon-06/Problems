#include<iostream>
#include<string>
#include<climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();

        long long integer = 0;

        int i = 0;
        while(i < size && s[i] == ' ') i++;

        int sign = 1;

        if(i < size && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++; 
        }


        while(i < size && isdigit(s[i]))
        {
            integer = integer*10 + (s[i] - '0');

            if(sign == 1 && integer > INT_MAX) return INT_MAX;
            if(sign == -1 && -integer < INT_MIN) return INT_MIN;
            i++;
        }

        return sign*integer;
        
    }
};

int main()
{
    Solution sol;
    string s = "42";
    cout << sol.myAtoi(s) << endl; // Output: 42

    s = "   -42";
    cout << sol.myAtoi(s) << endl; // Output: -42

    s = "4193 with words";
    cout << sol.myAtoi(s) << endl; // Output: 4193

    s = "words and 987";
    cout << sol.myAtoi(s) << endl; // Output: 0

    s = "-91283472332";
    cout << sol.myAtoi(s) << endl; // Output: -2147483648 (clamped to INT_MIN)

  return 0;
}




// int size = s.size();

//       int sign = 1;

//       int integer = 0;
      
//       for(int i = 0; i < size; i++)
//       {
//         int ASCII = int(s[i]);

//         if(integer == 0 && s[i] == '-') sign = -1;

//         else if(integer != 0 && s[i] == '-') break;

//         else if(isalpha(s[i])) break;

//         else if(ASCII >= 48 && ASCII <= 57) integer = integer*10 + (s[i] - '0');
        
//       }
//       return sign*integer;