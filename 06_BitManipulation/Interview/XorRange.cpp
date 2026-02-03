#include<iostream>

using namespace std;

class Solution{	
	public:
    int xorFrom0(int n)
    {
      if(n % 4 == 0) return n;
      else if(n % 4 == 1) return 1;
      else if(n % 4 == 2) return n + 1;
      else return 0;
    }

		int findRangeXOR(int l,int r){
			return (xorFrom0(l - 1) ^ xorFrom0(r));
		}
};


int main()
{
  Solution sol;
  cout << sol.findRangeXOR(5, 7) << endl;  // Example usage
  cout << sol.findRangeXOR(10, 15) << endl;  //
  cout << sol.findRangeXOR(5, 7) << endl;  //
  
  return 0;
}