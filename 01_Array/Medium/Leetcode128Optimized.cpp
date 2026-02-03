#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
          
      if(nums.empty()) return 0;
      int longest=1;
      unordered_set<int>  numSet(nums.begin(),nums.end());

      for(auto it : numSet)
      {
        if(numSet.find(it-1) == numSet.end())
        {
          int cnt=1;
          int current=it;
          while(numSet.find(current+1) != numSet.end())
          {
            cnt++;
            current++;
          }
          longest=max (longest,cnt);

        }

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