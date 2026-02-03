#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int upperBound(vector<int>& nums, int target) {
      int size=nums.size();
      int low=0;
      int high=size-1;
      int minInx=-1;
      while(low<=high)
      {
        int mid=(low+high)/2;
        if(nums[mid]>target)
        {
          minInx=mid;
          high=mid-1;
        }
        else //(nums[mid]<target)
        {
          low=mid+1;
        }

      }
      return minInx;
        
    }
};

int main()
{
  vector<int> nums={-1,0,3,5,9,12};
  int target=9;
  Solution Obj;
  cout<<Obj.upperBound(nums,target);
}