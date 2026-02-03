#include<iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

      if(n == 0) return 1;
      else if(n == 1) return x;
      else if(n == -1) return 1.0 / x;

      long long absN = abs((long long)n);


      double half = myPow(x, absN / 2);
      double ans = half * half;

      if(absN % 2 == 1) ans *= x;

      return (n > 0) ? ans : 1.0 / ans;
    }
};

int main()
{
    Solution s;
    cout<<s.myPow(2,7)<<endl;
    // cout<<s.myPow(2.10000, 3)<<endl;
    // cout<<s.myPow(2.00000, 10)<<endl;


  return 0;
}