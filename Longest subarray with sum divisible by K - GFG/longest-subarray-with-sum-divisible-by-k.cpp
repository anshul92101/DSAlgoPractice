// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int, int> remainderToIndexMap; //stores the first time a remainder is encountered
	    int ans = 0;
	    int sum=0,remainder, subArrayLength= 0;
	    remainderToIndexMap[0] = -1;
	    for(int i=0;i<n;i++){
	        
	        sum+=arr[i];
	        remainder = sum%k;
	        if(remainder<0) remainder+=k;
	        if(remainderToIndexMap.find(remainder)!=remainderToIndexMap.end()){
	           subArrayLength = i - (remainderToIndexMap[remainder] + 1) + 1;
	           ans = max(ans, subArrayLength);
	        }
	        else remainderToIndexMap[remainder]=i;
	        
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends