// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string, int> mp;
    int num = 1003;
    int solve(string s, int i, int j, bool isTrue){
        
        if(i>j) return 0;
        if(i==j){
            if(isTrue==true) return s[i]=='T';
            else return s[i]=='F';
        }
        int ans =0;
        string expr = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
        if(mp.find(expr)!=mp.end()) return mp[expr];
        
        for(int k=i+1;k<=j-1;k=k+2){
            
            int lT = solve(s,i,k-1,true);
            int lF = solve(s,i,k-1,false);
            int rT = solve(s,k+1,j,true);
            int rF = solve(s,k+1,j,false);
            
            if(s[k]=='&'){
                if(isTrue==true){
                    ans+= lT * rT;
                }
                else ans+= lF*rT + lF*rF + rF*lT;
            }
            else if(s[k]=='|'){
                if(isTrue==true){
                    ans+= lT*rF + rT*lF + rT*lT;
                }
                else ans+= lF*rF;
            }
            else if(s[k]=='^'){
                if(isTrue==true){
                    ans+= lT*rF + lF*rT;
                }
                else ans+= lT*rT + lF*rF;
            }
            
        }
        
        mp[expr] = ans%num;
        return ans%num;
        
    }

    int countWays(int N, string S){
        
        mp.clear();
        int ans = solve(S,0,N-1,true);
        return ans%num;
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends