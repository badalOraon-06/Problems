#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> result;
      int size=nums.size();
      sort(nums.begin(),nums.end());
      for(int i=0;i<size;i++)
      {
        if(i>0 && nums[i]==nums[i-1]) continue;

        for(int j=i+1;j<size;j++)
        {
          if(j>i+1 && nums[j]==nums[j-1]) continue;
          int k=j+1;
          int l=size-1;
          while(k<l)
          {
            long long sum=nums[i]+nums[j]+nums[k]+nums[l];

            if(sum==target)
            {
              result.push_back({nums[i],nums[j],nums[k],nums[l]});
              k++;
              l--;
              while(k<l && nums[k]==nums[k-1]) k++;
              while(k<l && nums[l]==nums[l+1]) l--;
            }
            else if(sum>target) l--;
            else k++;
          }
        }
      }
      return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = solution.fourSum(nums, target);

    for (const auto& quadruplet : result) {
        cout << "[";
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}