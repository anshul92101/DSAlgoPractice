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
    int getDiameter(TreeNode* node, int &diameter){
        
        if(node==NULL) return 0;
        int leftDia = getDiameter(node->left,diameter);
        int rightDia = getDiameter(node->right,diameter);
        int temp = max(leftDia, rightDia)+1;
        int ans = leftDia + rightDia + 1;
        diameter = max(diameter, ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = 0;
        int ans =  getDiameter(root, diameter);
        return diameter-1;
    }
};