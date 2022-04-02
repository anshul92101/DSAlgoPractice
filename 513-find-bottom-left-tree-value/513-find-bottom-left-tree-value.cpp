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
    int findBottomLeftValue(TreeNode* root){
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> solution;
        while(!q.empty()){
            
            int size = q.size();
            for(int i=0;i<size;i++){
                
                TreeNode* curr = q.front();
                q.pop();
                if(i==0) solution.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
            }
            
        }
        int N = solution.size();
        int ans = solution[N-1];
        return ans;
    }
};