#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int rows = matrix.size();
    int columns = matrix[0].size();

    int row = 0;
    int col = columns - 1;

    while(row < rows && col >= 0)
    {
      if(matrix[row][col] == target) return true;
      else if(matrix[row][col] < target) row++;
      else col--;
    }

    return false;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> matrix = {
      {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}};

  cout << solution.searchMatrix(matrix, 5) << endl;  // Output: true
  cout << solution.searchMatrix(matrix, 13) << endl; // Output: false

  return 0;
}