#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
      int size = s.size();
        string answer = "";
        
        unordered_map<char,int> freq;

        for(char c : s)
        {
          freq[c]++;
        }

        vector<vector<char>> bucket(size + 1);

        for(auto &i : freq)
        {
          bucket[i.second].push_back(i.first);
        }

        for(int i = size; i > 0; i--)
        {
          for(char c : bucket[i])
          {
            answer.append(i,c);
          }
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