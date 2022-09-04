class Solution {
public:
    
    void findPermutations(vector<int>& nums, vector<vector<int>>& solution, int index){
        
        if(index==nums.size()){
            solution.push_back(nums);    
            return;
        }
        
        
        int n = nums.size();
        for(int i=index;i<n;i++){
            
            swap(nums[index],nums[i]);
            findPermutations(nums, solution, index+1);
            swap(nums[index],nums[i]);
        
        }
        
        
    }
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> solution;
        findPermutations(nums,solution,0);
        return solution;
    
    }
};