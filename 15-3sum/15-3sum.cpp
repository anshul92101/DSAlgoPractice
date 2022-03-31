class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int i=0,l,r;
        int target;
        sort(nums.begin(),nums.end());   
        vector<vector<int>> solution;
        
        int n = nums.size();
        
        for(i=0;i<=n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            l = i+1;
            r = n-1;
            target = 0 - nums[i];
            while(l<r){ 
                int sum = nums[l] + nums[r];
                if(sum>target) r--;
                else if(sum<target) l++;      
                else{
                    solution.push_back(vector<int>({nums[i],nums[l],nums[r]}));
                    while (l<n-1 && nums[l]==nums[l+1])  l++;
                    while (r-1>=0 && nums[r]==nums[r-1]) r--;
                    l++,
                    r--;
                }
               
            }
        }
        return solution;
        
    }
};