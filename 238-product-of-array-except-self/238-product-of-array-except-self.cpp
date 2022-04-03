class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        
        int N = nums.size();
        vector<int> leftProduct(N);
        vector<int> rightProduct(N);
        vector<int> product(N);
        leftProduct[0] = 1;
        rightProduct[N-1] = 1 ;
        
        for(int i=1;i<N;i++) leftProduct[i] = leftProduct[i-1] * nums[i-1];
        for(int i=N-2;i>=0;i--) rightProduct[i] = rightProduct[i+1] * nums[i+1]; 
    
        for(int i=0;i<N;i++) product[i] = leftProduct[i] * rightProduct[i];
        
        return product;
    }
};