// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    unordered_map<string, int> mp;
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    { 
       // Your code here
       if(W==0 || n==0) return 0;
       string expr = to_string(W) + "_" + to_string(n);
       if(mp.find(expr)!=mp.end()){
           return mp[expr];
       }
       if(wt[n-1]<=W){
           
           int choice1 = val[n-1] + knapSack(W-wt[n-1],wt,val,n-1);
           int choice2 = knapSack(W,wt,val,n-1);
           int tempAns = max(choice1, choice2);
           return mp[expr] = tempAns;
       }
       else return mp[expr] = knapSack(W,wt,val,n-1);
       
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends