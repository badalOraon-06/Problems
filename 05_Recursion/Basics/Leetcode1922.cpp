#include<iostream>

using namespace std;

class Solution {
public:
    long long mod = 1e9 + 7;

    long long power(long long base, long long exp)
    {
      if(exp == 0) return 1;
      if(exp == 1) return base % mod;

      long long half = power(base, exp / 2);
      long long result = (half * half) % mod;

      if(exp % 2 == 1) {
        result = (result * base) % mod;
      }

      return result % mod;
    }


    int countGoodNumbers(long long n) {
      
      long long evenCount = (n + 1) / 2;
      long long oddCount = n / 2;

      long long ans = (power(5 , evenCount) * power(4, oddCount)) % mod;

      return (int)ans;
    }
};

int main()
{
    Solution s;
    cout<<s.countGoodNumbers(50)<<endl;
    cout<<s.countGoodNumbers(1)<<endl;
    cout<<s.countGoodNumbers(4)<<endl;


  return 0;
}