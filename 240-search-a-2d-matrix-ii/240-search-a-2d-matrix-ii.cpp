class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int col = -1;
        //searching the column where to apply binary search
       
        // binary search on col
        for(col=0;col<n;col++){
            int low = 0, high = m-1;
            while(low<=high){

                int mid = (low+high)/2;
                if(matrix[mid][col]==target) return true;
                else if(matrix[mid][col]>target) high = mid-1;
                else low = mid+1;

            }
        }
        return false;
        
    }
};