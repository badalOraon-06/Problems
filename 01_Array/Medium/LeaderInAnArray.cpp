#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
  void Leader(vector<int> nums)
  {
    int size=nums.size();
    int leader=nums[size-1];
    cout<<leader<<" ";
    
    for(int i=size-2;i>=0;i--)
    {
      if(nums[i]>leader)
      {
        leader=nums[i];
        cout<<leader<<" ";
      }
    }

  }

};
int main()
{
  
  vector<int> nums={10,22,12,3,0,6};
  Solution Obj;

  Obj.Leader(nums);
  return 0;
}