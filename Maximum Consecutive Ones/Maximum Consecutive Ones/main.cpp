//Problem: https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1301/


#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;



class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxConsec = 0, sum = 0;
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1){
                sum ++;
                maxConsec = max(maxConsec, sum);
            }
            
            else
                sum = 0;
        }
        
        return maxConsec;
    }
};




int main(){
    vector<int> nums {1, 1, 0, 0, 1};
    cout << Solution().findMaxConsecutiveOnes(nums);
}
