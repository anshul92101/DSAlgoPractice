
// sum equals to y at index k
//we should check if we have seen y-k at a previous index i... i-1 to k will have sum == req_sum
// 5 --> 10 , --> 10
class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        
        int sum=0, i,N = nums.size(),count=0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(i=0;i<N;i++){
            
            sum+=nums[i];
            if(mp.find(sum-k)!= mp.end()){
                count += mp[sum-k];
            }
            mp[sum]++;
            
        }
        return count;
    
    }
};