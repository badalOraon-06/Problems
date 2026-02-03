#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int size=nums.size();
      int breakPoint=-1;
      for(int i=size-2;i>=0;i--)
      {
        if(nums[i]<nums[i+1])
        {
          breakPoint=i;
          break;
        }
      }

      if(breakPoint==-1)
      {
        reverse(nums.begin(),nums.end());
        return;
      }
      
      for(int i=size-1;i>breakPoint;i--)
      {
        if(nums[i]>nums[breakPoint])
        {
          swap(nums[i],nums[breakPoint]);
          break;
        }
      }
      reverse(nums.begin()+breakPoint+1,nums.end());
        
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution obj;
    obj.nextPermutation(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}