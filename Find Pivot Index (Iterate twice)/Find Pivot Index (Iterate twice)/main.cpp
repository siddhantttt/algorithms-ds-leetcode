#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int pivot = -1, sum = 0, sumSoFar = 0;
        
        for (int i: nums)
            sum += i;
        
        
        for (int i = 0; i < nums.size(); i++){
            
            int sumWithoutCurr = sum - nums[i];
            
            if (sumWithoutCurr%2 != 0){
                sumSoFar += nums[i];
                continue;
            }
            
            else if (sumSoFar == sumWithoutCurr/2){
                return i;
            }
            sumSoFar += nums[i];
        }
        return pivot;
    }
};




int main(){
    
    vector<int> nums{1, 3, 4, 3, 1};
    cout << Solution().pivotIndex(nums);
    return 0;
}
