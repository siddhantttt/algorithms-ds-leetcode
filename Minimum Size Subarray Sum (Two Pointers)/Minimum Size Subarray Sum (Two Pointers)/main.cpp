//Problem: https://leetcode.com/problems/minimum-size-subarray-sum/
//Implementation: This is a O(N) implentation
//Extremely Important Problem


#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = INT_MAX, left = 0, sum = 0;
        for (int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum >= s){
                minLen = min(minLen, right-left+1);
                sum -= nums[left++];
            }
        }
        return minLen == INT_MAX? 0: minLen;
    }
};




int main(){
    vector<int> nums{2,3,1,2,4,3};
    cout << Solution().minSubArrayLen(7, nums);
    return 0;
}

