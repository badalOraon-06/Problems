#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  void find(int k, int n,int currInt, int currentSum, vector<int>& current, vector<vector<int>>& result)
  {
    if(currentSum == n && current.size() == k)
    {
      result.push_back(current);
      return;
    }

    if(currInt > 9) return;

    current.push_back(currInt);
    find(k, n, currInt + 1,currentSum + currInt, current, result);
    current.pop_back();

    find(k, n, currInt + 1,currentSum, current, result);

    return;
  }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        vector<vector<int>> result;

        find(k, n, 1, 0, current, result);

        return result;
    }
};


int main()
{
    Solution sol;
    int k = 3;
    int n = 7;

    vector<vector<int>> result = sol.combinationSum3(k, n);

    cout << "The combinations are:" << endl;
    for(auto combination : result)
    {
      cout << "[ ";
      for(int num : combination)
      {
        cout << num << " ";
      }
      cout << "]" << endl;
    }


  return 0;
}