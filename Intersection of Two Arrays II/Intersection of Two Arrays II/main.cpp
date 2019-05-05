//https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1178/
//Basic Solution


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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> m;
        vector<int> res;
        
        for (int i: nums2)
            m[i]++;
        
        
        for (int i: nums1){
            
            if (m.find(i) != m.end() && m[i] > 0){
                res.push_back(i);
                m[i]--;
            }
        }
        return res;
    }
};




int main(){
    
    vector <int> nums{1,2,2,1};
    vector<int> nums2{2,2};
    
    Solution().intersect(nums, nums2);
    return 0;
}
