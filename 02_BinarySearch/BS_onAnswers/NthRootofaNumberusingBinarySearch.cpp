#include<iostream>
#include<vector>

using namespace std;

class Solution{
  public:
  int sqrt(int n,int m)
  {
    int low=1,high=n;
    int element=n;
    while(low<=high)
    {
      long long ans=1;
      int mid=(low+high)/2;
      for(int i=1;i<=m;i++)
      {
        ans=ans*mid;
      }

      if(ans == n)
      {
        return mid;
      }
      else if(ans > n) high=mid-1;

      else 
      {
        low=mid+1;
        element=mid;
      }
    }
    return element;
  }

};

int main()
{
    Solution sol;
    int n = 27; // Example input
    int m = 3; // Example root
    int result = sol.sqrt(n, m);
    cout << "The " << m << "th root of " << n << " is approximately: " << result << endl; // Output: 3
    n = 16; // Another example input
    m = 4; // Another example root
    result = sol.sqrt(n, m);
    cout << "The " << m << "th root of " << n << " is approximately: " << result << endl; // Output: 2
  return 0;
}