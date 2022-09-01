class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> indexHash;
        for(int i=0;i<nums.size();i++){
            
            if(indexHash.find(target-nums[i])!= indexHash.end()){
                int ind1 = i;
                int ind2 = indexHash[target - nums[i]];
                return {ind1, ind2};
            }
            
            indexHash[nums[i]] = i;
        
        }
       return {0,0};
        
        
    }
};