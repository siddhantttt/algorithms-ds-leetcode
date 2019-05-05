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
private:
    
    string getHash(string s){
        sort(s.begin(), s.end());
        cout << s;
        
        return s;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> m;
        unordered_map<string, vector<int>>::iterator it;
        vector<vector<string>> res;
        
        for (int i = 0; i<strs.size(); i++)
            m[getHash(strs[i])].push_back(i);
        
        vector<string> inner;
        for (it = m.begin(); it != m.end(); it++){
            inner.clear();
            for (int i: it->second)
                inner.push_back(strs[i]);
            res.push_back(inner);
        }
        return res;
    }
};




int main(){
    
    vector<string> s{"eat", "tea", "tan", "ate", "nat", "bat"};
    
    Solution().groupAnagrams(s);
    
    return 0;
}
