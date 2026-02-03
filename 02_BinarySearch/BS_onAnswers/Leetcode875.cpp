#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

      int low=1;
      int high=*max_element(piles.begin(),piles.end());
      int ans = high ;
      
      while(low <= high)
      {
        int mid = (low+high)/2;
        int sumHours=0;


        for(int pile : piles)
        {
          sumHours += (pile + mid - 1) / mid;
        }

        if(sumHours <= h)
        {
          ans = mid;
          high = mid-1;
        }
        else
        {
          low = mid+1;
        }
      }
      return ans;
    }
};

int main()
{
  Solution sol;
  vector<int> piles = {3, 6, 7, 11};  
  int h = 8;
  int result = sol.minEatingSpeed(piles, h);
  cout << "Minimum eating speed: " << result << endl;
  // Expected output: Minimum eating speed: 4
  piles = {30, 11, 23, 4, 20};
  h = 5;
  result = sol.minEatingSpeed(piles, h);
  cout << "Minimum eating speed: " << result << endl;
  // Expected output: Minimum eating speed: 30


  return 0;
}