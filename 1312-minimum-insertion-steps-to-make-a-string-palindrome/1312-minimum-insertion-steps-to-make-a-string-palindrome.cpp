class Solution {
public:
    int minInsertions(string s) {
        
        string r = s;
        reverse(s.begin(),s.end());
        
        int N = s.length();
        int t[N+1][N+1];
        
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                if(i==0||j==0) t[i][j] =0;
            }
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(s[i-1]==r[j-1]) t[i][j] = 1 + t[i-1][j-1];
                else t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    
        
        int lcsLength = t[N][N];
        int ans = N - lcsLength;
        return ans;
    }
};