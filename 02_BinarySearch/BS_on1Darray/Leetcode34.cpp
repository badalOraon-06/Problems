#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int first=-1;
        int last=-1;

        while(low<=high)
        {
          int mid=(low+high)/2;
          if(nums[mid]==target)
          {
            first=mid;
            high=mid-1;
          }
          else if(nums[mid]<target)
          {
            low=mid+1;
          }
          else high=mid-1;
        }

        low=0;
        high=nums.size()-1;

        while(low<=high)
        {
          int mid=(low+high)/2;
          if(nums[mid]==target)
          {
            last=mid;
            low=mid+1;
          }
          else if(nums[mid]<target)
          {
            low=mid+1;
          }
          else high=mid-1;
        }

        return {first,last};
    }
};

int main()
{
  vector<int> nums={3,4,13,13,13,20,40};
  int target=13;
  
  Solution Obj;

  vector<int> ans;
  ans=Obj.searchRange(nums,target);

  cout<<ans[0]<<" "<<ans[1];
  return 0;
}