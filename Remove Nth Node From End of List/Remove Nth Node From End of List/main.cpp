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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        
        if (!head)
            return head;
        
        ListNode* back = head;
        ListNode* front = head;
        
        
        while(n--){
            if (front == NULL)
                return head;
            front = front->next;
        }
        
        if (front == NULL){
            head = back->next;
            return head;
        }
        
        while (front->next != NULL){
            back = back->next;
            front = front->next;
        }
        
        ListNode* temp;
        
        temp = back->next;
        back->next = temp->next;
        temp->next = NULL;
        return head;
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
    node3->next = NULL;
    node4->next = NULL;
    
    Solution().removeNthFromEnd(head, 2);
    cout << " ";
    return 0;
    }
