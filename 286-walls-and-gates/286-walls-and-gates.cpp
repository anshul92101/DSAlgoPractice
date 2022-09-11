class Solution {
public:
    
    void addNeighbour(queue<pair<int,int>>& q, int row, int col,vector<vector<bool>>& vis,vector<vector<int>>& rooms,int dist){
        
       int m = rooms.size();
       int n = rooms[0].size();
       if(row<0 || row>=m || col<0 || col>=n || rooms[row][col]==-1 || vis[row][col]) return;
            
       q.push({row,col});
       vis[row][col] = true;
       rooms[row][col] = dist;
        
        
    }
    
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        queue<pair<int,int>> q;
        int m = rooms.size();
        int n = rooms[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int dist = 0 ;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }
        
        while(!q.empty()){
            for(int i=0;i<q.size();i++){
                int row, col;
                row = q.front().first;
                col = q.front().second;
                dist = rooms[row][col]+1;
                // cout<<"row "<<row<<" col "<<col<<" value "<<rooms[row][col]<<" i "<<i<<endl;
                q.pop();
                addNeighbour(q,row+1,col,vis,rooms,dist);
                addNeighbour(q,row-1,col,vis,rooms,dist);
                addNeighbour(q,row,col+1,vis,rooms,dist);
                addNeighbour(q,row,col-1,vis,rooms,dist);
            }
          
        }
        
        
        
    }
};