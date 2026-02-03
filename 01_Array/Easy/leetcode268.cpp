#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
    int missingNumber(vector<int>& nums) {
      int n=nums.size();
      int value=n*(n+1)/2;
      int sum_value=0;

      for(int i=0;i<n;i++)
      {
        sum_value+=nums[i];        
      }
      return value-sum_value;
    } 
};




int main()
{
  vector<int>nums={3,0,1};
  Solution obj;


  cout<<obj.missingNumber(nums);

  return 0;
}