#include<iostream>
#include<vector>
using namespace std;


class Solution{
  public:
  /*
  int getElement(int row,int col)
  {
    int res=1;
    for(int i=0;i<col;i++)
    {
      res=res*(row-i);
      res=res/(i+1);
      
    }
    return res;
  }
    */


  vector<int> getRow(int rowIndex)
  {
    int res=1;
    vector<int> row;
    row.push_back(res);

    for(int i=1;i<rowIndex;i++)
    {
      res=res*(rowIndex-i);
      res=res/i;
      row.push_back(res);
    }
    return row;
  }
  
  vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 1; i <=numRows; ++i) {
            vector<int> row = getRow(i);
            triangle.push_back(row);
        }
        return triangle;
    }
    
};


int main()
{
  Solution solution;

  int numRows = 5;
  vector<vector<int>> triangle = solution.generate(numRows);  
  for (const auto& row : triangle) {
      for (int val : row) {
          cout << val << " ";
      }
      cout << endl;
  }

  return 0;
}