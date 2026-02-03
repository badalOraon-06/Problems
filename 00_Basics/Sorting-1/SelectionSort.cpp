#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int>& array)
{
  int size = array.size();

  for(int i = 0; i < size; i++)
  {
    int smallest = i;
    for(int j = i + 1; j < size; j++)
    {
      if(array[smallest] > array[j]) smallest = j;
    }
    
    int temp = array[smallest];
    array[smallest] = array[i];
    array[i] = temp;
  }
}

int main()
{
  vector<int> array = {5,4,3,2,1};
  selectionSort(array); 
  for(int i : array)
  {
    cout<<i<<" ";
  }


  return 0;
}