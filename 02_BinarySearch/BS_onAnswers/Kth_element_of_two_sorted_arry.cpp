#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
  public:
  int element(vector<int> &nums1, vector<int> &nums2, int k)
  {
    int size1 = nums1.size();
    int size2 = nums2.size();
    if (size1 > size2)
      return element(nums2, nums1, k);

    int low  = max(0, k - size2);
int high = min(k, size1);
    while (low <= high)
    {
      int mid = (low + high) / 2;

      int num1LeftCount = mid;
      int num2LeftCount = k - num1LeftCount;

      int left1 = (num1LeftCount > 0) ? nums1[num1LeftCount - 1] : INT_MIN;
      int right1 = (num1LeftCount < size1) ? nums1[num1LeftCount] : INT_MAX;

      int left2 = (num2LeftCount > 0) ? nums2[num2LeftCount - 1] : INT_MIN;
      int right2 = (num2LeftCount < size2) ? nums2[num2LeftCount] : INT_MAX;

      if (left1 <= right2 && left2 <= right1)
      {
        return max(left1, left2);
      }
      else if (left1 > right2)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return -1;
  }
};

int main()
{
  Solution sol;
  vector<int> nums1 = {1, 3, 8, 9, 15};
  vector<int> nums2 = {7, 11, 19, 21, 25};
  int k = 2;

  int result = sol.element(nums1, nums2, k);
  cout << "The " << k << "th element is: " << result << endl;

  return 0;
}