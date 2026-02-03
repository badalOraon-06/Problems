#include<iostream>
#include<vector>

using namespace std;

class Solution{

  public:
  vector<int> Find(vector<int> nums){

    long long len = nums.size();
    long long actualSum = 0; //len*(len + 1)/2;
    long long currSum = 0;

    long long actualSumOfSquare = 0;
    long long currSumOfSquare = 0;

    for(int i = 0; i < nums.size(); i++)
    {
      actualSum += i + 1;
      actualSumOfSquare += (i+1) * (i+1);

      currSum += nums[i];     
      currSumOfSquare += nums[i] * nums[i];
    }

    long long val1 = actualSum - currSum;
    long long val2 = actualSumOfSquare - currSumOfSquare;

    val2 = val2/val1;

    long long x = (val1 + val2)/2;
    long long y = x - val1;

    return {(int)x, (int)y};
  }
};

int main()
{
  Solution obj;
  vector<int> arr = {3, 1, 3};
  vector<int> result = obj.Find(arr);
  cout << "Missing Number: " << result[0] << ", Repeating Number: " << result[1] << endl;
  return 0;
}