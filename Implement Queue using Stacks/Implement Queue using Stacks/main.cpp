//
//  main.cpp
//  Implement Queue using Stacks
//
//  Created by Siddhant on 4/15/19.
//  Copyright © 2019 Stack. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>


using namespace std;

class MyQueue {
public:
    stack <int> s1;
    stack <int> s2;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        int temp;
        
        while (!s1.empty()){
            temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        
        s1.push(x);
        
        while (!s2.empty()){
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

int main(int argc, const char * argv[]) {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
     cout << obj->peek();
    cout << obj->pop();
    //cout << obj->empty();
//    int param_2 = obj->pop();
//    int param_3 = obj->peek();
//    bool param_4 = obj->empty();
}
