//Problem: https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1161/
//Instead of using STL Function, Implement the Data Structure.
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int a = haystack.find(needle);
        if (a == INT_MAX)
            return -1;
        else return a;
    }
};




int main(){
//    cout << INT_MAX;
    cout << Solution().strStr("aaaaa", "avb");
    return 0;
}
