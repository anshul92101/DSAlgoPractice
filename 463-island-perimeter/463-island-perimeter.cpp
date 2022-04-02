class Solution {
public:
    bool visited[101][101];
    pair<int,int> getStartingIndex(vector<vector<int>>& grid){
        
        int sr, sc;
        int N= grid.size();
        int M = grid[0].size();
        int flag =0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                    flag=1; 
                    break;
                }
            }
            if(flag==1) break;
        }    
        
        pair<int,int> p = {sr,sc};
        return p;
        
    }
    
    void getPerimeter(vector<vector<int>>& grid, int sr,int sc, int &ans){
        
        
        int N= grid.size();
        int M = grid[0].size();
        if(sr<0||sr>=N||sc<0||sc>=M||grid[sr][sc]!=1||visited[sr][sc]) return;
        
        visited[sr][sc] = true;
        if(sr>=1){
            if(grid[sr-1][sc]==0) ans+=1;
        }
        else ans+=1;
        if(sr<N-1){
            if(grid[sr+1][sc]==0) ans+=1;
        }
        else ans+=1;
        if(sc>=1){
            if(grid[sr][sc-1]==0) ans+=1;
        }
        else ans+=1;
        if(sc<M-1){
            if(grid[sr][sc+1]==0) ans+=1;
        }
        else ans+=1;
        
        getPerimeter(grid,sr-1,sc,ans);
        getPerimeter(grid,sr+1,sc,ans);
        getPerimeter(grid,sr,sc-1,ans);
        getPerimeter(grid,sr,sc+1,ans);
        
        
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int sr, sc;
        int N= grid.size();
        int M = grid[0].size();
        memset(visited,false,sizeof visited);
        pair<int,int> p = getStartingIndex(grid);
         sr = p.first;
         sc= p.second;
        int ans=0;
        getPerimeter(grid,sr,sc,ans);
        
        return ans;
    }
};