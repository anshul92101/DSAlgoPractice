class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int N = nums.size();
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN;
        for(int i=0;i<N;i++){
            
            if(nums[i]<=min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i]<min2) min2 = nums[i];
            
            if(nums[i]>=max1){
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i]>max2) max2 = nums[i];
        }
        
        int ans = max((max1-1) * (max2-1), (min1-1)*(min2-1));
        return ans;
        
    }
};