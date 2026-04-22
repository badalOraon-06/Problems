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

    long long sumSubarrayMins(vector<int>& arr) {
      int size = arr.size();      
      
      vector<int> pse = PSE(arr);
      vector<int> nse = NSE(arr);

      long long sum = 0;

      for(int i = 0; i < size; i++)
      {
        int left = i - pse[i];
        int right = nse[i] - i;

        sum = (sum + (right * left * 1ll * arr[i]));
      }
      
      return sum;      
    }



    // for maximums

    vector<int> PLE(vector<int>& arr)
    {
      stack<int> st;
      vector<int> ple(arr.size());

      for(int i = 0; i < arr.size() ; i++)
      {
        int currElement = arr[i];

        while(!st.empty() && arr[st.top()] <= currElement)
        {
          st.pop();
        }
        
        ple[i] = st.empty() ? -1 : st.top();

        st.push(i);
      }

      return ple;      
    }

    vector<int> NLE(vector<int>& arr)
    {
      int size = arr.size();
      stack<int> st;
      vector<int> nle(arr.size());

      for(int i = size - 1; i >= 0 ; i--)
      {
        int currElement = arr[i];

        while(!st.empty() && arr[st.top()] < currElement)
        {
          st.pop();
        }
        
        nle[i] = st.empty() ? arr.size() : st.top();

        st.push(i);
      }

      return nle;      
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
      int size = arr.size();
      
      
      vector<int> pse = PLE(arr);
      vector<int> nse = NLE(arr);

      long long sum = 0;

      for(int i = 0; i < size; i++)
      {
        int left = i - pse[i];
        int right = nse[i] - i;

        sum = (sum + (right * left * 1ll * arr[i]));
      }
      
      return sum;      
    }

    long long subArrayRanges(vector<int>& nums) {

      long long min = sumSubarrayMins(nums);
      long long max = sumSubarrayMaxs(nums);

      return max - min;        
    }
};

int main()
{
  Solution s;

  vector<int> nums = {4,-2,-3,4,1};

  cout << s.subArrayRanges(nums) << endl;

  return 0;
}