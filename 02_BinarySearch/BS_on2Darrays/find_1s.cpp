#include<iostream>
#include<vector>

using namespace std;

class Solution{
  public:
  int find(vector<vector<int>> mat)
  {
    int rows = mat.size();
    int column = mat[0].size();

    int index = - 1;
    int maxCount = 0;

    for(int i = 0; i < rows; i++)
    {
      int low = 0;
      int high = column - 1;

      int currCount = 0;

      while(low <= high)
      {
        int mid = (low + high)/2;

        if(mat[i][mid] == 1)
        {
          currCount = column - mid;
          high = mid - 1;
        }
        else{
          low = mid + 1;
        }
      }

      if(currCount > maxCount){
        maxCount = currCount;
        index = i;
      }

    }
    
    return index;
  }

};

int main()
{
  Solution solution;
  vector<vector<int>> mat = {
    {0, 1, 1, 1},
    {1, 1, 1, 1},
    {0, 0, 1, 0}
  };
  int rowIndex = solution.find(mat);
  cout << "Row with maximum 1's is: " << rowIndex << endl;

  return 0;
}
