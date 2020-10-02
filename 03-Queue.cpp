#include <iostream>

using namespace std;

class queue {
private:
    int *pIntQueue;
    int size;
    int first;
    int last;
    int counter;

public:
    // CONSTRUCTOR
    queue(int queSize) {
        size = queSize;
        first = last = counter = 0;
        pIntQueue = new int[size];
    }

    // CONSTRUCTOR With default value 10
    queue(void) {
        size = 10;
        first = last = counter = 0;
        pIntQueue = new int[size];
    }

    // ENEQUE
    void enqueue(int data) {
        counter++;
        pIntQueue[last] = data;
        last = (last + 1) % size;
    }

    // DEQUE
    int deque(void) {
        int temp = pIntQueue[first];
        counter--;
        first = (first + 1) % size;
        return temp;

    }

    // IS FULL
    bool isFull(void) {
        if (counter == size) return true;
        else return false;

    }

    // IS Empty
    bool isEmpty(void) {
        if (counter == 0) return true;
        else return false;
    }

    // GET Counter
    bool getCount(void) {
        return counter;
    }

    // Get Front
    int getFront(void) {
        return pIntQueue[first];

    }

    // CLEAR
    void clear(void) {
        first = last = counter = 0;
    }

};

int main() {

    queue myque(6);

    int input;

    for (input = 1; input <= 4; input++) {
        if (myque.isFull() == false) {
            myque.enqueue(input * input);
        }
    }


    while (myque.isEmpty() == false) {
        cout << myque.deque() << "\t";
    }


    for (input = 10; input <= 20; input++) {
        if (myque.isFull() == false) {
            myque.enqueue(input * input);
        }
    }


    while (myque.isEmpty() == false) {
        cout << myque.deque() << "\t";

    }
    return 0;


}

// implementing queue using 2 stack
#include <bits/stdc++.h> 
using namespace std; 
  
struct Queue { 
    stack<int> s1, s2; 
  
    void enQueue(int x) 
    { 
        // Move all elements from s1 to s2 
        while (!s1.empty()) { 
            s2.push(s1.top()); 
            s1.pop(); 
        } 
  
        // Push item into s1 
        s1.push(x); 
  
        // Push everything back to s1 
        while (!s2.empty()) { 
            s1.push(s2.top()); 
            s2.pop(); 
        } 
    } 
  
    // Dequeue an item from the queue 
    int deQueue() 
    { 
        
        if (s1.empty()) { 
            cout << "Q is Empty"; 
            exit(0); 
        } 
  
        
        int x = s1.top(); 
        s1.pop(); 
        return x; 
    } 
}; 
  
 
int main() 
{ 
    Queue q; 
    q.enQueue(1); 
    q.enQueue(2); 
    q.enQueue(3); 
  
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
  
    return 0; 
} 


