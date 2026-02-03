#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int size=nums.size();
      if(size==1) return nums[0];
      
      int low=1;
      int high=size-2;
      if(nums[0]!=nums[1]) return nums[0];
      if(nums[size-1]!=nums[size-2]) return nums[size-1];

      while(low<=high)
      {
        int mid=(low+high)/2;

        if(nums[mid] !=nums[mid-1] && nums[mid] != nums[mid+1])
        {
          return nums[mid];
        }
        if((mid%2==1 && nums[mid] == nums[mid-1]) || (mid%2==0 && nums[mid] == nums[mid+1]))
        {
          low=mid+1;
        }
        else{
          high=mid-1;
        }
      }
      return -1; // This line should never be reached if the input is valid
        
    }
};

int main()
{
  Solution solution;
  vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  int result = solution.singleNonDuplicate(nums);
  cout << "The single non-duplicate element is: " << result << endl;
  
  return 0;
}