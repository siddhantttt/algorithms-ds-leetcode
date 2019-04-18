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
public:
    
    void leafSequence(TreeNode* root, vector<int>& leafSeq){
        if (root == NULL)
            return;
        
        leafSequence(root->left, leafSeq);
        leafSequence(root->right, leafSeq);
        
        if (root->right == NULL && root->left == NULL)
            leafSeq.push_back(root->val);
    }
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> leafSeq1, leafSeq2;
        
        leafSequence(root1, leafSeq1);
        leafSequence(root2, leafSeq2);
        
        if (leafSeq1.size() != leafSeq2.size())
            return false;
        
        for (int i = 0; i<leafSeq1.size(); i++){
            if (leafSeq1[i] != leafSeq2[i])
                return false;
        }
        
        return true;
    }
};


int main(){
    
    TreeNode* root = new TreeNode;
    TreeNode* node1 = new TreeNode;
    TreeNode* node2 = new TreeNode;
    TreeNode* node3 = new TreeNode;
    TreeNode* node4 = new TreeNode;
    
    root->val = 3;
    root->right = NULL;
    root->left = NULL;
    
    node1->val = 2;
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
    
    cout << Solution().leafSimilar(root, node1);
}
