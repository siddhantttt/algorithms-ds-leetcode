//Problem: Top K Frequentest Elements (Leetcode)
// Implementation: Wrong and Incomplete

#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> m;
        map<int, int> reverse;
        vector<int> res;
        
        for (int i: nums){
            
            if (m.find(i) != m.end())
                m.at(i) += 1;
            
            else
                m.insert(make_pair(i, 1));
        }
        unordered_map<int, int>::iterator it = m.begin();
        for (; it != m.end(); it++)
            reverse.insert(make_pair(it->second, it->first));
        map<int, int>::iterator itReverse = reverse.begin();
        
        while (k-- && itReverse != reverse.end())
            res.push_back(itReverse->second);
        
        return res;
    }
};




int main(){
    vector<int> nums{4, 4, 5, 1, 2, 3};
    Solution().topKFrequent(nums, 1);
    return 0;
}

