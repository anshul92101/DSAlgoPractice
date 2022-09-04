class Solution {
public:
    
    //cases --> s->i , p --> j
    //match from the end
    
    bool getIfMatching(string s, string p, int i, int j, vector<vector<int>>& dp){
        
        if(j<0 && i<0) return true;
        if(j<0 && i>=0) return false;
        if(j>=0 && i<0){
            if(p[j]=='*') return getIfMatching(s,p,i,j-2,dp);
            else return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        if(s[i]==p[j] || p[j]=='.') return dp[i][j] = getIfMatching(s,p,i-1,j-1,dp);
        if(p[j]=='*'){
            if(p[j-1]==s[i] || p[j-1]=='.') return dp[i][j] = getIfMatching(s,p,i-1,j,dp) || getIfMatching(s,p,i,j-2,dp);
            else return dp[i][j] = getIfMatching(s,p,i,j-2,dp);
        }
           
        return dp[i][j] = false;
           
    }
    
    
    bool isMatch(string s, string p) {
        
        int m = s.length();
        int n = p.length();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        bool solution = getIfMatching(s,p,m-1,n-1,dp);
        return solution;
    
    }
};