#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int largestElement = -1, secondLargestElement = -1, largestElemIndex = -1;
        
        for (int i = 0; i<nums.size(); i++){
            if (nums[i]>largestElement){
                largestElement = nums[i];
                largestElemIndex = i;
            }
        }
        
        for (int i: nums){
            if (i > secondLargestElement && i != largestElement)
                secondLargestElement = i;
        }
        
        return largestElement >= 2*secondLargestElement? largestElemIndex: -1;
        
    }
};




int main(){
    vector<int> nums{1, 2, 2, 4};
    cout << Solution().dominantIndex(nums);
    return 0;
}

