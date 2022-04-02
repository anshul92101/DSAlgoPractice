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
    bool isLeaf(TreeNode* root){
        
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL) return true;
        else return false;
        
        
    }
    int minDepth(TreeNode* root) {
        
        if(isLeaf(root)) return 1;
        if(root==NULL) return 0;
        int left=INT_MAX, right=INT_MAX;
        if(root->left) left = minDepth(root->left);
        if(root->right) right = minDepth(root->right);
        
        int ans = min(left,right) + 1;
        
        return ans;
        
    }
};