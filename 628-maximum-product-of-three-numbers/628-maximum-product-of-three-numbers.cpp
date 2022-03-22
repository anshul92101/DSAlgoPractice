class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int min1=INT_MAX, min2= INT_MAX, max1=INT_MIN, max2=INT_MIN, max3= INT_MIN;
        int N = nums.size();
        
        for(int i=0;i<N;i++){
            
            if(nums[i]<=min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i]<min2){
                min2 = nums[i];
            }
            if(nums[i]>=max1){
                
                max3 = max2;
                max2 = max1;
                max1 = nums[i];

            }
            else if(nums[i]>=max2){
                max3= max2;
                max2 = nums[i];
            }
            else if(nums[i]>max3){
                max3 = nums[i];
            }
            
        }
        
        int prod1 = min1*min2;
        int prod2 = max2*max3;
        int solution = max(prod1*max1, prod2*max1);
        return solution;
        
    }
};