//Implementation : https://leetcode.com/problems/search-in-rotated-sorted-array/



#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    
    int pivot;
    void setPivot(vector<int> nums){
        pivot = 0;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] < nums[i-1]){
                this->pivot = i;
                break;
            }
        }
    }
    
    
    int searchHelper(vector<int> nums, int target, int i, int j){
        int I, J, MID, mid;
        
        if (i > j)
            return -1;
        
        I = (i+pivot)%nums.size();
        J = (j+pivot)%nums.size();
        
        mid = (i+j)/2;
        MID = (mid+pivot)%nums.size();
        
        if (nums[MID] == target)
            return MID;
        
        
        if (nums[MID] > target)
            j = mid-1;
        
        if (nums[MID] < target)
            i = mid+1;
        
        
        return searchHelper(nums, target, i, j);
        
    }
    
    int search(vector<int>& nums, int target) {
        setPivot(nums);
        return searchHelper(nums, target, 0, nums.size()-1);
    }
};




int main(){
    
    vector<int> nums{4,5,6,7,0,1,2};
    cout << Solution().search(nums, 2);
    return 0;
}
