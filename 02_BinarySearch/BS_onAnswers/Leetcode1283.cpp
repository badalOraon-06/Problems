#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath> 
using namespace std;


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
      int low = 1;
      int high = *max_element(nums.begin(),nums.end());
      int ans = -1;

      while(low <= high)
      {
        int mid = (low + high)/2;

        int sum = 0;
        for(int num : nums)
        {
          sum += ceil((double)num/mid);
        }
        if(sum <= threshold)
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
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6; // Example threshold
    int result = sol.smallestDivisor(nums, threshold);
    cout << "Smallest Divisor: " << result << endl; // Expected output: 5
    // You can test with other inputs as well
    vector<int> nums2 = {44, 22, 33, 11, 1};
    int threshold2 = 5; // Example threshold    
    int result2 = sol.smallestDivisor(nums2, threshold2);
    cout << "Smallest Divisor for second case: " << result2 << endl; // Expected output: 44


  return 0;
}