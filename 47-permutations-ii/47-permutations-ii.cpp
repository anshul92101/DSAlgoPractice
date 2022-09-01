class Solution {
public:
    void findSolutions(vector<int> &nums, int currIndex,vector<vector<int>> & solutions ){
            
        if(currIndex==nums.size()){
            solutions.push_back(nums);
            return;
        }
        
        int n = nums.size();
        unordered_set<int> hashSet;
        hashSet.clear();
        
        for(int i=currIndex;i<n;i++){
            if(hashSet.find(nums[i])==hashSet.end()){
                hashSet.insert(nums[i]);
            }
            else continue;
            swap(nums[i],nums[currIndex]);
            findSolutions(nums,currIndex+1,solutions);
            swap(nums[i],nums[currIndex]);
        }
        
        
        
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> solutions;
        int currIndex = 0;
        findSolutions(nums,currIndex,solutions);
        return solutions;
        
    }
};