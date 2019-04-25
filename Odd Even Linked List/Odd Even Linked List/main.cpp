//Problem: https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1208/
//Review Implementation once.


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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return head;
        
        if (!head->next)
            return head;
        
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        
        ListNode* head2 = node2;
        
        while (node1->next->next && node2->next->next){
            node1->next = node1->next->next;
            node2->next = node2->next->next;
            
            node1 = node1->next;
            node2 = node2->next;
        }
        
        if (node1->next && node1->next->next){
            node1->next = node1->next->next;
            node1 = node1->next;
        }
            
        if (node2->next)
            node2->next = node2->next->next;
        
        node1->next = head2;
        
        return head;
    }
};
    
    
    
    
    int main(){
        ListNode* head = new ListNode(1);
        ListNode* node1 = new ListNode(2);
        ListNode* node2 = new ListNode(3);
        ListNode* node3 = new ListNode(4);
        ListNode* node4 = new ListNode(5);
        ListNode* node5 = new ListNode(6);
        
        head->next = node1;
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;
        node5->next = NULL;
        
        
        Solution().oddEvenList(head);
        cout << "Something";
        
        
        return 0;
    }
