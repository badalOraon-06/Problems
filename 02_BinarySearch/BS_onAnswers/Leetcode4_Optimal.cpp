#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int size1 = nums1.size();
    int size2 = nums2.size();

    if (size1 > size2) return findMedianSortedArrays(nums2, nums1);

    int low = 0;
    int high = size1;

    bool isOdd = (size1 + size2) % 2;

    int totalLeft = (size1 + size2)/2;

    while(low <= high)
    {
      int mid = (low + high)/2;

      int nums1LeftCount = mid;
      int nums2LeftCount = totalLeft - mid;

      int left1 = (nums1LeftCount > 0) ? nums1[nums1LeftCount - 1] : INT_MIN;
      int right1 = (nums1LeftCount < size1) ? nums1[nums1LeftCount] : INT_MAX;

      int left2 = (nums2LeftCount > 0) ? nums2[nums2LeftCount - 1] :INT_MIN;
      int right2 = (nums2LeftCount < size2) ? nums2[nums2LeftCount] : INT_MAX;

      if( left1 <= right2 && left2 <= right1)
      {
        int leftMax = max(left1,left2);
        int rightMin = min(right1,right2);

        if(isOdd) return rightMin;
        return (leftMax + rightMin)/2.0;
      }
      else if(left1 > right2) high = mid - 1;
      else low = mid + 1;


    }

    return -1;

  }
};

int main()
{
  Solution sol;
  
  vector<int> nums3 = {1, 2};
  vector<int> nums4 = {3};
  cout << sol.findMedianSortedArrays(nums3, nums4) << endl;

  return 0;
}