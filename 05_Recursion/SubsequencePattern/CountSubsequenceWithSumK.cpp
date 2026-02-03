#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:    	
    int countN(vector<int>& nums, int k, int index, int currSum)
    {
        // base case
        if(index == nums.size())
        {
            return (currSum == k) ? 1 : 0;
        }

        // include current element
        int include = countN(nums, k, index + 1, currSum + nums[index]);

        // exclude current element
        int exclude = countN(nums, k, index + 1, currSum);

        return include + exclude;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k)
    {
        return countN(nums, k, 0, 0);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1};
    int k = 2;

    int result = sol.countSubsequenceWithTargetSum(nums, k);
    cout << "Count of Subsequences with sum " << k << " is: " << result << endl;

    return 0;
}
