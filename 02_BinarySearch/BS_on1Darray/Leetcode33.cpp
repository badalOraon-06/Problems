#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        
        while(low<=high)
        {
          int mid=(high+low)/2;
          if(nums[mid]==target) return mid;
          else if(nums[low]<=nums[mid])
          {
            if(nums[low]<=target && target<nums[mid]) high=mid-1;
            else low=mid+1;
            
          }
          else{
            if(nums[mid]<target && target<=nums[high]) low=mid+1;
            else high=mid-1;
          }
        }
        return -1;
    }
};

int main()
{
  vector<int> nums={1,3};
  int target=3;
  Solution Obj;
  cout<<Obj.search(nums,target);
}