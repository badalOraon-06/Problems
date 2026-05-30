#include<iostream>
#include<vector>
#include<deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

      int l = 0, r = 0;
      int size = nums.size();

      deque<int> q;
      vector<int> result(size - k + 1);

      while(r < k)
      {
        while(!q.empty() && nums[q.back()] < nums[r])
        {
          q.pop_back();
        }
        q.push_back(r);
        r++;
      }

      result[l] = nums[q.front()];

      while(r < size)
      {
        l++;
        if(!q.empty() && q.front() < l) q.pop_front();

        while(!q.empty() && nums[q.back()] < nums[r])
        {
          q.pop_back();
        }
        q.push_back(r);
        result[l] = nums[q.front()];
        r++;
        
      }

      return result;
    }
};

int main()
{
  Solution s;
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  int k = 3;
  vector<int> result = s.maxSlidingWindow(nums, k);
  for(int i : result)
  {
    cout << i << " ";
  }

  return 0;
}