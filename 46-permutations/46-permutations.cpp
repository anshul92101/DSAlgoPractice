class Solution {
public:
    
    void getPermutations(int ind, vector<int> &nums, vector<vector<int>> &solution)     {
        if(ind==nums.size()-1){
            solution.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            
            swap(nums[ind],nums[i]);
            getPermutations(ind+1,nums,solution);
            swap(nums[ind],nums[i]);
            
        }
        
        
    }
    
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> solution;
        int N = nums.size();
        getPermutations(0,nums,solution);
        return solution;
       
    }
    
    
    
};