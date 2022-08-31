class Solution {
public:
    
    bool isSafe(vector<string> board, int row, int col){
        
        //checking the columns
        for(int i=row;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }
        //checking for left upper diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
             if(board[i][j]=='Q') return false;
        }
        for(int i=row,j=col;i>=0 && j<board.size();i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    
    void findSolutions(vector<string> board, vector<vector<string>>& solution, int row){
        
        if(row==board.size()){
            solution.push_back(board);
            return;
        }
        
        for(int col=0;col<board.size();col++){
            
            if(isSafe(board,row,col)){
                board[row][col] = 'Q';
                findSolutions(board,solution,row+1);
                board[row][col] = '.';
            }
            
        }
        
    }
                
    vector<vector<string>> solveNQueens(int n) {
        
       vector<string> board(n,string(n,'.'));
       vector<vector<string>> solution;
       findSolutions(board,solution,0);
       return solution ;

    }
};