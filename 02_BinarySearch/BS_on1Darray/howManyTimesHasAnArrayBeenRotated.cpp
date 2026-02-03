#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    int findKRotation(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = (low + high)  / 2;

            if (nums[mid] > nums[high]) {
                // Minimum is in the right half
                low = mid + 1;
            } else {
                // Minimum is in the left half (including mid)
                high = mid;
            }
        }

        return low;
    }
  
};

int main()
{
  vector<int> nums = {4,5,6,7,0,1,2,3};
  Solution obj;
  cout << obj.findKRotation(nums) << endl; // Expected output: 1
    


  return 0;
}