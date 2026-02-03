#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    vector<int> primeFactors(int n){
          int dividend = n;
          int divisor = 2;

          vector<int> result;

          while(dividend % 2 == 0)
          {
            result.push_back(2);
            dividend = dividend / 2;
          }

          for(int i = 3; i * i <= dividend; i += 2)
          {
            while(dividend % i == 0)
            {
              result.push_back(i);
              dividend = dividend / i;
            }
          }
          if(dividend > 1) result.push_back(dividend);

          return result;
    }
};


int main()
{
  Solution sol;
  vector<int> factors = sol.primeFactors(1000);
  for(int factor : factors)
  {
    cout << factor << " ";
  }
  return 0;
}