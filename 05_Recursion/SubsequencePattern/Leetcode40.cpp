#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     void find(vector<int>& candidates, int target, int index, 
//               vector<vector<int>>& result, vector<int>& current, int currSum) {

//         // Base cases
//         if (currSum == target) {
//             result.push_back(current);
//             return;
//         }

//         if (currSum > target || index >= candidates.size()) return;

//         // INCLUDE current number
//         current.push_back(candidates[index]);
//         find(candidates, target, index + 1, result, current, currSum + candidates[index]);
//         current.pop_back();

//         // EXCLUDE current number → skip all duplicates
//         int nextIndex = index + 1;
//         while (nextIndex < candidates.size() && candidates[nextIndex] == candidates[index])
//             nextIndex++;

//         find(candidates, target, nextIndex, result, current, currSum);
//     }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());

//         vector<vector<int>> result;
//         vector<int> current;

//         find(candidates, target, 0, result, current, 0);

//         return result;
//     }
// };



class Solution {
public:
    void find(vector<int>& candidates, int target, int index, vector<vector<int>>& result, vector<int>& current, int currSum)
    {
      if(currSum == target)
      {
        result.push_back(current);
        return;
      }

      if (currSum > target) return;

      for(int i = index; i < candidates.size(); i++)
      {
        if(i > index && candidates[i] == candidates[i-1]) continue;

        current.push_back(candidates[i]);

        find(candidates, target, i + 1, result, current, currSum + candidates[i]);

        current.pop_back();
      }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int>> result;
      vector<int> current;

      sort(candidates.begin(), candidates.end());

      find(candidates, target, 0, result, current, 0);

      return result;
    }
};


int main()
{
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

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