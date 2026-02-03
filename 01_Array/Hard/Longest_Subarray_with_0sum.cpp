#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
  public:
  int subarray(vector<int> array)
  {
    int size = array.size();
    int currentSum = 0;
    int maxLen = 0;

    unordered_map<int,int> map;

    for(int i=0 ; i < size ; i++)
    {
      currentSum += array[i];
      if(currentSum == 0) maxLen = max(maxLen , i + 1);

      // int requiredSum = currentSum - 0;

      if(map.find(currentSum) != map.end())
      {
        int len = i - map[currentSum];
        maxLen = max(maxLen,len);
      }

      if(map.find(currentSum) == map.end())
      {
        map[currentSum] = i;
      }
      
    }

    return maxLen;
  }
};

int main()
{
  Solution sol;
  vector<int> array = {1, -1, 2, -2, 3, -3, 0};
  cout << "Length of longest subarray with 0 sum: " << sol.subarray(array) << endl;

  return 0;
}