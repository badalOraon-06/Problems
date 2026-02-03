#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int col0=1;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j]==0 && j!=0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
                else if(matrix[i][j]==0 && j==0)
                {
                    matrix[i][0]=0;
                    col0=0;
                }
            }
        }

        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0)
        {
            for(int j=0;j<cols;j++)
            {
                matrix[0][j]=0;
            }
        }
        if(col0==0)
        {
            for(int i=0;i<rows;i++)
            {
                matrix[i][0]=0;
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