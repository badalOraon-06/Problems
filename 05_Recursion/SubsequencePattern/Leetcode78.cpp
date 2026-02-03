#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  
  void subsetTemp(vector<int>& nums, int index, vector<int> subset, vector<vector<int>>& result)
  {
    if(nums.size() == index)
    {
      result.push_back(subset);
      return;
    }

    subsetTemp(nums, index + 1, subset, result);

    subset.push_back(nums[index]);

    subsetTemp(nums, index + 1, subset, result);

    return;
  }

    vector<vector<int>> subsets(vector<int>& nums) {


      vector<vector<int>> result;

      subsetTemp(nums, 0, {}, result);

      return result;

    }
};


int main()
{
  Solution s;
  vector<int> nums = {1,2,3};
  vector<vector<int>> result = s.subsets(nums);
  for (const auto& subset : result) {
    cout << "{ ";
    for (int num : subset) {
      cout << num << " ";
    }
    cout << "}" << endl;
  }
  return 0;
}