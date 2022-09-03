class Solution {
public:
    
    bool getIfMatching(int i, int j, string& s, string &p, vector<vector<int>>& dp){
        
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0){
            for(int itr=0; itr<=i; itr++){
                if(p[itr]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[i]==s[j] || p[i]=='?') return dp[i][j] = getIfMatching(i-1,j-1,s,p,dp);
        if(p[i]=='*'){
            return dp[i][j] = getIfMatching(i-1,j,s,p,dp) | getIfMatching(i,j-1,s,p,dp);
        }
        
        return dp[i][j] = false;
    
    }
    
    
    bool isMatch(string s, string p) {
        
        int m = p.length();
        int n = s.length();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        bool ans = getIfMatching(m-1,n-1,s,p,dp);
        return ans;
    
    }
};