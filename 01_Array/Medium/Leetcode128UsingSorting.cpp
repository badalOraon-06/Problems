#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if(nums.empty()) return 0;

      sort(nums.begin(),nums.end());
      int longest=1;
      int curr_length=1;
      int last_smallest=nums[0];
      int size=nums.size();

      for(int i=0;i<size;i++)
      {
        if(nums[i]==last_smallest) continue;
        else if(nums[i]-1==last_smallest)
        {
          curr_length++;
          last_smallest=nums[i];
        }
        else if(nums[i]!=last_smallest)
        {
          last_smallest=nums[i];
          curr_length=1;;

        }
        longest=max(longest,curr_length);
      }
      return longest;
        
    }
};

int main()
{
  vector<int> nums={100,4,200,1,3,2};
  Solution Obj;

  int result=Obj.longestConsecutive(nums);
  cout<<"Longest consecutive sequence length: "<<result<<endl;
  return 0;
}