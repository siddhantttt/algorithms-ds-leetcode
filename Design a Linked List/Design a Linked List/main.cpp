//Problem: https://leetcode.com/explore/learn/card/linked-list/209/singly-linked-list/1290/
//Implementation: Incomplete, giving runtime error.


#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;


struct Node {
    int val;
    Node *next;
    Node (int x): val(x), next(NULL) {}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    
    Node* head;
    int length;
    
    MyLinkedList() {
        head = NULL;
        length = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (head == NULL)
            return -1;
        
        if (index >= length)
            return -1;
        
        Node* temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        if (head == NULL)
            head = node;
        
        else {
            node->next = head;
            head = node;
        }
        
        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        if (head == NULL){
            head = node;
            length++;
            return;
        }
        
        Node* curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        
        curr->next = node;
        length++;
            
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > length)
            return;
        
        else if (index == length){
            addAtTail(val);
            return;
        }
        
        Node* temp = head;
        Node* node = new Node(val);
        for (int i = 1; i < index; i++)
            temp = temp->next;
        
        node->next = temp->next;
        temp->next = node;
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (head == NULL)
            return;
        
        if (index == 0){
            head = NULL;
            return;
        }
        
        Node* curr = head;
        
        for (int i = 1; i<index; i++)
            curr = curr->next;
        
        Node* temp = curr->next;
        curr->next = temp->next;
        
        temp->next = NULL;
    }
};




int main(){
    MyLinkedList* linkedList = new MyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1, 2);
    cout << linkedList->get(1);
    linkedList->deleteAtIndex(1);
    cout << linkedList->get(1);
    return 0;
    
}

