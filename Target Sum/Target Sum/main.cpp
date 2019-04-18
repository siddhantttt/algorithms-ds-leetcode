#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWaysHelper(vector<int>& nums, int S, int i, int sum){
        if (i == nums.size()) return sum==S;
        
        int addResult = findTargetSumWaysHelper(nums, S, i+1, sum+nums[i]);
        int subResult = findTargetSumWaysHelper(nums, S, i+1, sum-nums[i]);

        return addResult + subResult;
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWaysHelper(nums, S, 0, 0);
    }
};



int main(){
    
    vector<int> nums = {1, 1, 1, 1, 1};
    int S = 3;
    cout << Solution().findTargetSumWays(nums, S);
}
