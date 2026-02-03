#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    vector<vector<int>> primeFactors(vector<int>& queries){
      vector<vector<int>> result;
      for(int n : queries)
      {
        int dividend = n;
          int divisor = 2;

          vector<int> temp;

          while(dividend % 2 == 0)
          {
            temp.push_back(2);
            dividend = dividend / 2;
          }

          for(int i = 3; i * i <= dividend; i += 2)
          {
            while(dividend % i == 0)
            {
              temp.push_back(i);
              dividend = dividend / i;
            }
          }
          if(dividend > 1) temp.push_back(dividend);

          result.push_back(temp);
      }

      return result;
    }
};


int main()
{
  Solution sol;
  vector<int> queries = {60, 100, 37};
  vector<vector<int>> allFactors = sol.primeFactors(queries);
  for(const auto& factors : allFactors)
  {
    for(int factor : factors)
    {
      cout << factor << " ";
    }
    cout << endl;
  }

  return 0;
}