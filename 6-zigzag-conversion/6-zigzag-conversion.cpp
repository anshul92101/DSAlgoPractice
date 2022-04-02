class Solution {
public:
    
    void printVector(vector<vector<char>> &matrix){
        
        
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        
        
        
    }
    
    string convert(string s, int numRows) {
        
        vector<vector<char>> matrix(numRows,vector<char>(s.length(),'$'));
        
        int i = 0;
        int j=0, count=0;
        if(numRows==1) return s;
        int direction = 0;
        while(count<s.length()){
            
            if(direction==0){
                matrix[i][j] = s[count];
                i++;
                count++;
                if(i==numRows){
                    i = max(0,numRows-2);
                    j++;
                   // matrix[i][j] = s[count++];
                    direction = 1;
                }
            }
            
            else if(direction==1){
                 matrix[i][j] = s[count];
                 i--;
                 count++;
                 if(i==-1){
                    i = 1;
                    //matrix[i][j] = s[count++];
                    direction = 0;
                }
                else j++;
            }
        }
        
        string solution = "";
        int n = matrix.size();
        int m = matrix[0].size();
        
       // printVector(matrix);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!='$') solution.push_back(matrix[i][j]);
            }
        }
        
        return solution;
    }
};