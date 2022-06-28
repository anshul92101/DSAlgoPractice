// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    
        int binarySearchToGetFirstIndex(vector<int> row, int M){
            
            int low = 0;
            int high = M;
            int index = -1;
            while(low<=high){
                int mid = (low+high)/2;
                if(row[mid]==1){
                    index = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
                
            }
            
            return index;
    
            
        }
        
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            // your code here
            int numOfOnes = 0;
            int maxNumOfOnes = INT_MIN;
            int rowWithMaxNumOfOnes = 0;
            int indexOfFirstOne;
            for(int i=0;i<N;i++){
                indexOfFirstOne = binarySearchToGetFirstIndex(Mat[i],M);
                if(indexOfFirstOne==-1) continue;
                numOfOnes = M - indexOfFirstOne;
                if(numOfOnes > maxNumOfOnes){
                    maxNumOfOnes = numOfOnes;
                    rowWithMaxNumOfOnes = i;
                }
            }
            
            return rowWithMaxNumOfOnes;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends