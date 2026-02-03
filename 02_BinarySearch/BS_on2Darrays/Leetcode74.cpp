#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int rows = matrix.size();
      int column = matrix[0].size();

      int low = 0;
      int high = rows - 1;

      while(low <= high)
      {
        int mid = (low + high)/2;
        if(matrix[mid][0] > target) high = mid - 1;
        else low = mid + 1;
      }
      if(high < 0 || high >= rows) return false;
      
      int row = high;
      low = 0;
      high = column - 1;

      while(low <= high)
      {
        int mid = (low + high)/2;
        if(matrix[row][mid] == target) return true;
        else if(matrix[row][mid] > target) high = mid - 1;
        else low = mid + 1;
      }
      
      return false;
    }
};

int main()
{

  Solution sol;
  vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 3;
  bool found = sol.searchMatrix(matrix, target);
  cout << (found ? "Found" : "Not Found") << endl;
  return 0;
}