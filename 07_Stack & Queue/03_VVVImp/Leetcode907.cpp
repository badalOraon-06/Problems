#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class Solution {
public:
    vector<int> PSE(vector<int>& arr)
    {
      stack<int> st;
      vector<int> pse(arr.size());

      for(int i = 0; i < arr.size() ; i++)
      {
        int currElement = arr[i];

        while(!st.empty() && arr[st.top()] >= currElement)
        {
          st.pop();
        }
        
        pse[i] = st.empty() ? -1 : st.top();

        st.push(i);
      }

      return pse;      
    }

    vector<int> NSE(vector<int>& arr)
    {
      int size = arr.size();
      stack<int> st;
      vector<int> nse(arr.size());

      for(int i = size - 1; i >= 0 ; i--)
      {
        int currElement = arr[i];

        while(!st.empty() && arr[st.top()] > currElement)
        {
          st.pop();
        }
        
        nse[i] = st.empty() ? arr.size() : st.top();

        st.push(i);
      }

      return nse;      
    }

    int sumSubarrayMins(vector<int>& arr) {
      int size = arr.size();

      int mod = (int)(1e9 + 7);
      
      
      vector<int> pse = PSE(arr);
      vector<int> nse = NSE(arr);

      int sum = 0;

      for(int i = 0; i < size; i++)
      {
        int left = i - pse[i];
        int right = nse[i] - i;

        sum = (sum + (right * left * 1ll * arr[i]) % mod) % mod;
      }
      
      return sum;      
    }
};


int main()
{
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};

    cout << sol.sumSubarrayMins(arr) << endl;


  return 0;
}