#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      int size = bloomDay.size();

      if((double)size < m*k) return -1;

      int low = *min_element(bloomDay.begin(),bloomDay.end());
      int high =*max_element(bloomDay.begin(),bloomDay.end());

      int ans=-1;

      while(low <= high)
      {
        int mid = (low + high)/2;

        int adjacentFlower=0;
        int bouquets=0;

        for(int day : bloomDay)
        {
          if(day > mid) adjacentFlower=0;

          //  if(day <= mid) 
          else adjacentFlower++;
          if(adjacentFlower == k)
          {
            bouquets++;
            adjacentFlower=0; // Reset after forming a bouquet
          }

          
        }
        if(bouquets >= m)
          {
            ans=mid;
            high = mid-1;
          }
          else low = mid+1;
      }
      return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> bloomDay = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2; // Number of bouquets
    int k = 3; // Number of adjacent flowers in each bouquet
    int result = sol.minDays(bloomDay, m, k);
    cout << "Minimum days to make " << m << " bouquets: " << result << endl; // Expected output: 3

    bloomDay = {1, 10, 3, 10, 2};
    m = 3;
    k = 2;
    result = sol.minDays(bloomDay, m, k);
    cout << "Minimum days to make " << m << " bouquets: " << result << endl; // Expected output: -1 (not enough flowers)



  return 0;
}