#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayWithSumK(vector<int>& nums,long long k)
{
  int left=0,right=0;
  long long currentSum=nums[0];
  int maxLength=0;
  int n = nums.size();
  while(right<n)
  {
    while(currentSum>k && left<=right)
    {
      currentSum-=nums[left];
      left++;
    }
    if(currentSum==k)
    {
      maxLength = max(maxLength,right-left+1);
    }


    right++;
    if(right<n) currentSum+=nums[right];
  }
  
  return maxLength;
}

int main()
{
  vector<int> nums = {1,2,3,1,1,1,1,4,2,3};
  long long k = 6;
  int result = longestSubarrayWithSumK(nums, k);
  cout << "Length of the longest subarray with sum " << k << " is: " << result << endl;
  return 0;
}