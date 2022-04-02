class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int N = word1.length();
        int M = word2.length();
        
        int dp[N+1][M+1];
        
        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                if(i==0) dp[i][j] = j;
                if(j==0) dp[i][j] = i;
            }
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    
                    dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]}) + 1;
                    
                }
            }
        }
        
        return dp[N][M];
        
    }
};