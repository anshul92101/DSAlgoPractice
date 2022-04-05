class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i,l,r;
        int sum;
        int closest = INT_MAX;
        int solution;
        for(i=0;i<=n-3;i++){
            
            l = i+1;
            r = n-1;
            int newTarget = target - nums[i];
            while(l<r){
                
                sum = nums[r] + nums[l];
                int diff = abs(newTarget - sum);
                if(diff<closest) {
                    closest = diff;
                    solution = sum + nums[i];
                }
                if(sum<newTarget) l++;
                else if(sum>newTarget) r--;
                else return (sum + nums[i]);
                
            }
            
        }
        return solution;
        
    }
};