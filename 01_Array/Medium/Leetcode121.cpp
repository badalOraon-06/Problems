#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int maxProfit(vector<int>& prices) {
      int size=prices.size();
      int maxProfit=0;
      for(int i=0;i<size;i++)
      {
        for(int j=i+1;j<size;j++)
        {
          if(prices[j]>prices[i])
          {
            maxProfit=max(maxProfit,prices[j]-prices[i]);
          }
        }
      }
      return maxProfit;
    }
};


int main()
{
  vector<int> prices={7,1,5,3,6,4};
  Solution Obj;
  cout<<Obj.maxProfit(prices);


  return 0;
}