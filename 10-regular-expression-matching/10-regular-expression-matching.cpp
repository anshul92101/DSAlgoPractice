class Solution {
public:
    
    bool getIfMatching(int i, int j, string& p, string& s, vector<vector<int>>& dp){
        
        if(i<=-1 && j<=-1) return true;
        if(i<0 && j>=0) return false;
        if(j==-1 && i>=0){
            if(p[i]=='*') return getIfMatching(i-2,j,p,s,dp);
            else return false;
        }
        
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[i]==s[j] || p[i]=='.') return dp[i][j] = getIfMatching(i-1,j-1,p,s,dp);
        else if(p[i]=='*'){ 
            
            if(p[i-1]==s[j] || p[i-1]=='.'){
                return dp[i][j] = getIfMatching(i-2,j,p,s,dp) || getIfMatching(i,j-1,p,s,dp) ;
            }
            else return dp[i][j] = getIfMatching(i-2,j,p,s,dp);
                
        }
        return dp[i][j] = false;
        
    }
    
    
    bool isMatch(string s, string p) {
        
        int m = p.size();
        int n = s.size();        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        bool ans = getIfMatching(m-1,n-1,p,s,dp);
        return ans;
        
    }
};