class Solution {
public:
    
    //direction 0 -- right
    // 1 -- down, 2 -- left, 3 -- up
    
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        
        int top = 0, right = matrix[0].size() -1, down = matrix.size()-1, left = 0;
        int direction = 0;
        vector<int> solution;
        int i=0;
        while(top<=down && left<= right){
            
            if(direction==0){
                i = left; 
                while(i<=right){
                    
                    solution.push_back(matrix[top][i]);
                    i++;
                }
                top++;
                direction = 1;
            
            }
            else if(direction==1){
                i = top; 
                while(i<=down){
                    
                    solution.push_back(matrix[i][right]);
                    i++;
                }
                right--;
                direction = 2;
            
            }
             else if(direction==2){
                i = right; 
                while(i>=left){
                    
                    solution.push_back(matrix[down][i]);
                    i--;
                }
                down--;
                direction = 3;
            
            }
            else if(direction==3){
                i = down; 
                while(i>=top){
                    
                    solution.push_back(matrix[i][left]);
                    i--;
                }
                left++;
                direction = 0;
            
            }
            
        }
        
        return solution;
        
    }
};