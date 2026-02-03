#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int size1 = nums1.size();
    int size2 = nums2.size();
    int totalSize = size1 + size2;

    bool isOdd = totalSize % 2;

    int left = 0;
    int right = 0;
    int countIdx = 0;

    int previous = 0;
    int current = 0;

    int medianIdx = totalSize / 2;

    while (countIdx <= medianIdx)
    {      
      previous = current;


      if (left < size1 && (right >= size2 || nums1[left] <= nums2[right]))
      {
        current = nums1[left];
        left++;
      }
      else
      {
        current = nums2[right];
        right++;
      }
      countIdx++;
    }

    if(isOdd) return current;
    return (current + previous) / 2.0;
  }
};

int main()
{
  Solution sol;
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};
  cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
  vector<int> nums3 = {1, 2};
  vector<int> nums4 = {3, 4};
  cout << sol.findMedianSortedArrays(nums3, nums4) << endl;

  return 0;
}