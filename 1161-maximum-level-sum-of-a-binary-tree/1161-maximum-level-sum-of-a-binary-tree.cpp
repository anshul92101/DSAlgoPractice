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
    int maxLevelSum(TreeNode* root){
        
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int maxIndex = 0;
        int levelIndex = 1;
        while(!q.empty()){
            
            int levelSize = q.size();
            int sum =0;
            for(int i=0;i<levelSize;i++){
                
                TreeNode* currNode = q.front();
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
                sum+= currNode->val;
                q.pop();
            }
            if(sum>maxSum){
                
                maxSum = sum;
                maxIndex = levelIndex;
            }
            levelIndex++;
            
        }
        return maxIndex;
    }
};