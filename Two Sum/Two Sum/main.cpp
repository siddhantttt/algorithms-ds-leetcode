#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
//Problem: https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1115/
// Implementation: Correct!

#include <unordered_map>

using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++){
            if (m.find(target-nums[i]) != m.end()){
                res.push_back(m.at(target-nums[i]));
                res.push_back(i);
                return res;
            }
            
            else
                m.insert(make_pair(nums[i], i));
        }
        
        return res;
    }
};

int main(){
    
    vector<int> nums {2, 7, 11, 15};
    Solution().twoSum(nums, 9);
}
