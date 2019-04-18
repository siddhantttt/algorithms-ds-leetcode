//
//  main.cpp
//  Evaluate Reverse Polish Notation
//
//  Created by Siddhant on 4/11/19.
//  Copyright © 2019 Stack. All rights reserved.
//
#include <iostream>
#include <stack>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    
    stack<int> st;
    int evalRPN(vector<string>& tokens){
        for (string s: tokens){
            if (s[0] == '+'){
//                cout << "here";
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first + second);
//                cout << st.top();
            }
            
            else if (s[0] == '-' && s.length() == 1){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second-first);
            }
            else if (s[0] == '*'){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first * second);
            }
            
            else if (s[0] == '/'){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second/first);
            }
            
            else {
                int num = stoi(s);
                st.push(num);
                cout << num << endl;
//                cout << "here";
            }
//            cout << s << " ";
//            cout << st.top() << endl;
            cout << "Something";
        }
        if (st.empty()) {
            return 0;
        }
        else return st.top();
    }
};

int main(){
    Solution sol = Solution();
    vector<string> s{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};//"/","*","17","+","5","+"};
    cout << sol.evalRPN(s);
//    cout << stoi("-11");
    
}
