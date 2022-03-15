class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSum = INT_MIN, currMax = 0;
        
        for(int i=0; i<nums.size();i++){
            
            if(nums[i]<currMax + nums[i]){
                currMax = currMax + nums[i];
            }
            else currMax = nums[i];
                        
            maxSum = max(maxSum,currMax);
            
        }
        
        return maxSum;
        
    }
};