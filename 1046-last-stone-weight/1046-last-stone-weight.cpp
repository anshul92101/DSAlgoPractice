class Solution {
public:
    int lastStoneWeight(vector<int>& stones){
        
        priority_queue<int> pq;
        int stone1;
        int stone2;
        int N = stones.size();
        
        for(int i=0;i<N;i++){
            pq.push(stones[i]);
        }
        
        while(pq.size()>=2){
            
            stone1 = pq.top();
            pq.pop();
            stone2 = pq.top();
            pq.pop();
            if(stone1==stone2) continue;
            else if(stone1!=stone2) pq.push(stone1-stone2);
            
        }
        if(pq.size()==1) return pq.top();
        return 0;
        
        
    }
};

// put it in a max heap so that the heavies stone is always on the top, pop() the top two stones, do the appropriate operations (of reducing weight or deleting the stone)