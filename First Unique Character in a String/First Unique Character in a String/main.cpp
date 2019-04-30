#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        
        
        unordered_set<string, int> m;
        
        for (auto i = 0; i < s.length(); i++){
            
            if (m.find(s[i] != m.end())
                return i;
            
            
        }
        
        
    }
};





int main(){
    return 0;
}
