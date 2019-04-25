//Problem: https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1295/


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
    ListNode* rotateRight(ListNode* head, int k) {
        /*
         
         Code is not clean. However, it is correct.
         Method to be followed:
         1. Connect the tail to the head.
         2. Find the point and which there should be a break, i. e where the
         new head should start from.
         
         Edge cases:
         1. When rotations are zero
         2. When head is only one node.
         
         */
        
        if (!head || !head->next || k == 0)
            return head;
        
        
        ListNode* temp = head;
        ListNode *fast = head;
        
        int length = 0, rotations, breakPoint;
        
        while (temp){
            temp = temp->next;
            length++;
        }
        
        rotations = k%length;
        
        if (!rotations)
            return head;
        
        
        breakPoint = length - rotations;
        
        while (--breakPoint)
            fast = fast->next;
        
        ListNode* newHead = fast->next;
        fast->next = NULL;
        
        ListNode* node = newHead;
        
        while (node->next)
            node = node->next;
        
        node->next = head;
        return newHead;
        
    }
};
    
    int main(){
        ListNode* head = new ListNode(1);
//        ListNode* node1 = new ListNode(2);
//        ListNode* node2 = new ListNode(3);
//        ListNode* node3 = new ListNode(4);
//        ListNode* node4 = new ListNode(5);
        
//        head->next = node1;
//        node1->next = node2;
//        node2->next = node3;
//        node3->next = node4;
//        node4->next = NULL;
        
        Solution().rotateRight(head, 5);
        
        return 0;
    }
