#include<iostream>
#include<vector>
using namespace std;

/*
class Solution 
{
  public:
      void rotate(vector<int>& nums, int k)
      {
        for(int i=0;i<k;i++)
        {
          int n=nums.size();
          int temp=nums[n-1];
          for(int i=n-1;i>0;i--)
          {
            nums[i]=nums[i-1];
          }
          nums[0]=temp;
        }       
      }
};
*/

// wrong approach
/*
class Solution 
{
  public:
      void rotate(vector<int>& nums, int k)
      {
        vector<int> temp;
        int x=0;
        k=k%n;


        int n=nums.size();
        for(int i=0;i<n;i++)
        {
          if(i<k)
          {
            temp.push_back( nums[(i+k)%n] );
            nums[(i+k)%n]=nums[i];
          }
          
          else if((i+k)%n>=k)
          {
            temp.push_back(nums[(i+k)%n]);
            nums[(i+k)%n]=temp[x++];
          }
          


          else{
            nums[(i+k)%n]=temp[x++];
          }

        }        
      }
};
*/


class Solution{
  public:
      void rotate(vector<int>& nums,int k) {
          int n=nums.size();
          k=k%n; // Handle cases where k > n
          vector<int> temp(n);
  
          // Store rotated elements in the new array
          for(int i=0;i<n;i++) {
              temp[(i+k)%n]=nums[i];
          }
  
          // Copy back to original array
          nums=temp;
      }
  };


int main()
{
  Solution person;
  vector<int> nums={1,2};

  for(int i=0;i<nums.size();i++)
  {
    cout<<nums[i]<<" ";
  }
  cout<<endl;


  person.rotate(nums,3);

  for(int i=0;i<nums.size();i++)
  {
    cout<<nums[i]<<" ";
  }

  return 0;
}