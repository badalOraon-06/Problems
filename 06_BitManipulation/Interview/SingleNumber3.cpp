#include<iostream>
#include<vector>

using namespace std;

class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
			int totalXOR = 0;

			for(int num : nums)
			{
				totalXOR = totalXOR ^ num;
			}

			int testBit = (totalXOR & (totalXOR - 1)) ^ totalXOR;	
			
			int set = 0;
			int notSet = 0;

			for (int num : nums)
			{
				if((num & testBit) != 0)
				{
					set = set ^ num;
				}
				else{
					notSet = notSet ^ num;
				}
			}

			return (set < notSet) ? vector<int>{set, notSet} : vector<int>{notSet, set};
		}
};


int main()
{
	Solution sol;
	vector<int> nums = {1,2,1,3,2,5};
	vector<int> result = sol.singleNumber(nums);
	for(int num : result)
	{
		cout << num << " ";
	}
  return 0;
}