#include<bits/stdc++.h>
using namespace std;


bool check(vector<int> nums)
{
  int drop=0;
  int n=nums.size();

  for(int i=1;i<n;i++)
  {
    if(nums[i-1]>nums[i])
    {
      drop++;
    }
    if(drop>1)
    {
      return false;
    }
  }

  //make sure that last element is less than or equal to the first element
  if(nums[n-1]>nums[0] && drop==1)
  {
    return false;
  }
  
  return true;

}


int main(){
  vector<int> nums={2,1,3,4};
  cout << (check(nums) ? "true" : "false") << endl;
  
  
  
  return 0;
}