#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    int getMaxIndex(vector<int>& arr, int size)
    {
      int maxIndex = 0;

      for(int i = 1; i < size; i++)
      {
        if(arr[i] > arr[maxIndex])maxIndex = i;
      }
      return maxIndex;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int columns = mat[0].size();

        int low = 0;
        int high = rows - 1;

        while(low <= high)
        {
          int mid = (low + high)/2;

          int index = getMaxIndex(mat[mid], columns);

          int top = (mid - 1 >= 0) ? mat[mid - 1][index] : -1;
          int bottom = (mid + 1 < rows) ? mat[mid + 1][index] : -1;

          
          if(top < mat[mid][index] && bottom < mat[mid][index]) return {mid, index};

          else if(top > mat[mid][index]) high = mid - 1;

          else low = mid + 1;
          
          
        }

        return {-1, -1};
    }
};

int main()
{
  Solution sol;
  vector<vector<int>> mat = {{1, 4, 3}, {2, 5, 6}, {3, 2, 1}};
  vector<int> peak = sol.findPeakGrid(mat);
  cout << "Peak found at: (" << peak[0] << ", " << peak[1] << ")" << endl;
  return 0;
}