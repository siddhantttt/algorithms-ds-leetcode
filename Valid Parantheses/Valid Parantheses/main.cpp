//Ref: https://leetcode.com/explore/learn/card/queue-stack/230/usage-stack/1361/


#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    
    stack <int> p;
    
    bool isValid(string s) {
        for (char c: s){
            
            if (p.empty()){
                if (c == '(' || c == '{' || c == '['){
                    p.push(c);
                    continue;
                }
                else
                    return false;
            }
            if (!p.empty() && p.top() == '{'){
                if (c == ')' || c == ']')
                    return false;
                else if (c == '}')
                    p.pop();
                else
                    p.push(c);
            }
            
            else if (!p.empty() && p.top() == '['){
                if (c == '}' || c == ')')
                    return false;
                else if (c == ']')
                    p.pop();
                else
                    p.push(c);
            }
            
            else {
                if (c == ']' || c == '}')
                    return false;
                else if (c == ')')
                    p.pop();
                else
                    p.push(c);
            }
        }
        
        
        if (!p.empty() && (p.top() == '{' || p.top() == '[' || p.top() == '('))
            return false;
        
        return true;
        
    }
};





int main(int argc, const char * argv[]) {
    
    string s = "))))";
    Solution sol = Solution();
    
    cout << sol.isValid(s);

}
