#include<iostream>
#include<vector>


using namespace std;
class Solution {
public:
    // vector<int> rearrangeArray(vector<int>& nums) {
    //     int posIndex=0,negIndex=1;
    //     int size=nums.size();
    //     vector<int> result(size);
    //     for(int i=0;i<size;i++)
    //     {
    //       if(nums[i]>=0)
    //       {
    //         result[posIndex]=nums[i];
    //         posIndex+=2;
    //       }
    //       else{
    //         result[negIndex]=nums[i];
    //         negIndex+=2;
    //       }
    //     }
    //     return result;
    // }

    vector<int> rearrangeArray(vector<int>& nums) {
        int posIndex=0,negIndex=1;
        int size=nums.size();
        
        while( posIndex < size && negIndex < size)
        {
          while(posIndex < size && nums[posIndex] > 0) posIndex += 2;
          while(negIndex < size && nums[negIndex] < 0) negIndex += 2;

          if(posIndex < size && negIndex < size)
          {
            int temp = nums[posIndex];
            nums[posIndex] = nums[negIndex];
            nums[negIndex] = temp;
          }
          posIndex +=2;
          negIndex += 2;
        }
        return nums;
    }
};

int main()
{
  vector<int> nums={3,1,-2,-5,2,-4};
  Solution Obj;
  for(int i=0;i<nums.size();i++)
  {
    cout<<Obj.rearrangeArray(nums)[i]<<" ";
  } 

  return 0;
}