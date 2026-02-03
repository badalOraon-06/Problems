#include<iostream>
#include<vector>
#include<climits>


using namespace std;


class MinStack {
  long long min;
  int index;
  vector<long long> st;
public:
    MinStack() {
      min = LLONG_MAX;      
      index = -1;  
    }
    
    void push(int val) {
      long long x = val;
      if(index < 0)
      {
        st.push_back(x);    
        min = x;    
      }
      else if(x >= min)
      {
        st.push_back(x);
      }
      else{
        long long modified = 2LL * x - min;
        st.push_back(modified);
        min = x;
      }  
      index++;     
    }
    
    void pop() {
      if(index < 0)
        return;
      
      if(st[index] >= min)
      {
        st.pop_back();
        index--;
      }
      else{
        long long prev_min = 2LL * min - st[index];
        min = prev_min;
        st.pop_back();
        index--;
      }
        
    }
    
    int top() {
      if(index < 0)
        return -1;
        
      if(st[index] >= min)
      {
        return st[index];
      }
      
      return min;
        
    }
    
    int getMin() {
        return min;
    }
};



int main()
{
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout<<minStack.getMin()<<endl; // return -3
  minStack.pop();
  cout<<minStack.top()<<endl;    // return 0
  cout<<minStack.getMin()<<endl; // return -2

  return 0;
}