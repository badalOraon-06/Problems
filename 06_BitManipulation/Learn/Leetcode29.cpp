#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

// Leetcode Accepted
// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         if(dividend == divisor) return 1;

//         bool sign = true;// +ve
//         if(dividend >= 0 && divisor < 0) sign = false;
//         else if(dividend < 0 && divisor >= 0) sign = false;

//         long long abs_dividend = abs((long long)dividend);
//         long long abs_divisor = abs((long long)divisor);

//         long long quotient = 0;

//         while(abs_dividend >= abs_divisor)
//         {
//           int cnt = 0;
//           // Use long long for shifting and limit cnt to 31
//           while((cnt + 1) < 32 && abs_dividend >= (abs_divisor * (1LL << (cnt + 1))))
//           {
//             cnt++;
//           }
//           long long current_bit = 1LL << cnt;
//           quotient += current_bit;
//           abs_dividend -= (abs_divisor * current_bit);
//         }

//         quotient = (sign) ? quotient : -quotient;

//         if(quotient > INT_MAX) return INT_MAX;
//         else if(quotient < INT_MIN) return INT_MIN;

//         return (int)quotient;
//     }
// };

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool sign = true;// +ve

        if(dividend >= 0 && divisor < 0) sign = false;
        else if(dividend < 0 && divisor >= 0) sign = false;

        long abs_dividend = abs(dividend);
        long abs_divisor = abs(divisor);

        
        long quotient = 0;

        while(abs_dividend >= abs_divisor)
        {
          int cnt = 0;
          
          while(abs_dividend >= (abs_divisor << (cnt + 1)))
          {
            cnt += 1;
            
          }
          
          quotient += 1 << cnt;
          abs_dividend -= (abs_divisor << cnt);
        }

        if(quotient == (1<<31) && sign) return INT_MAX;
        else if(quotient == (1<<31) && !sign) return INT_MIN;

        return sign ? quotient : -quotient;
    }
};

int main()
{
  Solution s;
  
  int dividend = 10;
  int divisor = 3;
  cout<<s.divide(dividend, divisor)<<endl;
  dividend = 7;
  divisor = -3;
  cout<<s.divide(dividend, divisor)<<endl;
  dividend = -2147483648;
  divisor = -1;
  cout<<s.divide(dividend, divisor)<<endl;
  dividend = -2147483648;
  divisor = 1;
  cout<<s.divide(dividend, divisor)<<endl;

  return 0;
}


