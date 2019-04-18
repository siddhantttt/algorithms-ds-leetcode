#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    
    stack<int> s;
    stack<int> minStack;
    
    void push(int x) {
        
        if (s.empty()){
            s.push(x);
            minStack.push(x);
        }

        else if (!s.empty() && minStack.top() >= x){
            s.push(x);
            minStack.push(x);
            }

        else {
            s.push(x);
            minStack.push(minStack.top());
        }
    }
    
    void pop() {
        s.pop();
        minStack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};



int main(){
    MinStack* obj = new MinStack();
    obj->push(-2);
    cout << obj->getMin();
    obj->push(0);
    cout << obj->getMin();
    obj->push(-3);
    cout << obj->getMin();
    
    
    return 0;
}
