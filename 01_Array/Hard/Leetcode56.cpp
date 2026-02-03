#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int size = intervals.size();

      sort(intervals.begin(),intervals.end());

      vector<vector<int>> result;
      int first = intervals[0][0];
      int second = intervals[0][1];

      for(int i = 1; i < size; i++)
      {
        if(intervals[i][0] <= second)
        {
          second = max(second, intervals[i][1]);
        }

        else{
          result.push_back({first, second});

          first = intervals[i][0];
          second = intervals[i][1];
        }   
      
      }

      result.push_back({first, second});
      return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> merged = sol.merge(intervals);

    for(const auto& interval : merged) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    intervals = {{1,4},{4,5}};
    merged = sol.merge(intervals);

    for(const auto& interval : merged) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

  return 0;
}