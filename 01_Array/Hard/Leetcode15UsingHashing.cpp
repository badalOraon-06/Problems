#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size=nums.size();

        set<vector<int>> st;

        for(int i=0;i<size;i++)
        {
          set<int> hashset;
          for(int j=i+1;j<size;j++)
          {
            int third=-(nums[i]+nums[j]);
            if(hashset.find(third)!=hashset.end())
            {
              vector<int> temp={nums[i],nums[j],third};
              sort(temp.begin(),temp.end());
              st.insert(temp);
            } 
            hashset.insert(nums[j]);
          }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;        
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = solution.threeSum(nums);

    for (const auto& triplet : result) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
