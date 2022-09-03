class Solution {
public:
    
    int findSteps(int num){
        
        if(num==0) return 0;
        if(num%2==0) return 1 + findSteps(num/2);
        else return 1 + findSteps(num-1);
        
        
    }
    
    int numberOfSteps(int num) {
        int solution = findSteps(num);
        return solution;
    
    }
};