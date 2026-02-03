#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<long long,int> prefixCount;
      long long currentSum=0;
      int count=0;

      prefixCount[0] = 1; // To handle the case where a subarray starts from index 0

      for(int num : nums)
      {
        currentSum +=num;

        if(prefixCount.find(currentSum - k) != prefixCount.end())
        {
          count += prefixCount[currentSum - k];
        }

        prefixCount[currentSum]++;
      }
      return count;
    }
};

  

int main() {
    Solution solution;

    
    vector<int> nums = {1,0,1,0,1};
    int k = 2;
    int result = solution.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;
    return 0;
}