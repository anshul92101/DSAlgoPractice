class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;
    
    KthLargest(int k, vector<int>& nums) {
        
        kth = k;
        for(auto num: nums){
            add(num);
        }
        
        
    }
    
    int add(int val){
        
        if(pq.size()<kth){
           pq.push(val);
        }
        else if(!pq.empty() && pq.top()<val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/* always add the element and check what the kth largest is, 
return the kth largest element */ 