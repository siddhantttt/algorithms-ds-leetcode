#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++){
            if (m.find(nums[i]) != m.end() and abs(m[i] - i) <=k)
                return true;
            else
                m[nums[i]] = i;
        }
        return false;
    }
};




int main(){
    return 0;
}
