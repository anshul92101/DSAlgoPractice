class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) nums[i]=-1;
        }
        
        unordered_map<int,int> mp;
        int result = 0;
        int k = 0, subArrayLen;
        int sum = 0, N = nums.size();
        mp[0] = -1;
        for(int i=0;i<N;i++){
                                        //[-1,1,-1,-1,1] 
            sum+= nums[i];
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            if(mp.find(sum)!=mp.end()){
                subArrayLen = i - mp[sum];
                result = max(result,subArrayLen);
            }
    
        }
        
        return result;
    }
};