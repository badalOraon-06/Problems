#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        // Your code goes here
        int size = arr.size();
        stack<int> st;

        vector<int> result(size);

        for(int i = size - 1; i >= 0; i--)
        {
          int currElement = arr[i];

          while(!st.empty() && st.top() > currElement){
            st.pop();
          }

          if(!st.empty())
          {
            result[i] = st.top();
          }

          else{
            result[i] = -1;
          }

          st.push(arr[i]);
        }

        return result;
    }
};



int main()
{
  Solution sol;
  vector<int> arr = {4, 5, 2, 10, 8};
  vector<int> result = sol.nextSmallerElements(arr);
  for(int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  


  return 0;
}