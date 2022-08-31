class Solution {
public:
    int mySqrt(int x) {
        
        if(x==0 || x==1) return x;
        long long int low = 1, high = x;
        long long int ans = 0;
        while(low<=high){
            long long int mid = low + (high-low)/2;
            if(mid <= x/mid){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};