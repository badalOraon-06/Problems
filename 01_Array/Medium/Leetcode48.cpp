#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& arr)
    {
      int start=0;
      int end=arr.size()-1;
      while(start<end)
      {
        swap(arr[start],arr[end]);
        start++;
        end--;
      }
    }
    void rotate(vector<vector<int>>& matrix) {
      vector<vector<int>> ans;
      int size=matrix[0].size();
      for(int i=0;i<size-1;i++)
      {
        for(int j=i+1;j<size;j++)
        {
          if(i!=j)
          {
            swap(matrix[i][j],matrix[j][i]);
          }
        } 
      }
      for(int i=0;i<size;i++)
      {
        reverseArray(matrix[i]);
      }

        
    }
};

int main()
{
  Solution obj;
  vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
  obj.rotate(arr);
  for(int i=0;i<arr.size();i++)
  {
    for(int j=0;j<arr[i].size();j++)
    {
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}