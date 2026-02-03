#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:

  bool checkIthBit(int n, int i)
  {
    return (n & (1 << i)) != 0;
  }
};

int main()
{
  Solution s;
  cout << s.checkIthBit(5, 3);

  return 0;
}