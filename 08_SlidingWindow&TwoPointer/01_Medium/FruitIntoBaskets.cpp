#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        //your code goes here

        int l = 0, r = 0;
        int size = fruits.size();

        int longest = 0;

        unordered_map<int, int> map;
        

        while(r < size)
        {
          // if(map.find(fruits[r]) == map.end())
          // {
          //   map[fruits[r]] = 1;
          // }
          // else{
          //   map[fruits[r]]++;
          // }

          // or simply do this 
          map[fruits[r]]++;

          while(map.size() > 2)
          {
            map[fruits[l]]--;
            if(map[fruits[l]] == 0) map.erase(fruits[l]);
            l++;
          }

          longest = max(longest, r - l + 1);
          r++;
        }

        return longest;
    }
};

int main()
{
  Solution s;
  vector<int> fruits = {1, 2, 3, 2, 2};
  cout << s.totalFruits(fruits) << endl;


  return 0;
}