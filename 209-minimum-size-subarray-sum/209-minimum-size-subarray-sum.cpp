class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int windowStart =0,windowEnd =0, minWinLength=INT_MAX;
        int curWinLength=0, windowSum=0, flag =0;
        
        for(windowEnd=0;windowEnd<nums.size();windowEnd++){
            
            windowSum+= nums[windowEnd];
            while(windowSum>=target){
                
                curWinLength = windowEnd - windowStart + 1;
                minWinLength = min(curWinLength, minWinLength);
                windowSum-=nums[windowStart];
                windowStart++;
                flag=1;
            
            }
        
        }
        if(flag==1) return minWinLength;
        return 0;
        
    }
};