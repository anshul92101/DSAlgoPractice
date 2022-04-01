class Solution {
public:
    int dp[1000][1000];
    int getAnswer(string &text1, string &text2, int N){
        
        int lcs[2][N+1];
        memset(lcs,0,sizeof lcs);
        for(int i=0;i<2;i++){
            for(int j=0;j<N;j++){
                if(i==0 || j==0) lcs[i][j]=0;
            }
        }
        
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=N;j++){
                if(text1[i-1]==text2[j-1]) lcs[i%2][j] = 1 + lcs[(i-1)%2][(j-1)];
                else lcs[i%2][j] = max(lcs[(i-1)%2][j],lcs[i%2][(j-1)]);
            }
        }
        
        return lcs[text1.size()%2][N];
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n1 = text1.size();
        int n2 = text2.size();
       // vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        int biggerLength = max(n1,n2);
        int ans = getAnswer(text1,text2, biggerLength);    
        return ans;
    }
};