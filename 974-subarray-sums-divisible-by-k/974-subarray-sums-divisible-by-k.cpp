class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int sum=0, count=0, remainder;
        int N = nums.size();
        unordered_map<int,int> remainderFrequency;
        remainderFrequency[0] = 1;
                
        for(int i=0;i<N;i++){
            
            sum+= nums[i];
            remainder = sum%k;
            if(remainder<0) remainder+=k;
            
            if(remainderFrequency.find(remainder)!=remainderFrequency.end()){
                
                count+=remainderFrequency[remainder];
            }
            remainderFrequency[remainder]++;
            
        }
        
        return count;
        
        
    }
};