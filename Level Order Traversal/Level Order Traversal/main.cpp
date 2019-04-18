//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/931/
//Implementation: Look for a better Space Complexity solution :)



#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <iostream>
//#include <pair>

using namespace std;




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        map <TreeNode*, int> m;
        
        
        queue<TreeNode*> q;
        
        
        if (root == NULL)
            return res;
        
        q.push(root);
        m.insert(pair<TreeNode*, int>(root, 1));
//        vector<int> inner;
//        inner.push_back(root->val);
        
//        res.push_back(inner);
        
        
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            int height = m.at(node);
            if (height > res.size()){
                vector<int> inner;
                res.push_back(inner);
                res[height-1].push_back(node->val);
            }
            else {
                res[height-1].push_back(node->val);
            }
            
            if (node->left != NULL){
                q.push(node->left);
                m.insert(pair<TreeNode*, int>(node->left, height+1));
            }
            
            if (node->right != NULL){
                q.push(node->right);
                m.insert(pair<TreeNode*, int>(node->right, height+1));
            }
            
            
            cout << "Something";
        }
        
        return res;
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

    vector<vector<int>> res = Solution().levelOrder(root);
    
}
