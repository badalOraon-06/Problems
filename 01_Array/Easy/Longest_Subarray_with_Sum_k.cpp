#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestSubarrayWithSumK(vector<int>& nums,long long k)
{
  unordered_map<long long,int> prefixSumIndex;
  long long currentSum=0;
  int maxLength=0;

  for(int i=0;i<nums.size();i++)
  {
    currentSum+=nums[i];
    if(currentSum==k)
    {
      maxLength=max(maxLength,i+1);
    }
    
    long long requiredSum=currentSum-k;

    if(prefixSumIndex.find(requiredSum)!=prefixSumIndex.end())
    {
      int len=i-prefixSumIndex[requiredSum];
      maxLength=max(maxLength,len);
    }
    if(prefixSumIndex.find(currentSum)==prefixSumIndex.end())
    {
      prefixSumIndex[currentSum]=i;
    }

  
}
  return maxLength;
}

int main()
{
  vector<int> nums = {9,-3,3,-1,6,-5};
  long long k = 0;
  int result = longestSubarrayWithSumK(nums, k);
  cout << "Length of the longest subarray with sum " << k << " is: " << result << endl;
  return 0;
}