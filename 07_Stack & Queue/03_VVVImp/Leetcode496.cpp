#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {       
        int size1 = nums1.size();
        int size2 = nums2.size();

        unordered_map<int, int> map;

        vector<int> result;

        stack<int> st;

        // loop for finding the next greater element of nums2 and pushing currelement with its next greater element in a unordred map 
        for(int i = size2 - 1; i >= 0; i--)
        {
            int currElement = nums2[i];
            
            // ensuring that the stack top should store the NGE (stores element in increasing order)
            while(!st.empty() && st.top() < currElement)
            {
                st.pop();
            }

            // if stack contains an element then the topmost element is the NGE for currElement
            if(!st.empty())
            {
                map[currElement] = st.top();
            }
            // if Stack is empty then there is no NGE for the currElement
            else{
                map[currElement] = -1;
            }

            // push currElement to the stack so it can also participate to become NGE for the elements present to its left side
            st.push(currElement);
        }

        for(int i = 0; i < size1; i++)
        {
            result.push_back(map[nums1[i]]);            
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    for (int val : result)
    {
        cout << val << " ";
    }

    
    return 0;
}