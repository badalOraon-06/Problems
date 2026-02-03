#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
      void moveZeroes(vector<int>& nums) {
        for(int i=1,j=0;i<nums.size();)
        {
          if(nums[j]==0 && nums[i]!=0)
          {
            int temp=nums[j];
            nums[j]=nums[i];
            nums[i]=temp;
            i++;j++;
          }
          else if(nums[j]==0 && nums[i]==0)
          {
            i++;
          }
          else{
            i++;j++;
          }
        }
          
      }
};


int main()
{
  vector<int>nums={0,1,0,3,12};
  Solution obj;

  for(int i=0;i<nums.size();i++)
  {
    cout<<nums[i]<<" ";
  }
  cout<<endl;

  obj.moveZeroes(nums);

  for(int i=0;i<nums.size();i++)
  {
    cout<<nums[i]<<" ";
  }


  return 0;
}