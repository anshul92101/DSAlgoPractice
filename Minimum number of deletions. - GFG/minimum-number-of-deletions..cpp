// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends


int minDeletions(string str, int n) { 
    
    string reverseS = str;
    reverse(str.begin(),str.end());
    
    int n1, n2 = str.length();
    n1=n2;
    int t[n1+1][n2+1];
    
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(i==0||j==0) t[i][j]=0;
        }
    }
    
     for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            
            if(str[i-1]==reverseS[j-1]) t[i][j] = 1 + t[i-1][j-1];
            else t[i][j] = max(t[i-1][j],t[i][j-1]);
            
            
        }
    }
    
    int lcsLength=  t[n1][n2];

    
    
    int ans = n - lcsLength;
    return ans;
    
    
    //complete the function here 
} 