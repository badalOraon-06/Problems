#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> PSE(vector<int> &heights)
  {
    int size = heights.size();

    vector<int> result(size);

    stack<int> st;

    for(int i = 0; i < size; i++)
    {
      int curr = heights[i];
      while(!st.empty() && heights[st.top()] >= curr)
      {
        st.pop();
      }

      if(st.empty())
      {
        result[i] = -1;
      }
      else{
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

    for(int i = size - 1; i >= 0; i--)
    {
      int curr = heights[i];
      while(!st.empty() && heights[st.top()] > curr)
      {
        st.pop();
      }

      if(st.empty())
      {
        result[i] = size;
      }
      else{
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

    for(int i = 0; i < size; i++)
    {
      int currArea = (nse[i] - pse[i] - 1) * heights[i];
      maxArea = max(currArea, maxArea);
    }

    return maxArea;

  }
};

int main()
{
  Solution sol;
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  cout << sol.largestRectangleArea(heights) << endl;


  return 0;
}