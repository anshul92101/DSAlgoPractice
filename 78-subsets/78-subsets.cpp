class Solution {
public:
    
    void findSubsets(vector<int> nums, int ind, vector<int> subset, vector<vector<int>> &solution){
        
        if(ind==nums.size()){
            solution.push_back(subset);
            return;
        }
        
        subset.push_back(nums[ind]);
        findSubsets(nums,ind+1,subset,solution);
        subset.pop_back();
        findSubsets(nums,ind+1,subset,solution);

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> subset;
        vector<vector<int>> solution;
        int ind = 0;
        findSubsets(nums,ind,subset,solution);
        return solution;
        
    }
};