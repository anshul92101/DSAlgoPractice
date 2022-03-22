class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int N = nums.size();
        int res=0 , e= 0, s=0;
        int product = 1;
        
        for(e=0;e<N;e++){
            
            product*=nums[e];
            while(s<e && product>=k){
                product = product/nums[s];
                s++;
            }
            if(product<k){
                res += (e-s + 1);
            }
            
        }
        
        return res;
        
    }
};