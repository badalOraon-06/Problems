#include<iostream>
#include<vector>

using namespace std;

int secondLargest(vector<int>& array)
{
  int size = array.size();

  if(size == 0) return -1;
  int largest = array[0];
  int second = -1;

  for(int i = 1; i < size; i++)
  {
    if(array[i] > largest) 
    {
      second = largest;
      largest = array[i];
    }
    else if(array[i] <largest && array[i] > second){
      second = array[i];
    }
  }

  return second;
}

int main()
{
  vector<int> array = {10,5,8,12,15,6};
  cout<<secondLargest(array);

  


  return 0;
}