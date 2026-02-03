#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

      int size1 = m - 1;
      int size2 = n - 1;

      int nums1It = m + n - 1;
      while(size1 >= 0 && size2 >= 0)
      {
        if(nums1[size1] <= nums2[size2])
        {
          nums1[nums1It] = nums2[size2];
          size2--;
        }
        else{
          nums1[nums1It] = nums1[size1];
          size1--;
        }
        nums1It--;
        
      }
      while(size2 >= 0)
      {
        nums1[nums1It] = nums2[size2];
        nums1It--;
        size2--;
      }
      
    }
};

int main()
{
  Solution solution;
  vector<int> nums1 = {1,3,5, 0, 0, 0};
  vector<int> nums2 = {2,4,6};
  solution.merge(nums1, 3, nums2, 3);

  for (int num : nums1) {
        cout << num << " ";
        }
        cout<<endl;
  
  return 0;
}