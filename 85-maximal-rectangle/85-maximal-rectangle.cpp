class Solution {
public:
    
    vector<int> nextSmallestLeft(vector<int> &vec){
        
        stack<pair<int,int>> s;
        vector<int> index;
        for(int i=0;i<vec.size();i++){
            
            if(s.empty()) index.push_back(-1);
            else{
                if(s.top().first<vec[i]) index.push_back(s.top().second);
                else{
                    
                    while(!s.empty()&& s.top().first>=vec[i]) s.pop();
                    if(s.empty()) index.push_back(-1);
                    else if(s.top().first<vec[i]) index.push_back(s.top().second);
                
                }
            }
            pair<int,int> p = {vec[i],i};
            s.push(p);
            
        }
        
        return index;
        
        
    }
    
    vector<int> nextSmallestRight(vector<int> &vec){
        
        stack<pair<int,int>> s;
        vector<int> index;
        int N = vec.size();
        int pseudoIndex = N;
        
        for(int i=N-1;i>=0;i--){

            if(s.empty()) index.push_back(pseudoIndex);
            else{
                if(s.top().first<vec[i] ) index.push_back(s.top().second);
                else{

                    while(!s.empty()&& s.top().first>=vec[i]) s.pop();
                    if(s.empty()) index.push_back(pseudoIndex);
                    else if(s.top().first<vec[i] ) index.push_back(s.top().second);

                }
            }
            pair<int,int> p = {vec[i],i};
            s.push(p);
            
        }   
        reverse(index.begin(), index.end());
        return index;
        
        
    }
    
    
    int maximalHistogram(vector<int>& vec){

    
        vector<int> leftIndexes = nextSmallestLeft(vec);
        vector<int> rightIndexes = nextSmallestRight(vec);
        int maxArea = INT_MIN;
        
        for(int i=0;i<vec.size();i++){
            
            int area= (rightIndexes[i]-leftIndexes[i]-1)*vec[i];
            if(area>maxArea) maxArea = area;
        }
    
        return maxArea;
    
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int> v;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int j=0;j<m;j++){
            v.push_back(matrix[0][j]-'0');
        }
        int mx = maximalHistogram(v);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(matrix[i][j]=='0') v[j]=0;
                else v[j] += (matrix[i][j]-'0');
            }
            mx = max(mx, maximalHistogram(v));
        }
        return mx;
    }
};