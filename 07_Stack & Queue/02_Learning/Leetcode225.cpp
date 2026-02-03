#include<iostream>
#include<queue>

using namespace std;

class QueueStack {
  queue<int> queue1;
  queue<int> queue2;
public:
    QueueStack() {
    }
    
    void push(int x) {
      if(queue1.empty()) queue1.push(x);
      else{
        while(!queue1.empty())
        {
          queue2.push(queue1.front());
          queue1.pop();
        }
        queue1.push(x);
        while(!queue2.empty())
        {
          queue1.push(queue2.front());
          queue2.pop();
        }
      }
      return;
    }
    
    int pop() {
      if(queue1.empty()) return -1;
      int x = queue1.front();
      queue1.pop();
      return x;  
    }
    
    int top() {
      if(queue1.empty()) return -1;
      return queue1.front(); 
    }
    
    bool isEmpty() {
      return queue1.empty();
    }
};

int main()
{

  return 0;
}