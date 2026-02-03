#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
  public:
      int majorityElement(vector<int>& nums) {
      int count=0;
      int element;
      for(int i=0;i<nums.size();i++)
      {
        if(count==0)
        {
          element=nums[i];
          count=1;
        }
        else if(element==nums[i])
        {
          count++;
        }
        else{
          count--;
        }
      }
      return element;
      }
      
  };

  int main()
  {
    vector<int> nums={4,4,2,2,2,4,4,1};
    Solution obj;
    cout<<obj.majorityElement(nums);


    return 0;
  }