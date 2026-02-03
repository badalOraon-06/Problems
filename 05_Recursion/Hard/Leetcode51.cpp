#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool safe(int row, int col, vector<string>& board, int& n)
    {
      // this function will check for the safe place for the queen
      int dupRow = row;
      int dupCol = col;

      while(row >= 0 && col >= 0)
      {
        if(board[row][col] == 'Q')return false;
        row--;
        col--;
      }

      row = dupRow;
      col = dupCol;

      while(row >= 0)
      {
        if(board[row][col] == 'Q') return false;
        row--;
      }

      row = dupRow;
      col = dupCol;

      while(row >= 0 && col < n)
      {
        if(board[row][col] == 'Q') return false;
        row--;
        col++;
      }

      return true;
    }

    void solve(int row, vector<vector<string>>& result, vector<string>& board, int& n)
    {
      // this function will find all possible solutions and push it to the result array
      if(row >= n)
      {
        result.push_back(board);
        return;
      }

      for(int col = 0; col < n; col++)
      {
        if(safe(row, col, board, n))
        {
          board[row][col] = 'Q';
          solve(row + 1, result, board, n);
          board[row][col] = '.';
        }
      }
    }

    vector<vector<string>> solveNQueens(int n) {

      vector<vector<string>> result;
      vector<string> board(n);
      string s(n, '.');

      for(int i = 0; i < n; i++)
      {
        board[i] = s;
      }

      solve(0, result, board, n);

      return result;        
    }
};



// class Solution {
// public:
//     bool isSafe(string& checkStr, int& row, int& col, int& n)
//     {
//       if(checkStr[col] != '.') return false;

//       for(int i = 0; i < n; i++)
//       {
//         if(row - checkStr[i] != col - i) 
//         {
//           checkStr[col] = row;
//           return true;
//         }
//       }

//       return false;
//     }

//     void helper(int n, int row, vector<vector<string>>& result, vector<string> currMat, string currRow, string checkStr)
//     {
//       if(n == row)
//       {
//         result.push_back(currMat);
//       }

//       currRow = string(n, '.');

//       for(int i = 0; i < n; i++)
//       {
//         if(!isSafe(checkStr, row, i, n)) continue;
        
//         currRow[i] = 'Q';
//         helper(n, row+1, result, currMat, "", checkStr);                
//       }
//     }
   

//     vector<vector<string>> solveNQueens(int n) {

//       vector<vector<string>> result;
//       vector<string> currMat;
//       string checkStr(n, '.');

//       for(int i = 0; i < n; i++)
//       {
//         helper(n, 0, result, currMat, "", checkStr);
//       }

      
//       return result;
//     }
  
// };

int main()
{
  Solution sol;
  int n = 4;
  vector<vector<string>> result = sol.solveNQueens(n);

  for (const auto& board : result) {
    for (const auto& row : board) {
      cout << row << endl;
    }
    cout << endl;
  }

  return 0;
}