#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<int> rowFlag(rows,0);
        vector<int> colFlag(cols,0);

        for(int i=0;i<rows;i++)
        {
          for(int j=0;j<cols;j++)
          {
            if(matrix[i][j]==0)
            {
              rowFlag[i]=1;
              colFlag[j]=1;
            }
          }
        }

        for(int i=0;i<rows;i++)
        {
          for(int j=0;j<cols;j++)
          {
            if(rowFlag[i]==1 || colFlag[j]==1)
            {
              matrix[i][j]=0;
            }
          }
        }
    }
};

int main(){
    vector<vector<int>> matrix = {
        {1, 1, 1,1},
        {1, 0, 1,0},
        {1, 1, 1,1}
    };

    Solution obj;
    obj.setZeroes(matrix);

    for(const auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}