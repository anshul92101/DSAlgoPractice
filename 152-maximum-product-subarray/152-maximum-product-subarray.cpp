class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int omax = nums[0];
        int dp_max = nums[0];
        int dp_min = nums[0];
        for(int i=1;i<nums.size();i++){

            int res = max({nums[i],dp_max*nums[i],dp_min*nums[i]});
            dp_min = min({nums[i],dp_max*nums[i],dp_min*nums[i]});
            dp_max = res;
            omax = max(omax,dp_max);
        
        }
        
        return omax;
    }
};