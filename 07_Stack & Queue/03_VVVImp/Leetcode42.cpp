#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

      int len = height.size();

      if(len == 0 || len == 1 || len == 2) return 0;

      vector<int> prefixLeft(len);
      vector<int> suffixRight(len);

      prefixLeft[0] = height[0];
      suffixRight[len - 1] = height[len - 1];

      for(int i = 1; i < len; i++)
      {
        prefixLeft[i] = max(prefixLeft[i - 1], height[i]);
      }

      for(int i = len - 2; i >= 0; i--)
      {
        suffixRight[i] = max(suffixRight[i + 1], height[i]);
      }

      int total = 0;

      for(int i = 0; i < len; i++)
      {
        if(min(prefixLeft[i], suffixRight[i]) > height[i]){
          total += (min(prefixLeft[i], suffixRight[i]) - height[i]);
        }
        
      }  
      
      return total;
    }
};

int main()
{
  Solution sol;
  vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
  int result = sol.trap(height);  
  cout << result << endl;



  return 0;
}