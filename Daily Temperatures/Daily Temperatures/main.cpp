//Explanation: https://medium.com/@ashleywang.ads/leetcode-739-daily-temperatures-aced04f3fdb1
//Problem: https://leetcode.com/explore/learn/card/queue-stack/230/usage-stack/1363/
//TODO: Not Completed



#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        stack<int> s;
        vector<int> res;
        int popCount = 0;
        
        s.push(T[0]);
        
        for (int i = 1; i< T.size(); i++){
            
            while (!s.empty() && T[i] > s.top()){
                popCount++;
                res.push_back(popCount);
                s.pop();
            }
            
            s.push(T[i]);
            popCount = 0;
        }
        
        return res;
        
    }
};


int main(){
    
    vector<int> T{73,74,75,71,69,72,76,73};
    
    Solution solution = Solution();
    solution.dailyTemperatures(T);
    
}
