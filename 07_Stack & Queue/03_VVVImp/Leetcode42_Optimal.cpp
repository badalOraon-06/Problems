#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



class Solution {
public:
    int trap(vector<int>& height) {

      int left = 0;
      int right = height.size() - 1;

      int leftMax = height[0];
      int rightMax = height[height.size() - 1];

      int total = 0;

      while (left < right)
      {
        if(height[left] < height[right])
        {
          if(leftMax > height[left]){
            total += leftMax - height[left];
          }
          else{
            leftMax = height[left];
          }
          
          left++;

        }
        else{
          if(rightMax > height[right]){
            total += rightMax - height[right];
          }
          else{
            rightMax = height[right];
          }
          
          right --;
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

