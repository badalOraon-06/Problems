#include<iostream>
#include<vector>

using namespace std;


class Solution{
    public:

    bool check(vector<int>& nums, int k, int index, int currSum)
    {
      if(index == nums.size())
      {
        return (currSum == k) ? 1 : 0;
      }

      bool include = check(nums, k, index + 1, currSum + nums[index]);

      bool exclude = check(nums, k, index + 1, currSum);

      return include || exclude;

      return false;
    }


    bool checkSubsequenceSum(vector<int>& nums, int k) {
        
      return check(nums, k, 0,0);
    }
};


int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 5;

    bool result = sol.checkSubsequenceSum(nums, k);
    if(result)
      cout << "There exists a subsequence with sum " << k << endl;
    else
      cout << "No subsequence with sum " << k << " exists" << endl;


  return 0;
}