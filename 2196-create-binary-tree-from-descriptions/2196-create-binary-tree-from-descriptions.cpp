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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int, TreeNode*> treeMap;
        unordered_map<int,bool> isChild;
        TreeNode* root = NULL;
        for(int i=0;i<descriptions.size();i++){
            
            vector<int> node = descriptions[i];
            TreeNode* parentNode = NULL;
            TreeNode* childNode = NULL;
            if(treeMap.find(node[0])!=treeMap.end()) parentNode = treeMap[node[0]];
            else{
                parentNode = new TreeNode(node[0]);
                treeMap[node[0]] = parentNode;
            }
            
            if(treeMap.find(node[1])!=treeMap.end()) childNode = treeMap[node[1]];  
            else childNode = new TreeNode(node[1]);
            if(node[2]==1) parentNode->left = childNode;
            else if(node[2]==0) parentNode->right = childNode;
            treeMap[childNode->val] = childNode;
            isChild[childNode->val] = true;
            
        }
        int val;
        auto node = treeMap.begin();
        while(node!= treeMap.end()){
            val = node->first;
            int ans;
            if(isChild[val]==false){
                ans = val;
                break;
            }
            node++;
        }
        
        root = treeMap[val];
        
        return root;
        
    }
};