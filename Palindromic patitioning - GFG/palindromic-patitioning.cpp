// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{

public:
    int t[1001][1001];
    bool isPalindrome(string s, int i, int j){

        if(i>=j) return true;
        int itr1,itr2;
        for(itr1=i,itr2 =j; i<j;i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
    }
    
    int solve(string s, int i, int j){
        
        if(i>=j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int min = INT_MAX;
        int left, right;
        for(int k=i;k<=j-1;k++){
            
            if(t[i][k]!=-1) left = t[i][k];
            else{
                left = solve(s,i,k);
                t[i][k] = left;
            }
            
            if(t[k+1][j]!=-1) right = t[k+1][j];
            else{
                right = solve(s,k+1,j);
                t[k+1][j]= right;
            }
            
            int tempAns = left +  right + 1;
            if(tempAns<min) min = tempAns;
        
            
        }
        
        t[i][j] = min;
        return min;
        
        
    }

    int palindromicPartition(string str)
    {
        memset(t,-1,sizeof t);
        int solution;
        int N = str.length();
        solution = solve(str,0,N-1);
        return solution;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends