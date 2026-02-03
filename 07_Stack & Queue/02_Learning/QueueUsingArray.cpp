#include <iostream>
#include <vector>

using namespace std;

// class Queue
// {

//   vector<int> queue;
//   int frontIndex = 0;

// public:
//   void push(int data)
//   {
//     queue.push_back(data);
//   }

//   void pop()
//   {
//     if (empty())
//     {
//       cout << "Queue Empty";
//       return;
//     }
//     frontIndex++;
//   }

//   int front()
//   {
//     if (empty())
//     {
//       cout << "Queue Empty";
//       return -1;
//     }
//     return queue[frontIndex];
//   }

//   int size()
//   {
//     return queue.size() - frontIndex;
//   }

//   bool empty()
//   {
//     return frontIndex >= queue.size();
//   }
// };


class ArrayQueue {
  int size;
  int *queue;
  int front;
  int rear;
  int totalElement;


public:
    ArrayQueue() {
      this->size = 100;
      queue = new int[size];
      front = 0;
      rear = 0;
      totalElement = 0;
    }
    
    void push(int x) {
      if(totalElement == size) return;

      queue[rear] = x;

      rear = (rear + 1) % size;
      totalElement++;      
    }
    
    int pop() {
      if(isEmpty()) return -1;

      int x = queue[front];
      front = (front + 1) % size;
      totalElement--;
      return x;
    }
    
    int peek() {
      if(isEmpty()) return -1;
      return queue[front];
    }
    
    bool isEmpty() {
      return totalElement = 0;
    }

    ~ArrayQueue()
    {
      delete[] queue;
    }
};


int main()
{
  return 0;
}