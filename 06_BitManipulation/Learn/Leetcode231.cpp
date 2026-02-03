#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
    return (n & (n - 1)) == 0;
    }
};

int main()
{
  Solution s;
  cout<<s.isPowerOfTwo(2)<<endl;
  cout<<s.isPowerOfTwo(18)<<endl;
  cout<<s.isPowerOfTwo(1)<<endl;
  cout<<s.isPowerOfTwo(0)<<endl;

  return 0;
}