/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev;
    void inorder(TreeNode* root, bool& ans){
        
        if(root==NULL) return;
        inorder(root->left,ans);
        if(prev!=NULL && root->val <= prev->val) ans = false;
        prev = root;
        return inorder(root->right,ans);
        
    }
    
    bool isValidBST(TreeNode* root) {
        
       prev = NULL; 
       bool ans = true; 
       inorder(root, ans);
       return ans;
        
    }
};