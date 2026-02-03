#include<iostream>
#include<vector>

using namespace std;


class Solution {
  public:
  int maxSubArray(vector<int>& nums) {
    int res = nums[0];       
    int maxEnding = nums[0]; 

    for (int i=1;i<nums.size();i++) {

        maxEnding = max(nums[i], maxEnding + nums[i]);

        res = max(res, maxEnding);
    }
    return res;
}
  };



  int main() {
    Solution obj;
    vector<int> arr = {2};
    cout << obj.maxSubArray(arr);
    return 0;
}
