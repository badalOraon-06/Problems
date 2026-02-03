#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:

    void find(vector<int>& candidates, int target, int index, vector<vector<int>>& result, vector<int>& current, int currSum)
    {
      if(currSum == target)
      {
        result.push_back(current);
        return;
      }

      if(currSum > target || index == candidates.size()) return;

      find(candidates, target, index + 1, result, current, currSum);

      current.push_back(candidates[index]);

      find(candidates, target, index, result, current, currSum + candidates[index]);

      current.pop_back();
      
      return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
      vector<vector<int>> result;
      vector<int> current;

      find(candidates, target, 0, result, current, 0);

      return result;
    }
};


int main()
{
    Solution sol;
    vector<int> candidates = {2,3,6,7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << " are:" << endl;
    for(const auto& combination : result)
    {
      cout << "{ ";
      for(int num : combination)
      {
        cout << num << " ";
      }
      cout << "}" << endl;
    }



  return 0;
}