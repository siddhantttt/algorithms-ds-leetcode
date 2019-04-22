#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int digitIndex = digits.size()-1, carry=1;
        
        while (digitIndex >= 0){
            int sum = digits[digitIndex] + carry;
            carry = sum/10;
            digits[digitIndex] = sum%10;
            
            digitIndex--;
        }
        
        if (carry == 1){
            
            vector<int> newDigits;
            newDigits.push_back(1);
            for (int i = 0; i<digits.size(); i++)
                newDigits.push_back(0);
            
            return newDigits;
        }
        
        return digits;
        
    }
};




int main(){
    vector<int> nums{9, 9, 9};
    Solution().plusOne(nums);
    return 0;
}

