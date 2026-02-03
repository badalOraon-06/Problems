#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {

      vector<int> final;

      int left = 0;
      int right = 0;

      int leftSize = nums1.size();
      int rightSize = nums2.size();

      while(left < leftSize && right < rightSize)
      {
        while(left + 1 < leftSize && nums1[left] == nums1[left + 1])left++;

        while(right + 1 < rightSize && nums2[right] == nums2[right + 1])right++;

        if(nums1[left] == nums2[right])
        {
          final.push_back(nums1[left]);
          left++;
          right++;
        }
        else if(nums1[left] < nums2[right])
        {
          final.push_back(nums1[left]);
          left++;
        }
        else{
          final.push_back(nums2[right]);
          right++;
        }
      }

      while(left < leftSize)
      {
        while(left + 1 < leftSize && nums1[left] == nums1[left + 1])left++;
        final.push_back(nums1[left]);
        left++;
      }

      while(right < rightSize)
      {
        while(right + 1 < rightSize && nums2[right] == nums2[right + 1])right++;
        final.push_back(nums2[right]);
        right++;
      }

      return final;
        
    }
};


int main()
{
  vector<int>nums1={1,2,2,5};
  vector<int>nums2={2,3,4};
  Solution obj;
  vector<int>result = obj.unionArray(nums1, nums2);
  for(int i=0;i<result.size();i++)
  {
    cout<<result[i]<<" ";
  }

  return 0;
}

