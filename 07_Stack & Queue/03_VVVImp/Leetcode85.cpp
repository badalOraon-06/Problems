#include <iostream>
#include <vector>
#include<stack>

using namespace std;

class Solution
{
public:
  vector<int> PSE(vector<int> &heights)
  {
    int size = heights.size();

    vector<int> result(size);

    stack<int> st;

    for (int i = 0; i < size; i++)
    {
      int curr = heights[i];
      while (!st.empty() && heights[st.top()] >= curr)
      {
        st.pop();
      }

      if (st.empty())
      {
        result[i] = -1;
      }
      else
      {
        result[i] = st.top();
      }

      st.push(i);
    }

    return result;
  }

  vector<int> NSE(vector<int> &heights)
  {
    int size = heights.size();

    vector<int> result(size);

    stack<int> st;

    for (int i = size - 1; i >= 0; i--)
    {
      int curr = heights[i];
      while (!st.empty() && heights[st.top()] > curr)
      {
        st.pop();
      }

      if (st.empty())
      {
        result[i] = size;
      }
      else
      {
        result[i] = st.top();
      }

      st.push(i);
    }

    return result;
  }

  int largestRectangleArea(vector<int> &heights)
  {
    int size = heights.size();

    vector<int> pse = PSE(heights);
    vector<int> nse = NSE(heights);

    int maxArea = 0;

    for (int i = 0; i < size; i++)
    {
      int currArea = (nse[i] - pse[i] - 1) * heights[i];
      maxArea = max(currArea, maxArea);
    }

    return maxArea;
  }

  int maximalRectangle(vector<vector<char>> &matrix)
  {
    int rows = matrix.size();
    if(matrix.empty())
    {
      return 0;
    }
    int columns = matrix[0].size();

    vector<int> height(columns, 0);

    int maxArea = 0;

    for(int i = 0; i < rows; i++)
    {
      // this loop count height of consecutive ones
      for(int j = 0; j < columns; j++)
      {
        if(matrix[i][j] == '0')
        {
          height[j] = 0;
        }
        else{
          height[j] += 1;
        }
      }

      int currMaxArea = largestRectangleArea(height);

      if(currMaxArea > maxArea) maxArea = currMaxArea;

    }

    return maxArea;
  }
};

int main()
{
  Solution sol;

   vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                  {'1','0','1','1','1'},
                                  {'1','1','1','1','1'},
                                  {'1','0','0','1','0'}};
  int result = sol.maximalRectangle(matrix);
  cout << result << endl;


  return 0;
}