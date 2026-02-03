#include <iostream>

using namespace std;
//2nd Approach
class Solution {
public:
    int minBitFlips(int start, int goal) {
        
      int x = start ^ goal;

      int count = 0;

      while(x)
      {
        count += (x & 1);

        x >>= 1;
      }

      return count;
    }
};


// first approach 
// class Solution
// {
// public:
//   int minBitFlips(int start, int goal)
//   {
//     int count = 0;

//     int greatest = max(start, goal);

//     int temp = 1;

//     while (start != 0 || goal != 0)
//     {
//       if ((start & 1) != (goal & 1))
//         count++;

//       start >>= 1;
//       goal >>= 1;
//     }

//     return count;
//   }
// };

int main()
{
  Solution s;
  cout << s.minBitFlips(10, 7) << endl;

  return 0;
}