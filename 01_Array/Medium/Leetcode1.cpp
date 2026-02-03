#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size=nums.size();

        vector<pair<int,int>> numsWithIndex;
        for(int i=0;i<size;i++)
        {
            numsWithIndex.push_back({nums[i],i});
        }
        sort(numsWithIndex.begin(),numsWithIndex.end());
        int j=size-1;
        int i=0;
        while(i<j)
        {
            int sum=numsWithIndex[i].first+numsWithIndex[j].first;
            if(sum==target)
            {
                return {numsWithIndex[i].second,numsWithIndex[j].second};
            }
            else if(sum>target)
            {
                j--;
            }
            else if(sum<target)
            {
                i++;
            }
        }
        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices of the two numbers that add up to " << target << " are: ";
    for(int index : result)
    {
        cout << index << " ";
    }
    cout << endl;

  return 0;
}