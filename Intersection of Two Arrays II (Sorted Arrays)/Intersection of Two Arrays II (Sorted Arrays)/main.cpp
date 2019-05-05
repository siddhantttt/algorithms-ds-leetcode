//Problem: https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1178/
//Modificaiton: arrays are sorted
//Solution: Optimal
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
        
        int i = 0, j = 0;
        vector<int> res;
        
        while (i < nums1.size() && j < nums2.size()){
            
            if (nums1[i] > nums2[j])
                j++;
            
            else if (nums2[j] > nums1[i])
                i++;
            
            else {
                res.push_back(nums1[i]);
                j++;
                i++;
            }
            
        }
        return res;
        
    }
};




int main(){
    
    vector<int> nums1{1, 2, 2, 3};
    vector<int> nums2{2, 2,};
    Solution().intersect(nums1, nums2);
    
    return 0;
}
