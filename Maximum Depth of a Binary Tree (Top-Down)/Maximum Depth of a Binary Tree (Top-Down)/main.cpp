//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/535/
//


#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
    
private:
    int ans;
public:
    
    Solution (){
        ans = 0;
    }
    
    void maxDepthHelper(TreeNode* root, int depth){
        if (root == NULL){
            ans = depth > ans? depth: ans;
            return;
        }
        
        maxDepthHelper(root->left, depth+1);
        maxDepthHelper(root->right, depth+1);
        
    }
    
    int maxDepth(TreeNode* root) {
        maxDepthHelper(root, 0);
        return ans;
    }
};



int main(){
    
    TreeNode* root = new TreeNode;
    TreeNode* node1 = new TreeNode;
    TreeNode* node2 = new TreeNode;
    TreeNode* node3 = new TreeNode;
    TreeNode* node4 = new TreeNode;
    
    root->val = 3;
    root->right = node2;
    root->left = node1;
    
    node1->val = 9;
    node1->right = NULL;
    node1->left = NULL;
    
    node2->val = 20;
    node2->right = node3;
    node2->left = node4;
    
    node4->val = 15;
    node4->right = NULL;
    node4->left = NULL;
    
    node3->val = 7;
    node3->right = NULL;
    node3->left = NULL;
    
    cout << Solution().maxDepth(root);
}
