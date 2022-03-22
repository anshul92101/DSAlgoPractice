class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int result=0;
        int sum = 0, N = nums.size();
        int left=0, right=0;
        int subArrayLen;
        mp[0] = -1;
        for(int i=0;i<N;i++){
            
            sum+=nums[i];
            
            if(mp.find(sum-k)!=mp.end())
            {
                subArrayLen = i - (mp[sum-k] + 1) + 1;
                result = max(result,subArrayLen);
            }
                
            if(mp.find(sum)==mp.end()){
                mp[sum] = i;
            }
            
        }
        
        return result;
        
    }
};