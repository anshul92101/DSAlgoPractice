class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int N = arr.size();
        vector<int> solution;
        priority_queue<pair<int,int>> maxH;
        for(int i=0;i<N;i++){
            pair<int,int> p = {abs(x-arr[i]), arr[i]};
            maxH.push(p);
            if(maxH.size()>k) maxH.pop();
        }
        
        while(!maxH.empty()){
            solution.push_back(maxH.top().second);
            maxH.pop();
        }
        sort(solution.begin(),solution.end());
        return solution;
    }
};