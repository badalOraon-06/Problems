#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      int size = asteroids.size();

      stack<int> st;

      for(int i = 0; i < size; i++)
      {
         
        int curr = asteroids[i];

        if(curr > 0)
        {
          st.push(curr);
          continue;
        }

        while(!st.empty() && st.top() > 0 && st.top() < abs(curr))
        {
          st.pop();
          
        }
        if(!st.empty() && st.top() == abs(curr))
        {
          st.pop();
          continue;
        }

        if(st.empty() || st.top() < 0)
        {
          st.push(curr);
          continue;
        }

        if(st.top() > abs(curr))
        {
          continue;
        }

        st.push(curr);        
      }

      int stackSize = st.size();
      vector<int> result(stackSize);

      for(int i = stackSize - 1; i >= 0; i--)
      {
        result[i] = st.top();
        st.pop();
      }


      return result;
    }
};


int main()
{
  Solution s;

  vector<int> asteroids = {3,5,-6,2,-1,4};

  vector<int> result = s.asteroidCollision(asteroids);

  for(int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
}