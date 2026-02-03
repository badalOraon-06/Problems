#include<iostream>

using namespace std;

class Solution{
  public:

  void swap(int& x, int& y)
  {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
  }
};


int main()
{
  Solution s;
  int a = 5;  
  int b = 10;
  s.swap(a,b);
  cout<<a<<" "<<b<<endl;

  return 0;
}