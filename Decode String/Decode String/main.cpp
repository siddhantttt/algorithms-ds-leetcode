//Problem: https://leetcode.com/problems/decode-string/
//Implementation: Doesn't work for tens digits, works fine for ones :)


#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    stack<char> st;
    
    string concatenateString(string intermediate, int num){
//        reverse(intermediate.begin(), intermediate.end());
        string res;
        
        for (int i = 0; i<num; i++)
            res += intermediate;
        
        return res;
    }
    
    
    string decodeString(string s) {
        
        string intermediate, res;
//        st.push(s[0]);
//        int i = 1;
        
        for (int i = 0; i < s.length()-1; i++){
            
            st.push(s[i++]);
            
            while(!st.empty()){
                
                while(s[i] != ']')
                    st.push(s[i++]);
                
                while(st.top() != '['){
                    intermediate += st.top();
                    st.pop();
                }
                
                st.pop();
                int num = st.top()-'0';
                st.pop();
                intermediate = concatenateString(intermediate, num);
            }
            reverse(intermediate.begin(), intermediate.end());
            res += intermediate;
            intermediate.clear();
        }
        return res;
    }
};




int main(){
    string s= "3[a2[bc]]";
    cout << Solution().decodeString(s);
}
