class Solution {
public:
    
    int getLCSLength(string word1, string word2, int n1, int n2){
        
        int t[n1+1][n2+1];
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0||j==0) t[i][j]=0;
            }
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]) t[i][j] = 1 + t[i-1][j-1];
                else t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
        
        return t[n1][n2];
        
    }
    
    int minDistance(string word1, string word2) {
        
            int n1= word1.length();
            int n2 = word2.length();
            int l = getLCSLength(word1,word2,n1,n2);
            
            return ((n1-l) + (n2-l));
    
    }
};