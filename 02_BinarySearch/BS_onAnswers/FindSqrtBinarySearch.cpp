#include<iostream>
#include<vector>

using namespace std;

class Solution{
  public:
  int sqrt(int n)
  {
    int low=1,high=n;
    int ans=n;
    while(low<=high)
    {
      int mid=(low+high)/2;

      if(mid*mid == n)
      {
        return mid;
      }
      else if(mid*mid > n) high=mid-1;

      else 
      {
        low=mid+1;
        ans=mid;
      }
    }
    return ans;
  }

};

int main()
{
    Solution sol;
    int n = 16; // Example input
    int result = sol.sqrt(n);
    cout << "The square root of " << n << " is approximately: " << result << endl; // Output: 4
    n = 20; // Another example input
    result = sol.sqrt(n);
    cout << "The square root of " << n << " is approximately: " << result << endl; // Output: 5
  return 0;
}
