//Problem: https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1299/
//Implementation: This is a sliding window implementation. Much better implementations exist.

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
        if (nums.size() == 0)
            return 0;
        for (int ws = 1; ws <= nums.size(); ws++){
            
            int sum = 0;
            for (int i = 0; i < ws; i++)
                sum += nums[i];
            
            if (sum >= s)
                return ws;
            
            for (int j = ws; j < nums.size(); j++){
                sum -= nums[j-ws];
                sum += nums[j];
                
                if (sum >= s)
                    return ws;
            }
        }
        
        return 0;
    }
};


int main(){
    vector<int>s{1,2,3,4,5};
    cout << Solution().minSubArrayLen(15, s);
}

