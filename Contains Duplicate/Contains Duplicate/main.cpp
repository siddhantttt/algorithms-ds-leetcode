#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for (int i: nums){
            if (s.count(i))
                return true;
            
            s.insert(i);
        }
        
        return false;
    }
};




int main(){
    
    vector<int> nums{1, 2, 3, 1};
    cout << Solution().containsDuplicate(nums);
    
    return 0;
}


