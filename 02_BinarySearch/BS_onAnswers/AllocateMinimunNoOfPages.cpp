#include<iostream>
#include<vector>  
#include<algorithm>
#include<numeric>
using namespace std;


class Solution{
  public:
  int pages(vector<int> &books,int m)
  {
    int low = *max_element(books.begin(),books.end());
    int high = accumulate(books.begin(),books.end(),0);

    while(low <= high)
    {
      int mid = (low+high)/2;
      int count=1;
      int sum=0;
      for(int i = 0 ;i<books.size();i++)
      {
        sum+=books[i];
        if(sum>mid)
        {
          count++;
          sum=books[i];
        }
      }

      if(count>m)
      {
        low=mid+1;
      }
      else high=mid-1;
    }
    return low;
  }
};


int main()
{
  Solution obj;
  vector<int> books = {12, 34, 67, 90};
  int m = 2;
  cout << obj.pages(books, m) << endl;
  return 0;
}