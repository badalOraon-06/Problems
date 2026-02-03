#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices) {
      int buyPrice=prices[0];
      int maxprofit=0;
      int currentProfit=0;
      int size=prices.size();
      for(int i=1;i<size;i++)
      {
        if(buyPrice>prices[i])
        {
          buyPrice=prices[i];
        }
        else{
          currentProfit=prices[i]-buyPrice;
          maxprofit=max(maxprofit,currentProfit);
        }
      }
      return maxprofit;
    }
};


int main()
{
  vector<int> prices={7,1,5,3,6,4};
  Solution Obj;
  cout<<Obj.maxProfit(prices);


  return 0;
}