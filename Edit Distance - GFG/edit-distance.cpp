// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        
        int N = s.length();
        int M = t.length();
        
        int dp[N+1][M+1];
        
        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                if(i==0) dp[i][j] = j;
                if(j==0) dp[i][j] = i;
            }
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    
                    dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]}) + 1;
                    
                }
            }
        }
        
        return dp[N][M];
        // Code here
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends