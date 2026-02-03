#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int size = nums.size();
      
      if(size==1) {
          return nums;
      }

      int requiredCount = size / 3;
      vector<int> result;
      sort(nums.begin(), nums.end());
      int count=0;
      for(int i=0;i<size;i++)
      {
        if(i==0 || nums[i]!= nums[i-1]) {
          count=1;
        } else {
          count++;
        }
        if(count>requiredCount && (result.empty() || result.back() != nums[i]))
        {
          result.push_back(nums[i]);
        }
      }
      return result;
    
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 3, 2, 1, 1, 1, 1, 2, 2};
    vector<int> result = solution.majorityElement(nums);
    
    cout << "Majority elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}