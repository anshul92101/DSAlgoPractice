class Solution {
public:
       long long int dp[100000];
    
    long long int min(long long int a, long long int b){
    
        if(a<b) return a;
        else return b;
        
    }
    int minJumps(vector<int>& nums, int idx){
        
        int dest = nums.size()-1;
        if(idx>=dest) return 0;
        if(dp[idx]!=-1) return dp[idx];
        long long int ans= INT_MAX-1;
        for(int i=1;i<=nums[idx];i++){
            if(idx + i>dest) break;
            long long int c1 = 1 + minJumps(nums,idx + i);
            ans= min(ans, c1);
        }
        dp[idx]= ans;
        return ans;
        
    }
    
    int jump(vector<int>& nums) {
        
        memset(dp,-1,sizeof dp);
        int ans = minJumps(nums,0);
        return ans;
        
    }
};