#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high)
        {
          if(nums[mid]==2)
          {
            swap(nums[mid],nums[high]);
            high--;
          }
          else if(nums[mid]==0)
          {
            swap(nums[mid],nums[low]);
            low++;
            mid++;
          }
          else{
            mid++;
          }
        }
          
      }
  };

void print(vector<int> nums)
{
  for(int i=0;i<nums.size();i++)
  {
    cout<<nums[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  vector<int> nums={2,0,2,1,1,0};
  print(nums);
  Solution obj;
  obj.sortColors(nums);
  print(nums);

  return 0;
}