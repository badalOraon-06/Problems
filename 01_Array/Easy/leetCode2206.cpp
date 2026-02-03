#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
  public:
  bool divideArray(vector<int>& nums){
    unordered_map<int,int> freq;

    for(int num : nums)
    {
      freq[num]++;
    }

    for(auto& pair : freq)
    {
      if(pair.second % 2 !=0)
      {
        return false;
      }
    }
    return true;
  }
};


//optimized solution
/*

class Solution {
public:
    bool divideArray(vector<int>& nums) {
       sort(nums.begin(), nums.end());  // Step 1: Sort the array
       
       for(int i = 0; i < nums.size(); i += 2) {  // Step 2: Check pairs
           if(nums[i] != nums[i + 1]) {  // Step 3: If a pair is not equal, return false
               return false;
           }
       }
       return true;  // Step 4: If all pairs are equal, return true
    }
};


*/


int main() {
  Solution sol;
  vector<int> nums = {3, 3, 2, 2, 2, 2};

  if (sol.divideArray(nums)) {
      cout << "true" << endl;
  } else {
      cout << "false" << endl;
  }

  return 0;
}