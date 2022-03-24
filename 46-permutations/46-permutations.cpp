class Solution {
public:
    
    void getPermutations(vector<int> &nums, vector<int> &visited, vector<vector<int>> &solution, vector<int> &ans){
        
        if(ans.size()==nums.size())
        {
            solution.push_back(ans);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            
            if(!visited[i]){
                
                visited[i]=1;
                ans.push_back(nums[i]);
                getPermutations(nums,visited,solution,ans);
                visited[i]=0;
                ans.pop_back();
            }
            
        }
        
        
    }
    
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> solution;
        int N = nums.size();
        vector<int> visited(N,0);
        vector<int> ans;
        getPermutations(nums,visited,solution,ans);
        return solution;
       
    }
    
    
    
};