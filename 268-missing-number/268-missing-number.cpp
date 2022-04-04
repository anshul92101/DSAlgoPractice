class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
       int n = nums.size();
       int sumN = 0, sumOfArray=0;
       for(int i=1;i<=n;i++) sumN +=i ;
       for(int i=0;i<n;i++)  sumOfArray += nums[i];
       int missing = sumN - sumOfArray;  
        
       return missing; 
        
    }
};