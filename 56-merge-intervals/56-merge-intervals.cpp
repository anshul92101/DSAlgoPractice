class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> solution;
        vector<int> mergedInterval = intervals[0];
        for(auto it: intervals){
            
            if(it[0]<=mergedInterval[1]){
                mergedInterval[1] = max(mergedInterval[1], it[1]);
            }
            else{
                solution.push_back(mergedInterval);
                mergedInterval = it;
            }
        }
        solution.push_back(mergedInterval);
        return solution;
    }
};