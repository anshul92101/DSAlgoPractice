class Solution {
public:
    
    vector<int> nearestSmallTowardsLeft(vector<int> heights){

        vector<int> indexes;
        stack<pair<int,int>> s;
        for(int i=0;i<heights.size();i++){
            
            if(s.empty()) indexes.push_back(-1);
            else{
                
                if(s.top().first<heights[i]) indexes.push_back(s.top().second); 
                else{
                    
                    while(!s.empty() && s.top().first>=heights[i]) s.pop();
                    if(s.empty()) indexes.push_back(-1);
                    else if(s.top().first<heights[i]){           
                        indexes.push_back(s.top().second);
                    };
                    
                }
                
            }
            pair<int,int> p = {heights[i],i};
            s.push(p);
    
        }
        
        return indexes;
    }
    
    
    vector<int> nearestSmallTowardsRight(vector<int> heights){

        vector<int> indexes;
        stack<pair<int,int>> s;
        int pseudoIndex = heights.size();
        for(int i=heights.size()-1;i>=0;i--){
            
            if(s.empty()) indexes.push_back(pseudoIndex);
            else{
                
                if(s.top().first<heights[i]) indexes.push_back(s.top().second); 
                else{
                    
                    while(!s.empty() && s.top().first>=heights[i]) s.pop();
                    if(s.empty()) indexes.push_back(pseudoIndex);
                    else if(s.top().first<heights[i]){ 
                        indexes.push_back(s.top().second);
                    }
                }
                
            }
            pair<int,int> p = {heights[i],i};
            s.push(p);
    
        }
        reverse(indexes.begin(),indexes.end());
        return indexes;
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        
        int N = heights.size();
        int maxArea = INT_MIN;
        vector<int> leftSmallerIndexes = nearestSmallTowardsLeft(heights);
        vector<int> rightSmallerIndexes = nearestSmallTowardsRight(heights);
        
        for(int i =0;i<N;i++){
            
            int area = (rightSmallerIndexes[i] - leftSmallerIndexes[i] - 1)*heights[i];
            if(area>maxArea) maxArea = area;
        }
        
        return maxArea;
        
    }
};