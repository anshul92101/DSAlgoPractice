// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
       
        if(n>m) return kthElement(arr2,arr1,m,n,k);
	    int high = min(n,k);
	    int low = max(0,k-m);
        int cut1, cut2, left1,left2,right1, right2;
    	while(low<=high){
    
    		cut1 = (low+high)/2;
    		cut2 = k - cut1;
    
    		if(cut1==0) left1 = INT_MIN;
    		else left1 = arr1[cut1-1];
    		if(cut2==0) left2 = INT_MIN;
    		else left2 = arr2[cut2-1];
    
    		if(cut1==n) right1=INT_MAX;
    		else right1= arr1[cut1];
    		if(cut2==m) right2= INT_MAX;
    		else right2 = arr2[cut2];
    
    		if(left1<=right2 && left2<=right1){
    
    			int ans = max(left1,left2);
    			return ans;
    
    		}
    		else if(left1>right2) high = cut1-1;
    		else low = cut1 + 1;
    
    	}
    	
    	return -1;   
        
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends