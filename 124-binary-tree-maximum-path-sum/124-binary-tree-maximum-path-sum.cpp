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
    
    int getPath(TreeNode* node, int &maxi){
        
        if(node==NULL) return 0;
        
        int leftPath = getPath(node->left, maxi);
        int rightPath = getPath(node->right, maxi);
        
        int temp = max(node->val,node->val + max(leftPath,rightPath));
        int ans = max(temp, node->val + leftPath + rightPath);
        maxi = max(ans,maxi);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        
        int maxpath = INT_MIN ;
        int ans = getPath(root,maxpath);
        return maxpath;
        
    }
};