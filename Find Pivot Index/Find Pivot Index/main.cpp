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
        int pivot = -1;
        
        int leftIndex = 0, rightIndex = nums.size()-1, leftSum = 0, rightSum = 0;
        
        leftSum = nums[leftIndex];
        rightSum = nums[rightIndex];
        
        while (leftIndex < rightIndex-1){
            if (leftSum + nums[leftIndex+1] <= rightSum)
                leftSum += nums[++leftIndex];
            
            else if (rightSum + nums[rightIndex-1] <= leftSum)
                rightSum += nums[--rightIndex];
            
            else if (leftIndex + 2 == rightIndex)
                break;
            
            else
                return -1;
            
        }
        
        if (leftSum == rightSum)
            pivot = leftIndex + 1;
        
        return pivot;
    }
};




int main(){
    
    vector<int> nums{1,7,3,6,5,6};
    cout << Solution().pivotIndex(nums);
    return 0;
}
