class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        
        string reverseS = s;
        reverse(s.begin(),s.end());
        
        int n1, n2 = s.length();
        n1=n2;
        int t[n1+1][n2+1];
        
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(i==0||j==0) t[i][j]=0;
            }
        }
        
         for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                
                if(s[i-1]==reverseS[j-1]) t[i][j] = 1 + t[i-1][j-1];
                else t[i][j] = max(t[i-1][j],t[i][j-1]);
                
                
            }
        }
        int diff = n1- t[n1][n2];
        if(diff<=k) return true;
        else return false;
        
    }
};