//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/537/

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
    int sum;
public:
    
    bool hasPathSumHelper(TreeNode* root, int currSum){
        if (root == NULL)
            return false;
        
        if (root->val + currSum == sum && root->left == NULL && root->right == NULL)
            return true;
        
        bool leftCheck = hasPathSumHelper(root->left, currSum + root->val);
        bool rightCheck = hasPathSumHelper(root->right, currSum + root->val);
        
        return leftCheck || rightCheck;
        
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        this->sum = sum;
        return hasPathSumHelper(root, 0);
    }
};


int main(){
    
    TreeNode* root = new TreeNode;
    TreeNode* node1 = new TreeNode;
    TreeNode* node2 = new TreeNode;
    TreeNode* node3 = new TreeNode;
    TreeNode* node4 = new TreeNode;
    
    root->val = -2;
    root->right = node1;
    root->left = NULL;
    
    node1->val = -3;
    node1->right = NULL;
    node1->left = NULL;
    
//    node2->val = 20;
//    node2->right = node3;
//    node2->left = node4;
//
//    node4->val = 15;
//    node4->right = NULL;
//    node4->left = NULL;
//
//    node3->val = 7;
//    node3->right = NULL;
//    node3->left = NULL;
    
    cout << Solution().hasPathSum(root, -5 );
}

