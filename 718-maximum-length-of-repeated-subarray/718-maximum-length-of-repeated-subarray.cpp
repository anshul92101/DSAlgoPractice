class Solution {
public:
    
    int getMax(vector<vector<int>>& dp){
        
        int n1 = dp.size();
        int n2 = dp[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(dp[i][j]>ans) ans = dp[i][j];
            }
        }
        return ans;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
       // int dp[n1+1][n2+1];
        for(int i=1;i<=n1;i++){
            
            for(int j=1;j<=n2;j++){
                
                if(nums1[i-1]==nums2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
                
            }
            
        }
        
        int ans = getMax(dp);
        return ans;
        
    }
};