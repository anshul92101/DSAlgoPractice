// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solveMCM(int arr[],int i, int j, vector<vector<int>> &t){
        
        if(i>=j) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int min = INT_MAX;
        for(int k=i;k<=j-1;k++){
            
            int tempAns = solveMCM(arr,i,k,t) + solveMCM(arr,k+1,j,t) + arr[i-1]*arr[k]*arr[j];
            if(tempAns<min) min = tempAns;
            
        }
        t[i][j] = min;
        return min;
        
    }

    int matrixMultiplication(int N, int arr[])
    {
        
        vector<vector<int>> t(N, vector<int>(N,-1));
        int solution = solveMCM(arr,1,N-1,t);
        return solution;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends