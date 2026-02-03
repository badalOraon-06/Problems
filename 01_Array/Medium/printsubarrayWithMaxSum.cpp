#include<iostream>
#include<vector>

using namespace std;

vector<int> fun(vector<int>& nums)
{
  int maxSum = nums[0];
  int maxEndingSum = nums[0];

  for(int num : nums)
  {
    maxEndingSum += num;
    maxEndingSum = max(maxEndingSum, num);

    maxSum = max(maxSum, maxEndingSum);
  }
}

int main()
{


  return 0;
}