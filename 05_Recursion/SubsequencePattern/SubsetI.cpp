#include<iostream>
#include<vector>

using namespace std;


class Solution {
  public:

  void sums(vector<int>& nums, int index, int currSum, vector<int>& result)
  {
    if(index == nums.size())
    {
      result.push_back(currSum);
      return;
    }


    sums(nums, index + 1, currSum, result);

    sums(nums, index + 1, currSum + nums[index], result);

    return;

  }


    vector<int> subsetSums(vector<int>& nums) {
        vector<int> result;

        sums(nums, 0, 0, result);

        return result;
    }
};


int main()
{
    Solution sol;
    vector<int> nums = {5, 2, 1};

    vector<int> result = sol.subsetSums(nums);

    cout << "Subset sums are:" << endl;
    for(int sum : result)
    {
      cout << sum << " ";
    }
    cout << endl;



  return 0;
}