// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{   
    public:
    unordered_map<string,int> mp;
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor
    int eggDrop(int n, int k) 
    {
        // your code here
        int ans = INT_MAX;
        if(n==1) return k;
        if(k<=1) return k;
        int low = 0, high = k;
        string expr = to_string(n) + "_" + to_string(k);
        if(mp.find(expr)!=mp.end()) return mp[expr];
        
        while(low<=high){
            
            int mid = (low+high)/2;
            int left = eggDrop(n-1,mid-1);
            int right = eggDrop(n,k-mid);
            int temp = 1 + max(left,right);
            ans = min(ans,temp);
            if(left>right) high = mid-1;
            else low = mid+1;
        }
        return mp[expr] = ans;
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends