#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;


class MyStack {
public:
    /** Initialize your data structure here. */
    
    queue<int> q;
    
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        
        while (q.front() != x){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
        
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};



int main(){
    
    MyStack* obj = new MyStack;
    obj->push(1);
    obj->push(2);
    cout << obj->top();
    cout << obj->pop();
    cout << obj->empty();
}
