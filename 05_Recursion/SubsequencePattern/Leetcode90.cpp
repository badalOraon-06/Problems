#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:

  void find(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result)
  {
    if(index == nums.size())
    {
      result.push_back(current);
      return;
    }
    
    current.push_back(nums[index]);
    find(nums, index + 1, current, result);
    current.pop_back();

    int nextIndex = index + 1;

    while(nextIndex < nums.size() && nums[nextIndex] == nums[nextIndex-1])nextIndex++;

    find(nums, nextIndex, current, result);


    return;
    
  }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> current;

        find(nums, 0, current, result);
        return result;
    }
};


int main()
{
    Solution sol;
    vector<int> nums = {1,2,2};

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "The subsets are:" << endl;
    for(auto subset : result)
    {
      cout << "[ ";
      for(int num : subset)
      {
        cout << num << " ";
      }
      cout << "]" << endl;
    }


  return 0;
}