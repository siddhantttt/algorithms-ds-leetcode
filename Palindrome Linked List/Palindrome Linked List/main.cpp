//Problem: https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1209/
//Implementation: Incomplete. Use fast and slow pointers instead of length.

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
    bool isPalindrome(ListNode* head) {
        
        if (!head)
            return true;

        if (!head->next)
            return true;

        ListNode* node = head;
        int length = 0;
        while (node){
            node = node->next;
            length++;
        }

        ListNode *left = head, *right = head;
        int leftCounter, rightCounter = 0;
        
        if (length%2 != 0){
            leftCounter = length/2-1;
            rightCounter = length/2+1;
        }
        
        else {
            leftCounter = length/2-1;
            rightCounter = length/2;
        }
        
        for (int i = rightCounter; i < length; i++)
            right = right->next;
            

        //Reverse first part
        ListNode *curr = head, *prev = NULL, *next = curr->next;
        
        
        while (curr->next!= NULL && leftCounter--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        curr->next = prev;
        
        while (curr && right){
            if (curr->val != right->val)
                return false;
            
            curr = curr->next;
            right = right->next;
        }
        
        return true;
        
        
    }
};
    
    
    int main(){
        ListNode* head = new ListNode(1);
        ListNode* node1 = new ListNode(2);
        ListNode* node2 = new ListNode(3);
        ListNode* node3 = new ListNode(2);
        ListNode* node4 = new ListNode(1);
        
        head->next = node1;
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = NULL;
        
        cout << Solution().isPalindrome(head);
        
        return 0;
    }
