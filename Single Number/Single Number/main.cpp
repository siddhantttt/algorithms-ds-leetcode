//Problem: https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1176/
//Implementation: Suboptimal, try using no extra space.


#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_set<int> s;
        for (int i: nums){
            if (s.count(i))
                s.erase(i);
            
            else
                s.insert(i);
        }
        
        unordered_set<int>::iterator it;
        
        it = s.begin();
        
        
        return *it;
    }
};




int main(){
    vector<int> nums{2, 2, 1, 1, 3};
    cout <<Solution().singleNumber(nums);
    return 0;
}
