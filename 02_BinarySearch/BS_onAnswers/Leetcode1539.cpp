#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size()-1;

        if(arr.size() == 0) return k;


        while(low <= high)
        {
          int mid = (low + high)/2;
          int missing = arr[mid] - (mid + 1);

          if(missing < k) low = mid+1;
          else high = mid-1;
        }
        cout << "low: " << low << ", high: " << high << endl;
        // return arr[low] + (k-low);

        return low + k;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << "The " << k << "th positive integer missing from the array is: " << sol.findKthPositive(arr, k) << endl;


  return 0;
}