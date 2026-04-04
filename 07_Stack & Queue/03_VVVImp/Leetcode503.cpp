#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    // Using stack to keep track of next greater elements
    int size = nums.size();

    stack<int> st;
    vector<int> result(size, -1);

    for (int i = 2 * size - 1; i >= 0; i--)
    {
      int currElement = nums[i % size];

      while (!st.empty() && st.top() <= currElement)
      {
        st.pop();
      }

      if (i < size && !st.empty())
      {
        result[i] = st.top();
      }

      st.push(currElement);
    }    

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 3};
  vector<int> result = sol.nextGreaterElements(nums);
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}