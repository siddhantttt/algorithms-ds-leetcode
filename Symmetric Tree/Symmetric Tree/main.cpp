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
public:
    
    bool isMirror(TreeNode* one, TreeNode* two){
        if (one == NULL && two == NULL)
            return true;
        else if (one == NULL || two == NULL)
            return false;
        
        bool leftResult = isMirror(one->left, two->right);
        bool rightResult = isMirror(one->right, two->left);
        
        return leftResult && rightResult && (one->val == two->val);
    }
    bool isSymmetric (TreeNode* root){
        
        if (root == NULL)
            return true;
        else
            return isMirror(root->left, root->right);
    }
};



int main(){
    
    TreeNode* root = new TreeNode;
    TreeNode* node1 = new TreeNode;
    TreeNode* node2 = new TreeNode;
    TreeNode* node3 = new TreeNode;
    TreeNode* node4 = new TreeNode;
    
    root->val = 1;
    root->right = node2;
    root->left = node1;
    
    node1->val = 2;
    node1->right = NULL;
    node1->left = NULL;
    
    node2->val = 2;
    node2->right = NULL;
    node2->left = NULL;
    
//    node4->val = 3;
//    node4->right = NULL;
//    node4->left = NULL;
//
//    node3->val = 4;
//    node3->right = NULL;
//    node3->left = NULL;
    
    cout << Solution().isSymmetric(root);
}
