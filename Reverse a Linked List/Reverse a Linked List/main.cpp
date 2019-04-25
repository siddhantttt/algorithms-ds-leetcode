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
    ListNode* reverseList(ListNode* head) {
        
        if (!head)
            return NULL;
        
        ListNode* prev = NULL, *curr = head, *next;
        
        while (curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};
    
    
    
    
int main(){
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
        
    head->next = NULL;
    node1->next = NULL;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = NULL;
    
    ListNode* h = Solution().reverseList(head);
    cout << endl;
    
    return 0;
}
