//Problem:

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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s;
        unordered_set<int> s2;
        vector<int> intersection;
        
        for (int i: nums2)
            s.insert(i);
        
        for (int i: nums1){
            if (s.count(i)){
                if (s2.count(i)){
                    continue;
                }
                
                intersection.push_back(i);
                s2.insert(i);
            }
        }
            
            
        return intersection;
    }
};



int main(){
    return 0;
}
