//Problem: https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1151/



#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        
        for (int j = 0; j<nums.size(); j++){
            if (nums[i] != nums[j]){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};




int main(){
    return 0;
}
