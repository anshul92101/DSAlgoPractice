class Solution {
public:
    int dp[1000][1000];
    int lcs(string &text1, string &text2, int n1, int n2){
        
        if(n1==0||n2==0) return 0;
        
        if(dp[n1][n2]!=0) return dp[n1][n2];
        
        if(text1[n1-1]==text2[n2-1]){
            
            return dp[n1][n2] = 1 + lcs(text1,text2,n1-1,n2-1);
            
        }
        else{
            
            return dp[n1][n2] = max(lcs(text1,text2,n1,n2-1), lcs(text1,text2,n1-1,n2));
            
        }
        
        
        
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n1 = text1.size();
        int n2 = text2.size();
        memset(dp,0,sizeof dp);
       // vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        int ans = lcs(text1,text2,n1,n2);    
        return ans;
    }
};