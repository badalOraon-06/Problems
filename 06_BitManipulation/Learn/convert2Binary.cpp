#include<iostream>
#include<algorithm>

using namespace std;

class Solution{
  public:

  string convert(int decimal)
  {
    string result = "";

    while(decimal > 0)
    {
      result += (decimal % 2) ? '1' : '0';
      decimal = decimal / 2;
    }

    reverse(result.begin(), result.end());

    return result;
  }

};

int main()
{
  Solution s;
  cout<<s.convert(10);
  

  return 0;
}