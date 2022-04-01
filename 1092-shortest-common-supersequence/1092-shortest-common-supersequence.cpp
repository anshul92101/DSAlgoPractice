class Solution {
public:
    
    string getString(string &str1, string &str2, vector<vector<int>> &t){
        
            int n1 = str1.length();
            int n2 = str2.length();    
            
            int i = n1, j=n2;
            string scs="";
            while(i>0 && j>0){
                
                if(str1[i-1]==str2[j-1]){
                    scs.push_back(str1[i-1]);
                    i--;
                    j--;
                }
                else if(t[i-1][j]>t[i][j-1]){
                    scs.push_back(str1[i-1]);
                    i--;
                }
                else{
                    scs.push_back(str2[j-1]);
                    j--;
                }
                
            }
            while(i>0){
                scs.push_back(str1[i-1]);
                i--;
            }
            while(j>0){
                scs.push_back(str2[j-1]);
                j--;
            }
        
            reverse(scs.begin(),scs.end());
            return scs;
        
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n1 = str1.length();
        int n2 = str2.length();
        
        vector<vector<int>> t(n1+1,vector<int>(n2+1));
        
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                
                if(i==0||j==0) t[i][j]=0;     
            }
        
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                
                if(str1[i-1]==str2[j-1]) t[i][j] = 1 + t[i-1][j-1];
                else t[i][j] = max(t[i-1][j],t[i][j-1]);
                
            }
        }
        
        string ans = getString(str1,str2,t);
        return ans;
        
    }
};