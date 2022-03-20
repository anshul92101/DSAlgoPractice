class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        
        vector<int> PSA; //an array to store the prefix sum
        int N = nums.size();
        unordered_map<int, int> freq; // stores the frequency of curSum-k
        int curSum =0;
        int count=0;
        freq[curSum]=1;
        for(int i=0;i<N;i++){
            curSum+=nums[i];
            if(freq.find(curSum-k)!=freq.end()){
                count+= freq[curSum-k];
            }
            freq[curSum]++;
        }
        return count;
    }
};