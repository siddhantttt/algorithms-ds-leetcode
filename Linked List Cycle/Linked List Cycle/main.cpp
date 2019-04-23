
#include <vector>
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
        unordered_set<ListNode*> s;
        
        while (head != NULL){
            if (s.find(head) == s.end()){
                s.insert(head);
                head = head->next;
            }
            
            else
                return true;
        }
        return false;
    }
};




int main(){
    return 0;
}
