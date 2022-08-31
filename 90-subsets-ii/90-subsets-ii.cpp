class Solution {
public:
    
    
    void findSubsets(vector<int> nums, int ind, vector<int> subset, vector<vector<int>> &solution){

        solution.push_back(subset);
        
        for(int i=ind;i<nums.size();i++){

            if(i!=ind && nums[i]==nums[i-1]) continue;
            subset.push_back(nums[i]);
            findSubsets(nums,i+1,subset,solution);
            subset.pop_back();
        
        }
    
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    
        vector<int> subset = {};
        int ind = 0 ;
        sort(nums.begin(),nums.end());
        vector<vector<int>> solution;
        findSubsets(nums,ind,subset,solution);
        return solution;
    
    }
};