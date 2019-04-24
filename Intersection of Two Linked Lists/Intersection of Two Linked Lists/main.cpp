//Problem: https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1215/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (!headA || !headB)
            return NULL;
        
        ListNode *nodeA = headA, *nodeB = headB;
        int lengthA = 0, lengthB = 0;
        
        while (nodeA->next != NULL){
            nodeA = nodeA->next;
            lengthA++;
        }
        
        while (nodeB->next != NULL){
            nodeB = nodeB->next;
            lengthB++;
        }
        
        if (nodeB != nodeA)
            return NULL;
        
        
        nodeA = headA;
        nodeB = headB;
        if (lengthA > lengthB){
            int diff = lengthA - lengthB;
            while (diff--)
                nodeA = nodeA->next;
        }
        
        else if (lengthB > lengthA){
            int diff = lengthB - lengthA;
            while (diff--)
                nodeB = nodeB->next;
        }
        
        while (nodeB != nodeA){
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        
        return nodeA;
    }
};
    
    
    
    int main(){
        
        ListNode* head = new ListNode(1);
        ListNode* node1 = new ListNode(2);
        ListNode* node2 = new ListNode(3);
        ListNode* node3 = new ListNode(4);
        ListNode* node4 = new ListNode(5);
        
        head->next = node1;
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = NULL;
        
        
        Solution().getIntersectionNode(head, head2);
    }
