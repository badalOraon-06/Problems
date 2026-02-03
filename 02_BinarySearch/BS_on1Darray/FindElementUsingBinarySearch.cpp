#include <bits/stdc++.h>
using namespace std;

int searchX(vector<int> arr,int element)
{
  int n=arr.size();
  int low=0;
  int high=n-1;

  while(low <= high)
  {
    int mid=(low+high)/2;

    if(arr[mid]==element)
    {
      return mid;
    }

    else if(arr[mid]>element)
    {
      high=mid-1;
    }

    else{
      low=mid+1;
    }
  }

  
  return -1;

}



int searchXrecursively(vector<int> arr,int low,int high,int target)
{
  if(low>high)
  {
    return -1;
  }

  int mid=(high+low)/2;
  if(arr[mid]==target)
  {
    return mid;
  }
  else if(arr[mid]>target)
  {
    return searchXrecursively(arr,low,mid-1,target);
  }
  else{
    return searchXrecursively(arr,mid+1,high,target);
  }
  return -1;
    
}
  



int main()
{
  vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = searchXrecursively(arr,0,arr.size()-1,target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "<< ind << endl;
    return 0;


  return 0;
}