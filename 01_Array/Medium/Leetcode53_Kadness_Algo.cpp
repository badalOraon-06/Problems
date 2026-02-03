#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
  public:
    int maxSubArray(vector<int>& nums)
    {
      int n=nums.size();
      int sum=0;
      int max_val=nums[0];

      for(int i=0;i<n;i++)
      {
        sum+=nums[i];
        max_val=max(max_val,sum);
        if(sum<0)
        {
          sum=0;
        }
      }

      return max_val;

    }
};

int main()
{
  Solution Obj;

  vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};

  cout<<Obj.maxSubArray(nums);


  return 0;
}


