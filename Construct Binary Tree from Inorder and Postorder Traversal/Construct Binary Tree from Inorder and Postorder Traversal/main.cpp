//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/942/
//Implementation: This implementation is infact the correct one. However, it is inefficient. There
//exist more efficient implementations.
//Refer: https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/


#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTreeHelper(vector<int> inorder, vector<int>postorder, int postpos, int inlpos, int inrpos){
        
        if (inlpos > inrpos)
            return NULL;
        
        if (inlpos == inrpos){
            TreeNode* root = new TreeNode(inorder[inlpos]);
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        int rootElement = postorder[postpos], elementPos;
        for (int i = inlpos; i <= inrpos; i++){
            if (inorder[i] == rootElement)
                elementPos = i;
        }
        TreeNode* root = new TreeNode(postorder[postpos]);
        root->right = buildTreeHelper(inorder, postorder, postpos-1, elementPos+1, inrpos);
        root->left = buildTreeHelper(inorder, postorder, postpos-1, inlpos, elementPos-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        return buildTreeHelper(inorder, postorder, postorder.size()-1, 0, inorder.size()-1);
    }
};




int main(){
    vector<int> inorder{9,3,15,20,7}, postorder{9,15,7,20,3};
    TreeNode* node = Solution().buildTree(inorder, postorder);
    return 0;
}
