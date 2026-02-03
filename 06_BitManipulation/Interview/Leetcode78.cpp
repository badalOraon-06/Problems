#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        int subsets = 1 << size;

        for(int i = 0; i < subsets; i++)
        {
          vector<int> set = {};
          for(int j = 0; j < size; j++)
          {
            if(i & (1 << j)) set.push_back(nums[j]);
          }
          result.push_back(set);
        }

        return result;
    }
};

int main()
{
  Solution s;
  vector<int> nums = {1,2,3};
  vector<vector<int>> ans = s.subsets(nums);
  for(auto vec : ans)
  {
    for(auto val : vec)
      cout << val << " ";
    cout << endl;
  }


  return 0;
}