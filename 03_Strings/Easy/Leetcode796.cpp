#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        return (s+s).find(goal) != string::npos;
    }
};

int main()
{
    Solution sol;

    string s = "abcde";
    string goal = "abced";

    if(sol.rotateString(s, goal)) {
        cout << "The string can be rotated to match the goal." << endl;
    } else {
        cout << "The string cannot be rotated to match the goal." << endl;
    }


  return 0;
}