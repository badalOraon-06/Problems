#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void findword(vector<vector<char>>& board, int rowIdx, int colIdx, string& word, int strIdx, bool& result)
    {
        if(strIdx == word.size())
        {
            result = true;
            return;
        }

        int rows = board.size();
        int columns = board[0].size();

        if(rowIdx < 0 || colIdx < 0 || rowIdx >= rows || colIdx >= columns) return;

        if(board[rowIdx][colIdx] != word[strIdx]) return;

        char temp = board[rowIdx][colIdx];
        board[rowIdx][colIdx] = '#';

        findword(board, rowIdx - 1, colIdx, word, strIdx + 1, result);
        if(result) 
        {
            board[rowIdx][colIdx] = temp;
            return;
        }
        findword(board, rowIdx + 1, colIdx, word, strIdx + 1, result);
        if(result) 
        {
            board[rowIdx][colIdx] = temp;
            return;
        } 
        findword(board, rowIdx, colIdx - 1, word, strIdx + 1, result);
        if(result) 
        {
            board[rowIdx][colIdx] = temp;
            return;
        } 
        findword(board, rowIdx, colIdx + 1, word, strIdx + 1, result);

        board[rowIdx][colIdx] = temp;
        return;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int columns = board[0].size();

        bool result = false;
        

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(board[i][j] == word[0])
                {
                    findword(board, i, j, word, 0, result);
                }

                if(result) return result;
            }
        }


        return false;
    }
};


int main()
{
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    bool result = sol.exist(board, word);

    if(result)
    {
        cout << "The word exists in the board." << endl;
    }
    else
    {
        cout << "The word does not exist in the board." << endl;        
    }

    return 0;
}