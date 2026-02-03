#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
  public:

  int AggressiveCows(vector<int> &stalls,int k)
  {
    sort(stalls.begin(),stalls.end());
    int low = 1;
    int high = stalls[stalls.size()-1] - stalls[0];

    while (low <= high)
    {
      int mid = (low + high)/2;

      int count = 1;
      int previous = stalls[0];
      for(int i = 1; i<stalls.size() ;i++)
      {
        if(stalls[i] - previous >= mid)
        {
          count++;
          previous =stalls[i];
        }
      }

      if(count < k)
      {
        high = mid-1;
      }
      else 
      {
        low = mid+1;
      }
    }

    return high;


  }

};

int main()
{
  
  
  vector<int> stalls={0,3,4,7,10,9};
  int k=4;
  // Example input: stalls = {0, 3, 4, 7, 10, 9}, k = 4
  // Expected output: 3 (the maximum minimum distance between cows)
  
  Solution obj;
  cout << obj.AggressiveCows(stalls, k) << endl;

  return 0;
}