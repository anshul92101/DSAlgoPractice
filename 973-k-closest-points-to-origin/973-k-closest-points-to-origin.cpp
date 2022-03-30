class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,vector<int>>> maxHeap;
        vector<vector<int>> solution;
        int N = points.size();
        for(int i=0;i<N;i++){
            
            pair<int,vector<int>> p;
            p.first = pow(points[i][0],2) + pow(points[i][1],2);
            p.second = points[i];
            maxHeap.push(p);
            
            if(maxHeap.size()>k) maxHeap.pop();  
        }
        while(!maxHeap.empty()){
            solution.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return solution;
        
    }
};