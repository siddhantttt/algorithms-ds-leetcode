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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(INT_MIN);
        
        ListNode* tail = dummy;
        
        while (l1 && l2){
            if (l1->val < l2->val){
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }
            
            else {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }
        
        tail->next = l1? l1: l2;
        
        return dummy->next;
    }
};
    
    
    int main(){
        ListNode* head = new ListNode(1);
        ListNode* node1 = new ListNode(2);
        ListNode* node2 = new ListNode(3);
        ListNode* node3 = new ListNode(4);
        ListNode* node4 = new ListNode(5);
        ListNode* node5 = new ListNode(6);
        ListNode* head2 = new ListNode(7);
        
        head->next = node1;
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = NULL;
        head2->next = node5;
        node5->next = NULL;
        
        Solution().mergeTwoLists(head, head2);
        return 0;
    }
