// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n){
	    
	    int maxSum = 0;
	    int minDiff = INT_MAX;
	    for(int i=0;i<n;i++) maxSum+= arr[i];
	    
	    int t[n+1][(maxSum/2) + 2];
	    
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<(maxSum/2) + 1; j++){
	            
	            if(j==0) t[i][j] = true;
	            if(i==0 &j!=0) t[i][j] = false;
	        }
	    }
	    
	    
	    for(int i=1;i<n+1;i++){
	        for(int j=0;j<(maxSum/2) + 1;j++){
	            
	            if(arr[i-1]<=j) t[i][j] = t[i-1][j-arr[i-1]]||t[i-1][j];
	            else t[i][j] = t[i-1][j];
	        }
	    }
	    
	    for(int sum=0;sum<=maxSum/2;sum++){
	        
	        if(t[n][sum]){
	            
	            int temp = abs(maxSum - 2*sum);
	            if(temp<minDiff) minDiff = temp;
	        }
	        
	    }
	    
	    return minDiff;
	  
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends