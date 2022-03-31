class Solution {
public:
    
    bool hasSubset(vector<int>& nums, int sum){
    
        int N = nums.size();
        int t[N+1][sum+1];
        for(int i=0;i<N+1;i++){
            for(int j=0;j<sum+1;j++){
                if(j==0) t[i][j] = true;
                if(i==0 && j!=0) t[i][j] = false;
            }
        }
    
        for(int i=1;i<N+1;i++){
            for(int j=0;j<sum+1;j++){
                
                if(nums[i-1]<=j) t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                else t[i][j] = t[i-1][j];
                
                
            }
        }
        return t[N][sum];
    
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%2==1) return false;
        else{
            bool ans = hasSubset(nums, sum/2);
            return ans;
        }
        
    }
};