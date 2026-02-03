#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
    void find(vector<vector<int>>& grid, vector<string>& result, string& currRoot, int row, int col, int n)
    {
      // this function start from cell(0, 0) and find the root and push that result in the result array

      if(row == n - 1 && col == n - 1)
      {
        result.push_back(currRoot);
        return;
      }
      grid[row][col] = 0;

      if(col + 1 < n && grid[row][col + 1] == 1)
      {
        currRoot += 'R';
        find(grid, result, currRoot, row, col + 1, n);
        currRoot.pop_back();
      }
      
      if(row + 1 < n && grid[row + 1][col] == 1)
      {
        currRoot += 'D';
        find(grid, result, currRoot, row + 1, col, n);
        currRoot.pop_back();
      }

      if(col - 1 >= 0 && grid[row][col - 1] == 1)
      {
        currRoot += 'L';
        find(grid, result, currRoot, row, col - 1, n);
        currRoot.pop_back();
      }

      if(row - 1 >= 0 && grid[row - 1][col] == 1)
      {
        currRoot += 'U';
        find(grid, result, currRoot, row - 1, col, n);
        currRoot.pop_back();
      }

      grid[row][col] = 1;
      
      return;
    }

    vector<string> findPath(vector<vector<int> > &grid) {
        //your code goes here
        vector<string> result;
        string currRoot = "";
        int n = grid.size();

        if(grid[0][0] == 0 || grid[n-1][n-1] == 0) return result;
        

        find(grid, result, currRoot, 0, 0, n);

        return result;       
        
    }
};


int main()
{

    Solution solution;

    vector<vector<int>> grid = {
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 0, 0},
      {0, 1, 1, 1}
    };

    vector<string> result = solution.findPath(grid);

    cout << "Possible paths from top-left to bottom-right are: " << endl;
    for(const string& path : result)
    {
      cout << path << endl;
    }


  return 0;
}