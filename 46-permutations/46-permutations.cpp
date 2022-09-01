class Solution {
public:
    
    void findPermutations(vector<int>& nums, int cid, vector<vector<int>>& sol){
        
        if(cid==nums.size()){
            
            sol.push_back(nums);
            return;
        }
            
        int n = nums.size();
        for(int i=cid;i<n;i++){
            
            swap(nums[i],nums[cid]);
            findPermutations(nums,cid+1,sol);
            swap(nums[i],nums[cid]);
            
        }

    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> sol;
        int currIndex = 0;
        findPermutations(nums,currIndex,sol);
        return sol;
    
    }
};