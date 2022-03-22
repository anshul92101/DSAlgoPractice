class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int product = 1;
        int ans = INT_MIN;
        int N = nums.size();
        
        for(int i=0;i<N;i++){

            product*= nums[i];
            ans= max(product,ans);
            if(product==0){
                product = 1;
            }
        
        }
        product = 1;
        for(int i=N-1;i>=0;i--){
            product*= nums[i];
            ans= max(product,ans);
            if(product==0){
                product = 1;
            }
        }
            
        return ans;
        
        
    }
};