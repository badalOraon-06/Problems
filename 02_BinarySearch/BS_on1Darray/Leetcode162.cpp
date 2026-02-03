#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size=nums.size();
        if(size==1) return 0;

        if(nums[0]>nums[1]) return 0;
        if(nums[size-1]>nums[size-2]) return size-1;

        int low=1,high=size-2 ;

        while(low<=high)
        {
          int mid=(low+high)/2;

          if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;

          else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]) low=mid+1;

          else if(nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1]) high= mid-1;

          else low=mid+1;
        }

        return -1;

    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int peakIndex = sol.findPeakElement(nums);
    cout << "Peak element index: " << peakIndex << endl; // Output: 2
    cout << "Peak element value: " << nums[peakIndex] << endl; // Output: 3
  return 0;
}