#include<iostream>

using namespace std;

class Solution
{
  public:

  bool checkOdd(int x)
  {
    return (x & 1);
  }

};


int main()
{
  Solution s;
  cout<<s.checkOdd(4)<<endl;
  cout<<s.checkOdd(5)<<endl;

  return 0;
}