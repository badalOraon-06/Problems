#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution
{
  public:
  int painter(vector<int> &boards , int k)
  {
    int low = *max_element(boards.begin(),boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);

    while(low <= high)
    {
      int mid = (low + high)/2;

      int time = 0;
      int count = 1;

      for(int board : boards)
      {
        time += board;

        if(time > mid)
        {
          time = board;
          count++;
        }
      }

      if(count > k) low = mid + 1;

      else high = mid - 1;
    }

    return low;
  }
};

int main()
{
  Solution obj;
  vector<int> boards = {10, 20, 30, 40};
  int k = 2;
  int result = obj.painter(boards, k);
  cout << "Minimum time required: " << result << endl;
  return 0;
}