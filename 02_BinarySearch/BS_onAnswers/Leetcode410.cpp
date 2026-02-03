#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low <= high)
        {
          int mid = (low+high)/2;

          int sum = 0;
          int count = 1;
          for(int num : nums)
          {
            sum += num;
            if(sum > mid)
            {
              sum = num;
              count++;
            }
          }

          if(count > k)
          {
            low = mid + 1;
          }
          else high = mid - 1;
        }

        return low;
    }
};

int main()
{
  Solution sol;
  vector<int> nums = {7,2,5,10,8};
  int k = 2;
  cout << sol.splitArray(nums, k) << endl;

  return 0;
}