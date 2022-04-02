class Solution {
public:
    
    void markIsland(vector<vector<char>>& grid, int sr, int sc){
        
        int N = grid.size();
        int M = grid[0].size();
        if(sr<0||sr>=N||sc<0||sc>=M||grid[sr][sc]!='1') return;
        
        grid[sr][sc]='2';
        
        markIsland(grid,sr-1,sc);
        markIsland(grid,sr+1,sc);
        markIsland(grid,sr,sc-1);
        markIsland(grid,sr,sc+1);
        
    }

    
    int numIslands(vector<vector<char>>& grid) {
        
        int N = grid.size();
        int M = grid[0].size();
        int numOfIslands = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                
                if(grid[i][j]=='1'){
                    markIsland(grid,i,j);
                    numOfIslands++;
                }
                
                
            }
        }
        return numOfIslands;
    
    
    
    }
};