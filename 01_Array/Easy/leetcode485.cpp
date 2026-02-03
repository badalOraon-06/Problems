#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int findMaxConsecutiveOnes(vector<int>& nums) {
          int ones=0;
          int max=0;

          for(int i=0;i<nums.size();i++)
          {
            if(nums[i]==1)
            {
              ones++;
            }
            else if(nums[i]==0)
            {
              ones=0;
            }
            if(ones>max){
              max=ones;
            }
            
          }
          return max;
      }
};

int main()
{
  Solution obj;
  vector<int> nums={1,1,0,1,1,1};

  cout<<obj.findMaxConsecutiveOnes(nums);


  return 0;
}