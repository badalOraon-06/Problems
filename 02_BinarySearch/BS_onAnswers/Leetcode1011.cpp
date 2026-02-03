#include <iostream>
#include <vector> 
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;


class Solution {

    
    
public:
    int shipWithinDays(vector<int>& weights, int days) {

      int low = *max_element(weights.begin(),weights.end());
      int high = accumulate(weights.begin() , weights.end() , 0);
      int ans = -1;

      while (low <= high)
      {
        int mid = (low + high)/2;

        int dayCount = 1; //start day
        int sum = 0;
        for( int weight : weights)
        {
          if(sum + weight > mid)
          {
            dayCount++; //start new day
            sum = 0;
          }
          sum += weight;
          
        }

        if(dayCount <= days)
        {
          ans = mid;
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
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5; // Example number of days
    int result = sol.shipWithinDays(weights, days);
    cout << "Minimum capacity to ship within " << days << " days: " << result << endl; // Expected output: 15

    // You can test with other inputs as well
    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3; // Example number of days    
    int result2 = sol.shipWithinDays(weights2, days2);
    cout << "Minimum capacity for second case: " << result2 << endl; // Expected output: 6

  return 0;
}