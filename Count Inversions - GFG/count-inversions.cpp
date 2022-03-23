// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    long long int merge(long long arr[],int start,int mid, int end){
            
            //if(start>=end) return 0;
            int i=start, k=0, j = mid+1;
            long long int inv =0;
            int N = end-start+1;
            long long temp[N];
            
            while(i<=mid && j<=end){
                
                if(arr[i]<=arr[j]) temp[k++] = arr[i++];
                else{
                    temp[k++] = arr[j++];
                    inv+= (mid - i + 1);
                }
                
            }
            while(i<=mid) temp[k++] = arr[i++];
            while(j<=end) temp[k++] = arr[j++];
            k=0;
            while(k<N){
                arr[start+k] = temp[k];
                k++;
            }
            return inv;
    
    }

    long long int mergeSort(long long arr[], int start, int end){
        
        long long int inv= 0;
        if(end>start){
            int mid = (start+end)/2;
            inv+= mergeSort(arr,start,mid);
            inv+= mergeSort(arr,mid+1,end);
            inv+= merge(arr,start,mid,end);
        }
        return inv;
        

    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int ans = mergeSort(arr,0,N-1);
        return ans;
    
        
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends