#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* temp = root;
        
        while (!s.empty() || temp != NULL){
            if (temp != NULL){
                s.push(temp);
                temp = temp->left;
            }
            
            else {
                temp = s.top();
                s.pop();
                res.push_back(temp->val);
                temp = temp->right;
            }
        }
        return res;
    }
};


int main(){
    
    TreeNode* root = new TreeNode;
    TreeNode* temp1= new TreeNode;
    TreeNode* temp2 = new TreeNode;
    
    root->val = 1;
    root->left = NULL;
    root->right = temp1;
    
    
    temp1->val = 2;
    temp1->left = temp2;
    temp1->right = NULL;
    
    temp2->val = 3;
    temp2->left = NULL;
    temp2->right = NULL;
    
    
    vector<int> res = Solution().inorderTraversal(root);
    cout << " ";
}




