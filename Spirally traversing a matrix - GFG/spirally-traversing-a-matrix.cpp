// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int top = 0, down = r-1, right = c-1, left = 0;
        vector<int> solution;
        int dir = 0; // 4 kinds of direction 0-->rightward, 1--> downward, 2-->leftward, 3--> upward
        while(top<=down && left<=right){
            
            if(dir==0){
                for(int i=left;i<=right;i++) solution.push_back(matrix[top][i]);
                top++;
            }
            else if(dir==1){
                
                for(int i=top;i<=down;i++) solution.push_back(matrix[i][right]);
                right--;
                
            }
            else if(dir==2){
                
                for(int i=right;i>=left;i--) solution.push_back(matrix[down][i]);
                down--;
                
            }
            else if(dir==3){
                
                for(int i=down;i>=top;i--) solution.push_back(matrix[i][left]);
                left++;
            }
            
            dir = (dir+1)%4;
        }
    
        return solution;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends