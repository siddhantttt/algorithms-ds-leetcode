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
        unordered_map<char, int> m;
        
        
        for (char c: s){
            if (m.find(c) != m.end())
                m[c]++;
            else
                m.insert(make_pair(c, 1));
        }
        
        
        
        for (int i = 0; i < s.length(); i++){
            if (m[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};





int main(){
    return 0;
}
