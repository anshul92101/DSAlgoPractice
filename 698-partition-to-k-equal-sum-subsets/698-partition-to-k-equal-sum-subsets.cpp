class Solution {
public:
    unordered_map<vector<bool>, bool> dp;
    bool findSubsets(vector<int>& nums,int index, int currSum, int sum, int count, int k, vector<bool> &visited){
        
        
        if(dp.find(visited)!=dp.end()) return dp[visited];
        if(count==k-1) return dp[visited] = true;
        if(currSum>sum) return dp[visited] = false;
        
        if(currSum==sum){
            currSum =0;
            count++;
            return dp[visited] = findSubsets(nums,0,currSum,sum,count,k,visited);
        }
        
        
        int N = nums.size();
        
        
        
        for(int i=index;i<N;i++){
            
            if(visited[i]==false){   
               // currSum+=nums[i];
                visited[i]=true;
                
                if(findSubsets(nums,i+1, currSum + nums[i],sum,count,k,visited)) return dp[visited] = true;
              //  currSum-=nums[i];
                visited[i] = false;
            }
            
        }
        
        return dp[visited] = false;
        
        
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0;
        int n = nums.size();
        vector<bool> visited(n,false);
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
        }
        
        if(sum%k!=0) return false;
        //vector<int> currSubset;
        sort(nums.begin(),nums.end(),greater<int>());
        int currSum=0;
        int count = 0;
        bool ans = findSubsets(nums,0,currSum,sum/k,count, k,visited);
        
        return ans;
        
    }
};