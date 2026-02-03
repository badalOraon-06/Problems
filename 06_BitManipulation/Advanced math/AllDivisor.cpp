#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> divisors(int n) {

      vector<int> result;
      vector<int> result2;

      for(int i = 1; i * i <= n; i++)
      {
        if(n % i == 0)
        {
          result.push_back(i);
          result2.push_back(n / i);
          if(i * i == n) result2.pop_back();
        }
        
      }

      for(int i = result2.size() - 1; i >= 0; i--)
      {
        result.push_back(result2[i]);
      }
      return result;
    }
};


int main()
{
  Solution sol;
  int n = 36;

  vector<int> divisors = sol.divisors(n);
  for (int d : divisors) {
    cout << d << " ";
  }
  cout << endl;

  return 0;
}