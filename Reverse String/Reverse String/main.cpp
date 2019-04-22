#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    void swap(char &a, char &b){
        char temp = a;
        a = b;
        b = temp;
    }
    
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        
        while (i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
 



int main(){
    vector<char> a{'a', 'b', 'c'};
    Solution().reverseString(a);
}
