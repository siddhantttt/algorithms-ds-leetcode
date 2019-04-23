//Problem: https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1214/

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        
        ListNode* i = head->next->next;
        ListNode* j = head->next;
        
        while (j != NULL && i != NULL){
            
            if (j == i)
                return true;
            
            j = j->next;
            if (i->next)
                i = i->next->next;
        }
        
        
        return false;
    }
};
    
    
    
    
int main(){
    return 0;
}
