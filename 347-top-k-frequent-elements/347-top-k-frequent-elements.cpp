class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> solution;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        unordered_map<int,int> freq;
        int N = nums.size();
        for(int i=0;i<N;i++) freq[nums[i]]++;
        
        for(auto it: freq){
            
            pair<int,int> p = {it.second, it.first};
            minHeap.push(p);
            if(minHeap.size()>k) minHeap.pop();
    
        }
        while(!minHeap.empty()){
            solution.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return solution;
    }
};