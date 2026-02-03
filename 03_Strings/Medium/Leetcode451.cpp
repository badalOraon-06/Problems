#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string answer = "";
        
        unordered_map<char,int> map;
        priority_queue<pair<int,char>> sorted;

        
        for(char c : s)
        {
          if(map.find(c) != map.end()) map[c]++;
          else map[c] = 1;
        }

        for(auto i : map)
        {
          sorted.push({i.second,i.first});
        }

        while(!sorted.empty())
        {
          int count = sorted.top().first;
          char element = sorted.top().second;

          for(int i = 0;i < count; i++)
          {
            answer += element;
          }
          sorted.pop();
        }

        return answer;
    }
};

int main()
{
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl; // Output: "eetr" or "eert"

    s = "cccaaa";
    cout << sol.frequencySort(s) << endl; // Output: "aaaccc" or "cccaaa"

    s = "Aabb";
    cout << sol.frequencySort(s) << endl; // Output: "bbAa" or "Aabb"


  return 0;
}