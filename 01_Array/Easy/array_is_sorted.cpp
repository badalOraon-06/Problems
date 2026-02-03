#include<bits/stdc++.h>
using namespace std;

//Brute
bool isSorted(vector<int> arr)
{
  for(int i=0;i<arr.size();i++)
  {
    for(int j=i+1;j<arr.size();j++)
    {
      if(arr[i]>arr[j])
      {
        return false;
      }
    }
  }
  return true;
}

//optimal
bool Optimal_isSorted(vector<int> arr)
{
  for(int i=1;i<arr.size();i++)
  {
    if(arr[i]<arr[i-1])
    {
      return false;
    }
  }
  return true;
}



int main()
{
  vector<int> arr={1,11,2,5,9};
  cout<<isSorted(arr);




  return 0;
}