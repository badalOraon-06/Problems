#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    return atMost(nums, k) - atMost(nums, k - 1);
  }

private:
  int atMost(vector<int> &nums, int k)
  {
    if(k < 0) return 0;

    int l = 0, r = 0;
    int size = nums.size();

    int OddCnt = 0;

    int totalCount = 0;

    while(r < size)
    {
      if(nums[r] % 2 != 0) OddCnt++;

      while(OddCnt > k)
      {
        if(nums[l] % 2 != 0) OddCnt--;
        l++;
      }

      totalCount += (r - l + 1);

      r++;
    }

    return totalCount;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 1, 2, 1, 1};
  int k = 3;
  cout << s.numberOfSubarrays(nums, k) << endl;



  return 0;
}