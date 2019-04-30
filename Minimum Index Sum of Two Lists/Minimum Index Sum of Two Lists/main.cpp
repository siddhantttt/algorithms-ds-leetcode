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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        unordered_map<string, int> m;
        unordered_set<string> s;
        vector<string> res;
        
        int minSum = INT_MAX;
        
        for (int i = 0; i < list1.size(); i++)
            m.insert(make_pair(list1[i], i));
        
        
        for (int i = 0; i < list2.size(); i++){
            
            if (m.find(list2[i]) == m.end())
                continue;
            
            else {
                m.at(list2[i]) += i;
                if (m.at(list2[i]) == minSum){
                    res.push_back(list2[i]);
                }
                
                else if (m.at(list2[i]) < minSum){
                    res.clear();
                    res.push_back(list2[i]);
                    minSum = m.at(list2[i]);
                    
                }
                
            }
                
        }
        
        
        return res;
        
    }
};




int main(){
    
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"KFC", "Shogun", "Burger King"};
    
    
    auto res = Solution().findRestaurant(list1, list2);
    
    return 0;
}
