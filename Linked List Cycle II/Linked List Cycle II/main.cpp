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
    
    ListNode* findCycle(ListNode* pos, ListNode*  head){
        
        ListNode* start = head;
        
        while (start != pos){
            pos = pos->next;
            start = start->next;
        }
        return NULL;
    }
    
    
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* fast = head;
        ListNode* slow = head->next;
        while (slow && fast && fast->next){
            if (slow == fast)
                return findCycle(slow, head);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        return NULL;
        
    }
};
    
    
    
    
    int main(){
        
        ListNode* head = new ListNode(1);
        ListNode* node1 = new ListNode(2);
        ListNode* node2 = new ListNode(3);
        ListNode* node3 = new ListNode(4);
        
        head->next = node1;
        node1->next = node2;
        node2->next = node3;
        node3->next = node2;
        
        Solution().detectCycle(head);
        return 0;
        
        
        
        
        
        
    }
