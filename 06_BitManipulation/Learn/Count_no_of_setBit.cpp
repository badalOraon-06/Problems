#include<iostream>

using namespace std;

class Solution {
public:
    int countSetBits(int n) {
      int count = 0;
      while (n != 0)
      {
        if(n & 1)count++;
        n = n >> 1;
      }

      return count;
      }
};

int main()
{
  Solution s;
  cout<<s.countSetBits(5)<<endl;
  cout<<s.countSetBits(7)<<endl;
  cout<<s.countSetBits(10)<<endl;
  cout<<s.countSetBits(0)<<endl;


  return 0;
}