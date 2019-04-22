//This is an Implementation of KMP Algorithm.
// Video: https://www.youtube.com/watch?v=V5-7GzOfADQ
//Giving Heap buffer overflow on Leetcode :\

#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

class KMPAlgorithm {
public:
    
    vector<int> computeLPSArray(string pattern){
        vector<int> LPS;
        
        if (!pattern.length())
            return LPS;
        
        LPS.push_back(0);
    
        for (auto j = 1; j<pattern.length(); j++){
            
            if (pattern[LPS[j-1]] == pattern[j])
                LPS.push_back(LPS[j-1] + 1);
            else
                LPS.push_back(0);
        }
        return LPS;
    }
    
    int find(string str, string pattern){
        
        vector<int> LPS = computeLPSArray(pattern);
        int i = 0, j = 0;
        while (i<str.length() && j<pattern.length()){
            
            if (str[i] == pattern[j]){
                i++;
                j++;
            }
            
            else if(str[i] != pattern[i] && j == 0)
                i++;
            
            else
                j = LPS[j-1];
        }
        int resp =  j == pattern.length()? i-j: -1;
        return resp;
    }
};




int main(){
    cout << KMPAlgorithm().find( "aaaaa", "bba");
    
}

