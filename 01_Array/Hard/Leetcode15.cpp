#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<size;i++)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            
            int j=i+1;
            int k=size-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
            
                if(sum==0)
                {
                    result.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return result;

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